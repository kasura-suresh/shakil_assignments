/********************************************************
         ~ APB_Implementation in systemC ~ 
          
Author - Md Shakil Ansari 
date   - 19/04/20
*********************************************************/

#include<list>
#include<utility>
#include<systemc.h>
#include<iostream>
using namespace std ;
struct slave_if : public sc_interface
{
  virtual void write (unsigned int add ,unsigned int data ) = 0 ;
  virtual void read (unsigned int add ) = 0 ;
};
enum APB_States { idle , setup ,accesss } ;
SC_MODULE(master_bridge) , public slave_if
{
  sc_in<bool>  clk;
  sc_out<bool> pselx; 
  sc_out<int>  paddr; //address bus
  sc_out<int>  pwdata; //data bus
  sc_out<bool> penable;
  sc_out<bool> pwrite;
  sc_in<bool>  pready;
  sc_in<int>   prdata;
  list< pair<int,int> >   writeList ;
  list <int>  readList ;
  sc_export<slave_if> master_export ;
  APB_States curr_state = idle ; // idle state is assigned
  pair <int,int> temp;

  void write(unsigned int add , unsigned int data )
  {
    assert(add < 10 ) ;
    writeList.push_back(make_pair(add,data)) ; 
  }
  void read (unsigned add) 
  {
    assert(add <10);
    readList.push_back(add) ;   //adding into the readlist   
  }
  void fsm()
  {    
    if(curr_state == idle )
    {
      cout<<"@ "<<sc_time_stamp()<<" IDLE STATE"<<endl;
      pselx = 0 ;
      paddr  = 0 ;
      penable.write(0);
      pwdata = 0;
      curr_state = setup;   // setup state is assigned
    }
    else if( curr_state == setup)
    {
      cout<<"@ "<<sc_time_stamp()<<" SETUP STATE"<<endl;
      pselx = 1;
      penable.write(0);
      temp = writeList.front() ;
      if(pwrite == 1)
      paddr = temp.first;
      else 
      {
        paddr  = readList.front();
      }        
      curr_state = accesss; //access state
    }
    //in access state
    else
    {
      cout<<"@ "<<sc_time_stamp()<<" ACCESS STATE"<<endl;
      penable.write(1) ;
 
      if(pready == 0)
      {
        cout <<"@ "<<sc_time_stamp()<<" Slave is not ready"<<endl;      
      }
      else 
      {
        if(pwrite ==1)
        {
          cout<<"Write Operation is ON....."<<endl; 

          if (writeList.size() > 0 )
          {
            pwdata =  temp.second;
            cout<<"From master ,Data to write is  = "<<temp.second<<endl;
            writeList.pop_front(); //resize the list
            curr_state = setup ; // goes back to setup state
          }
          else
          {
            cout<<"list is empty"<<endl;
            pselx = 0;
            penable.write(0);
            curr_state = idle; // goes back to idle state
          }
        }
        else
        {
          cout<<"Read Operation is ON....."<<endl;
          if (readList.size() > 0 )
          {
            cout<<"From Slave to master data read is = "<<prdata<<endl;
            readList.pop_front();
            curr_state = setup ; // goes back to setup state
          }
          else
          {
            cout<<"Readlist is empty"<<endl;
            pselx = 0;
            penable.write(0);
            curr_state = idle; // goes back to idle state
            sc_stop();
          }
        }
      }
    }
  }
  void setWrite()
  {
    pwrite = 1 ;
    wait(46,SC_NS) ; // upto 46ns write operation is occurring
    pwrite = 0 ;
  }
  SC_CTOR(master_bridge)
  {
    SC_METHOD(fsm);
    sensitive<<clk.pos();
    dont_initialize();
    SC_THREAD(setWrite) ;
    sensitive <<clk.pos() ;
    master_export.bind(*this);
  }
};

