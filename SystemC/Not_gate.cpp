// Not_Gate implementation using SystemC 
// author - Md shakil Ansari  Date - 03-04-2020
#include<systemc.h>
using namespace std ;
SC_MODULE(Not_gate)
{
  sc_in<bool> a ;
  sc_out<bool> y ;
  
  void Logic ()
  {
    y = !a ;
  }
  SC_CTOR(Not_gate)
  {
    SC_METHOD(Logic) ;
    sensitive << a ;
  }
};

SC_MODULE(testbench)
{
  sc_out<bool> a ;
  sc_in<bool> y ;
  
  void Logic()
  {
    cout<<"Not Gate Truth Table : "<<endl ;
    a = 0 ;
    wait(5 ,SC_NS) ;
   // wait(0 ,SC_NS) ;
    cout<<" a = "<<a <<" y = "<<y <<endl;
    
   a = 1 ;
    wait(5 ,SC_NS) ;
  //  wait(5 ,SC_NS) ;
    cout<<" a = "<<a << " y = "<<y<<endl;
    
  }
  SC_CTOR(testbench)
  {
    SC_THREAD(Logic) ;
  }
};

int sc_main(int argc ,char* argv[] )
{
  Not_gate not1("not1") ;
  testbench tb1("tb1") ;
  sc_signal<bool> a,y ; // channel 
  
  tb1.a(a) ;
  tb1.y(y) ;
  
  not1.a(a) ;
  not1.y(y) ;
  
  sc_start() ;
  return 0 ;
}
  

