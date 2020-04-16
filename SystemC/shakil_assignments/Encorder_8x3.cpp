/***************************************************
 SystemC code for designing of a 8x3 encorder
 Author :- Md Shakil Ansari    date :- 06/04/2020

****************************************************/

#include<systemc.h>
using namespace std ;
SC_MODULE(Encoder)
{
  sc_in<bool> d0,d1,d2,d3,d4,d5,d6,d7 ;
  sc_out<bool> x ,y , z ;
  void logic()
  {
    x = ( d4 | d5 | d6 | d7 ) ;
    y = ( d2 | d3 | d6 | d7 ) ;
    z = ( d1 | d3 | d5 | d7 ) ;
  }
  SC_CTOR(Encoder)
  {
    SC_METHOD(logic) ;
    sensitive<<d0<<d1<<d2<<d3<<d4<<d5<<d6<<d7 ;
  }
};
SC_MODULE(testbench)
{
  sc_out<bool> d0,d1,d2,d3,d4,d5,d6,d7 ;
  sc_in<bool> x ,y ,z ;
  
  void combinations()
  { 
    cout<<"Encoder Truth Table : "<<endl ;
    cout<<"        \t\tINPUTS\t\t\t\t\t    OUTPUT"<<endl ;
   d7 = 0 ; d6 = 0 ; d5 = 0 ; d4 = 0 ; d3 = 0 ; d2 = 0 ; d1 = 0 ; d0 = 1 ;
    wait(5 ,SC_NS) ;
   cout<<" d7 = "<<d7<<" d6 = "<<d6 <<" d5 = "<<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 << "   x = " <<x << " y = " <<y << " z = " <<z <<endl;
    
   d7 = 0 ; d6 = 0 ; d5 = 0 ; d4 = 0 ; d3 = 0 ; d2 = 0 ; d1 = 1 ; d0 = 0 ;
    wait(5 ,SC_NS) ;
   cout<<" d7 = "<<d7<<" d6 = "<<d6 <<" d5 = "<<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 << "   x = " <<x << " y = " <<y << " z = " <<z <<endl;
    d7 = 0 ; d6 = 0 ; d5 = 0 ; d4 = 0 ; d3 = 0 ; d2 = 1 ; d1 = 0 ; d0 = 0 ;
    wait(5 ,SC_NS) ;
   cout<<" d7 = "<<d7<<" d6 = "<<d6 <<" d5 = "<<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 << "   x = " <<x << " y = " <<y << " z = " <<z <<endl;
    d7 = 0 ; d6 = 0 ; d5 = 0 ; d4 = 0 ; d3 = 1 ; d2 = 0 ; d1 = 0 ; d0 = 0 ;
    wait(5 ,SC_NS) ;
   cout<<" d7 = "<<d7<<" d6 = "<<d6 <<" d5 = "<<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 << "   x = " <<x << " y = " <<y << " z = " <<z <<endl;
    d7 = 0 ; d6 = 0 ; d5 = 0 ; d4 = 1 ; d3 = 0 ; d2 = 0 ; d1 = 0 ; d0 = 0 ;
    wait(5 ,SC_NS) ;
   cout<<" d7 = "<<d7<<" d6 = "<<d6 <<" d5 = "<<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 << "   x = " <<x << " y = " <<y << " z = " <<z <<endl;
    d7 = 0 ; d6 = 0 ; d5 = 1 ; d4 = 0 ; d3 = 0 ; d2 = 0 ; d1 = 0 ; d0 = 0 ;
    wait(5 ,SC_NS) ;
   cout<<" d7 = "<<d7<<" d6 = "<<d6 <<" d5 = "<<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 << "   x = " <<x << " y = " <<y << " z = " <<z <<endl;
    d7 = 0 ; d6 = 1 ; d5 = 0 ; d4 = 0 ; d3 = 0 ; d2 = 0 ; d1 = 0 ; d0 = 0 ;
    wait(5 ,SC_NS) ;
   cout<<" d7 = "<<d7<<" d6 = "<<d6 <<" d5 = "<<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 << "   x = " <<x << " y = " <<y << " z = " <<z <<endl;
    d7 = 1 ; d6 = 0 ; d5 = 0 ; d4 = 0 ; d3 = 0 ; d2 = 0 ; d1 = 0 ; d0 = 0 ;
    wait(5 ,SC_NS) ;
   cout<<" d7 = "<<d7<<" d6 = "<<d6 <<" d5 = "<<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 << "   x = " <<x << " y = " <<y << " z = " <<z <<endl;
}
     
  SC_CTOR(testbench)
  {
    SC_THREAD(combinations) ;
  }
};

int sc_main(int argc ,char* argv[] )
{
  Encoder Enc_8x3("Enc_8x3") ;
  testbench tb1("tb1") ;
  sc_signal<bool> x ,y ,z, d0,d1,d2,d3,d4,d5,d6,d7 ;
  
  tb1.x(x) ;
  tb1.y(y) ;
  tb1.z(z) ;
  tb1.d0(d0) ;
  tb1.d1(d1) ;
  tb1.d2(d2) ;
  tb1.d3(d3) ;
  tb1.d4(d4) ;
  tb1.d5(d5) ;
  tb1.d6(d6) ;
  tb1.d7(d7) ;

  
  
  Enc_8x3.x(x) ;
  Enc_8x3.y(y) ;
  Enc_8x3.z(z) ;
  Enc_8x3.d0(d0) ;
  Enc_8x3.d1(d1) ;
  Enc_8x3.d2(d2) ;
  Enc_8x3.d3(d3) ;
  Enc_8x3.d4(d4) ;
  Enc_8x3.d5(d5) ;
  Enc_8x3.d6(d6) ;
  Enc_8x3.d7(d7) ;

  sc_start() ;
  return 0 ;

}
  