SC_MODULE(host)
{
  sc_in<bool> clk ;
  sc_port<slave_if> host_port ; 
  void behaviour ()
  {
    for (int i = 0 ; i < 10 ; i++)
    {
      host_port->write( i , i*3) ;
    }
    for (int i = 0 ; i < 10 ; i++ )
    {
      host_port->read(i) ;
    }
  }
  SC_CTOR(host)
  {
    SC_THREAD(behaviour) ;
  }

};

SC_MODULE(slave1)   
{
  sc_in<bool> clk;
  sc_in<bool> pselx;
  sc_in<int>  paddr;      //address bus
  sc_in<int>  pwdata;     //data bus
  sc_out<int> prdata; 
  sc_in<bool> penable;
  sc_in<bool> pwrite;
  sc_out<bool> pready;
  int* slave_storage = new int[10] ; // data will be wriitten to this array

  void behaviour( )
  {
      while(true)
      {
      pready = 1;
      wait(1);
      wait(SC_ZERO_TIME);
      if(pselx == 0)
      cout<<"@ "<<sc_time_stamp()<<" Slave Is NOT Selected Yet"<<endl;
      else
      {
        cout<<"SLAVE SELECTED\n@ "<<endl ;
        if(pselx == 1 && penable == 1 && pwrite == 1)
        {
          slave_storage[paddr] = pwdata ;
          cout<<"@ "<<sc_time_stamp()<<" data recieved by slave is = "<< slave_storage[paddr] <<endl;
        }
        else if(pselx == 1 && penable == 1 && pwrite == 0)
        { 
          wait(SC_ZERO_TIME);
          cout<<"PADDR = :"<< paddr<<endl;
          prdata = slave_storage[paddr] ;
          cout<<"@ "<<sc_time_stamp()<<" transfering data from slave to master " <<slave_storage[paddr]<<endl ;
        }
        else
        {
          cout<<"Oops ! Master/Slave is NOT Enabled :"<<endl;
        }
      }
    }
  }
  void buzy()
  {
    pready = 0;
  }

  void ready()
  {
    pready = 1;
  }
  SC_CTOR(slave1)
  {
    SC_THREAD(behaviour);
    sensitive<<clk.pos()<<pwrite ;
    dont_initialize();
    //SC_METHOD(ready);
  }
};

int sc_main(int argc ,char* argv[])
{
  master_bridge master("master");
  slave1        slave("slave") ;
  sc_clock clk("clk" ,2 ,SC_NS) ;
  host host1("host");
  host1.host_port(master.master_export) ;
  sc_signal<bool>  pselx ,pwrite ,pready ,penable ;
  sc_signal<int> pwdata ,paddr ,prdata ;
  pready.write(1);
  
  sc_trace_file* tf = sc_create_vcd_trace_file("APB") ;
  sc_trace(tf,clk,"clock") ;
  sc_trace(tf,pselx,"pselx") ;
  sc_trace(tf,pwrite,"pwrite") ;
  sc_trace(tf,penable,"penable") ;
  sc_trace(tf,pready,"pready") ;
  sc_trace(tf,paddr,"paddr") ;
  sc_trace(tf,pwdata,"pwdata") ;
  sc_trace(tf,prdata,"prdata") ;
  
  master.pselx(pselx)     ;
  master.pwrite(pwrite)   ;
  master.pready(pready)   ;
  master.penable(penable) ;
  master.pwdata(pwdata)   ;
  master.paddr(paddr)     ;
  master.prdata(prdata)   ;

  slave.pselx(pselx)      ;
  slave.pwrite(pwrite)    ;
  slave.pready(pready)    ;
  slave.penable(penable)  ;
  slave.pwdata(pwdata)    ;
  slave.paddr(paddr)      ;
  slave.prdata(prdata)    ;
  master.clk(clk) ;
  slave.clk(clk) ;
  host1.clk(clk);
  sc_start(200,SC_NS) ;
  return 0 ;
}




