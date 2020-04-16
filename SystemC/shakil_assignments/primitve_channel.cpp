
/*****************************************************
 Primitive channel implementation in systemC
 author : Md Shakil Ansari    date : 14/04/2020

******************************************************/
#include <systemc.h>
class slave_write_if : public sc_interface
{
    public :
    virtual void write (unsigned int add , unsigned data ) = 0 ;
} ;
class slave_read_if : public sc_interface
{
    public :
    virtual int read (unsigned int add ) = 0 ;
};
SC_MODULE(Master)
{
  sc_port<slave_write_if> master_port ;
  sc_in <bool> clk ;
  int i = 0 ;
  void process()
  {
    while (true)
    {
      wait();
       //for(int i = 0 ; i < 10 ; ++i)
      master_port-> write( i ,i*5) ;
      i++ ;
    }
  }
  SC_CTOR(Master)
  {
    SC_THREAD(process) ;
    sensitive<<clk.pos() ;
  }
};
SC_MODULE (slave)
{
 sc_port <slave_read_if> slave_port ;
  int i = 0 ;
 
  void process()
  {
    while(true)
    {
    wait() ;
    int read_val ;
   // for(int i = 0 ; i < 10 ; ++i)
    read_val = slave_port->read(i) ;
    if(read_val != i*5 )
    {
        cout<<"ERROR ! data mismatched "<<endl ;
    }
    i++ ;
    }
  }
   SC_CTOR(slave)
   {
     SC_THREAD(process) ;
     sensitive<< slave_port ;
   }
};
class master_slave_channel : public sc_prim_channel , public slave_read_if, public slave_write_if
{
  public:
  sc_event e ;
  int* channel_arr = new int [10] ;
  void write (unsigned int add , unsigned data )
  {
    assert( add < 10 );
    channel_arr[add] =  data ;
    assert(add <10) ;
    cout<<"@ "<<sc_time_stamp() <<" writing at address - "<<add<<"  the data - "<<data<<endl;
    request_update() ;
  }
  int read (unsigned int add)
  {
    assert(add <10) ;
    cout<<"@ "<<sc_time_stamp() <<" reading at address  - "<<add<<"  the data - "<<channel_arr[add]<<endl;
    return channel_arr[add] ;
  }
  void update() 
  {
    e.notify(SC_ZERO_TIME);
  }
  const sc_event& default_event() const { return e; }
  
  
};
int sc_main(int argc , char* argv[])
{
  Master m("m") ;
  slave s("s") ;
  master_slave_channel ch ;
  sc_clock clk("clk",2 ,SC_NS) ;
  m.clk(clk) ;
  m.master_port(ch) ; 
  s.slave_port(ch)  ;
  sc_start(20,SC_NS)  ;
  return 0 ;
}  
