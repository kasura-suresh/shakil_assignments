// Xor_Gate implementation using SystemC 
// author - Md shakil Ansari  Date - 03-04-2020
#include<systemc.h>
using namespace std ;
SC_MODULE(Xor_gate)
{
  sc_in<bool> a ,b ;
  sc_out<bool> y ;
  
  void Logic ()
  {
    y = a^b ;
  }
  SC_CTOR(Xor_gate)
  {
    SC_METHOD(Logic) ;
    sensitive << a << b ;
  }
};

SC_MODULE(testbench)
{
  sc_out<bool> a, b ;
  sc_in<bool> y ;
  
  void Logic()
  {
    a = 0 ; b = 0 ;
    wait(0 ,SC_NS) ;
    wait(0 ,SC_NS) ;
    cout<<" a = "<< a <<" b = "<<b <<"y = "<<y<<endl;
    
    a = 0 ; b = 1 ;
    wait(0 ,SC_NS) ;
    wait(0 ,SC_NS) ;
    cout<<" a = "<< a <<" b = "<<b <<"y = "<<y<<endl;
    
    a = 1; b = 0 ;
    wait(5 ,SC_NS) ;
   // wait(0 ,SC_NS) ;
    cout<<" a = "<< a <<" b = "<<b <<"y = "<<y<<endl;
    
    a = 1 ; b = 1 ;
    wait(5 ,SC_NS) ;
   // wait(0 ,SC_NS) ;
    cout<<" a = "<< a <<" b = "<<b <<"y = "<<y<<endl;
  }
  SC_CTOR(testbench)
  {
    SC_THREAD(Logic) ;
  }
};

int sc_main(int argc ,char* argv[] )
{
  Xor_gate xor1("xor1") ;
  testbench tb1("tb1") ;
  sc_signal<bool> a,b,y ;
  
  tb1.a(a) ;
  tb1.b(b) ;
  tb1.y(y) ;
  
  xor1.a(a) ;
  xor1.b(b) ;
  xor1.y(y) ;
  
  sc_start() ;
  return 0 ;
}
  

