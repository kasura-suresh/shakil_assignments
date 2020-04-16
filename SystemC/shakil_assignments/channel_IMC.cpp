/*****************************************************
  interface method call by  channel implementation in systemC
 author : Md Shakil Ansari    date : 14/04/2020

******************************************************/
#include<systemc.h>
class slave_if : public sc_interface{
  public :
  virtual void write (unsigned int add ,unsigned int data ) = 0 ;
  virtual int read (unsigned int add ) = 0 ;
 // slave_if(){}
};
SC_MODULE(Master)
{
    sc_in<bool> clk ;
    sc_port<slave_if> p // p becomes the smart pointer of slave_if ;
  int i = 0 ;
    
    void behaviour()
    {
      while(true){
      wait() ;  
      int read_val ;
     // for (unsigned int i = 0 ;i<10 ; ++i){
  
        p->write(i , i*5 ) ;
        read_val = p->read(i) ;
        if(read_val != i*5 )
        {
        cout<<"ERROR ! ,data mismatched "<<endl ;
        }
        i++ ;
    // wait() ;
    }
    }
  SC_CTOR(Master)
  {
    SC_THREAD(behaviour) ;
    sensitive<<clk.pos() ;
  }
};

SC_MODULE(slave) ,public slave_if
{
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
   // SC_METHOD(write) ;
   // SC_METHOD(read) ;
  }
} ;



  
int sc_main(int argc, char* argv[])
{
  Master m("m") ;
  slave s("s") ;
  m.p(s) ;  //connecting master port to slave module 
  sc_start(100,SC_NS) ;
  return 0 ;
}
    
      
    
    
