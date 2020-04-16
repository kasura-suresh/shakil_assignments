/*****************************************************
 Hierarchical channel implementation in systemC
 author : Md Shakil Ansari    date : 14/04/2020

******************************************************/
 #include <systemc.h>
class slave_if : public sc_interface
{
  public :
  virtual void write (unsigned int add ,unsigned int data ) = 0 ;
  virtual int read (unsigned int add ) = 0 ;
 // slave_if(){}
};

class peripheral_if : public sc_interface
{
  public :
  virtual void write (unsigned int add ,unsigned int data ) = 0 ;
  virtual int read (unsigned int add ) = 0 ;
 
};
SC_MODULE(Master)
{
    sc_in<bool> clk ;
    sc_port<slave_if> p ;
   // int i = 0 ;
    void behaviour()
    {
      wait() ;
      int read_val ;
      for (int i = 0 ;i < 10 ; ++i)
      {
        p->write(i , i*5 ) ;
        read_val = p->read(i) ;
        if(read_val != i*5 )
        {
          cout<<"ERROR ! , data mismatched "<<endl ;
        }
    
      }
    }
    
  SC_CTOR(Master)
  {
    SC_THREAD(behaviour) ;
    sensitive<<clk.pos() ;
  }
};
SC_MODULE(slave) , public slave_if
{
  sc_export <slave_if> p_slave ;
  sc_port<peripheral_if> p_peripheral ;
  int* slave_arr = new int[10] ;
  virtual void write (unsigned int add ,unsigned int data )
  {
    assert(add <10) ;
    cout<<"@ "<<sc_time_stamp() <<"writing at address "<<add<<" the data "<<data<<endl;
    slave_arr[add] = data ;
  }
  virtual int read (unsigned int add )
  {
    assert(add <10) ;
    cout<<"@ "<<sc_time_stamp() <<"readiing at address "<<add<<" the data "<<slave_arr[add]<<endl;
    return slave_arr[add] ;
  }
  SC_CTOR(slave)
  {
    p_slave.bind(*this) ;
  //  SC_METHOD(write) ;
  //  SC_METHOD(read) ;
  }
} ;
SC_MODULE(peripheral) ,public peripheral_if
{
  sc_export<peripheral_if> p_peripheral ;
  int* p_arr = new int[10] ;
  void write (unsigned int add ,unsigned int data)
  {
    assert(add < 10) ;
    cout<<"@ "<<sc_time_stamp() <<"writing at address "<<add<<" the data "<<data<<endl;
    p_arr[add] = data ;
  }
  int read (unsigned int add)
  {
    assert(add <10) ;
    cout<<"@ "<<sc_time_stamp() <<"readiing at address "<<add<<" the data "<<p_arr[add]<<endl;
    return p_arr[add] ;
  }
  SC_CTOR(peripheral)
  {
    p_peripheral.bind(*this);
  }
} ;
int sc_main(int argc ,char* argv[])
{
  Master m("m") ;
  slave s("s") ;
  peripheral p("p") ;
  sc_clock clk("clk" ,2,SC_NS) ;
  m.clk(clk) ;
  m.p(s.p_slave ) ; // port of master is bound to export of slave
  s.p_peripheral(p. p_peripheral) ;//port of slave is bound to export of peripheral
          
  sc_start(20 ,SC_NS) ;
};
          
  
    
    
    
  
  
  
  
  
  
  
  
  
  
