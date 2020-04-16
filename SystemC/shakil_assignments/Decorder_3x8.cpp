/***************************************************
 SystemC code for designing of a 3x8 decorder
 Author :- Md Shakil Ansari    date :- 06/04/2020

****************************************************/
#include<systemc.h>
using namespace std ;
SC_MODULE(Decorder)
{
  sc_in<bool> x,y,z ;
  sc_out<bool> d0,d1,d2,d3,d4,d5,d6,d7 ;
  void logic()
  {
    d0 = (!x & !y & !z) ;
    d1 = (!x & !y & z) ;
    d2 = (!x & y & !z) ;
    d3 = (!x & y & z) ;
    d4 = (x & !y & !z) ;
    d5 = (x & !y & z) ;
    d6 = (x & y & !z) ;
    d7 = (x & y & z) ;
  }
  SC_CTOR(Decorder)
  {
    SC_METHOD(logic) ;
    sensitive<<x<<y<<z ;
  }
};
SC_MODULE(testbench)
{
  sc_out<bool> x, y , z ;
  sc_in<bool> d0,d1,d2,d3,d4,d5,d6,d7 ;
  
  void combinations()
  { 
    cout<<"Decorder Truth Table : "<<endl ;
    cout<<"   INPUTS\t\t\t\t      OUTPUT"<<endl ;
    x = 0 ; y = 0 ,z = 0 ;
    wait(5 ,SC_NS) ;
   cout<<" x = "<< x <<" y = "<<y <<" z = "<<y << "    d7 = " <<d7 << " d6 = " <<d6 << " d5 = " <<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 <<endl;
    
    x = 0 ; y = 0 ,z = 1 ;
    wait(5 ,SC_NS) ;
    cout<<" x = "<< x <<" y = "<<y <<" z = "<<y << "    d7 = " <<d7 << " d6 = " <<d6 << " d5 = " <<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 <<endl;
    x = 0 ; y = 1 ,z = 0 ;
    wait(5 ,SC_NS) ;
    cout<<" x = "<< x <<" y = "<<y <<" z = "<<y << "    d7 = " <<d7 << " d6 = " <<d6 << " d5 = " <<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 <<endl;
    x = 0 ; y = 1 ,z = 1 ;
    wait(5 ,SC_NS) ;
    cout<<" x = "<< x <<" y = "<<y <<" z = "<<y << "    d7 = " <<d7 << " d6 = " <<d6 << " d5 = " <<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 <<endl;
    x = 1 ; y = 0 ,z = 0 ;
    wait(5 ,SC_NS) ;
    cout<<" x = "<< x <<" y = "<<y <<" z = "<<y << "    d7 = " <<d7 << " d6 = " <<d6 << " d5 = " <<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 <<endl;
    x = 1 ; y = 0 ,z = 1 ;
    wait(5 ,SC_NS) ;
    cout<<" x = "<< x <<" y = "<<y <<" z = "<<y << "    d7 = " <<d7 << " d6 = " <<d6 << " d5 = " <<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 <<endl;
    x = 1 ; y = 1 ,z = 0 ;
    wait(5 ,SC_NS) ;
    cout<<" x = "<< x <<" y = "<<y <<" z = "<<y << "    d7 = " <<d7 << " d6 = " <<d6 << " d5 = " <<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 <<endl;
    x = 1 ; y = 1 ,z = 1 ;
    wait(5 ,SC_NS) ;
    cout<<" x = "<< x <<" y = "<<y <<" z = "<<y << "    d7 = " <<d7 << " d6 = " <<d6 << " d5 = " <<d5 << " d4 = " <<d4 << " d3 = " <<d3 << " d2 = " <<d2 << " d1 = " <<d1 << " d0 = " <<d0 <<endl;
  }
     
  SC_CTOR(testbench)
  {
    SC_THREAD(combinations) ;
  }
};

int sc_main(int argc ,char* argv[] )
{
  Decorder dec_3x8("dec_3x8") ;
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

  
  
  dec_3x8.x(x) ;
  dec_3x8.y(y) ;
  dec_3x8.z(z) ;
  dec_3x8.d0(d0) ;
  dec_3x8.d1(d1) ;
  dec_3x8.d2(d2) ;
  dec_3x8.d3(d3) ;
  dec_3x8.d4(d4) ;
  dec_3x8.d5(d5) ;
  dec_3x8.d6(d6) ;
  dec_3x8.d7(d7) ;

  sc_start() ;
  return 0 ;

}
  
