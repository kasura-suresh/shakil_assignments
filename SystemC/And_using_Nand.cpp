/**************************************************** 
  systenC :- Or Gate realisation using NAND Gate
  Author -Md Shakil Ansari  date - 05-04-2020
*****************************************************/
#include<systemc.h>
SC_MODULE(NAND)
{
  sc_in<bool> a,b ;
  sc_out<bool> y ;
  void Nand_logic()
  {
    y = !(a&b) ;
  }
  SC_CTOR(NAND): a("a"),b("b"),y("y")
  {
    SC_METHOD(Nand_logic)
    sensitive<< a << b ;
  }
} ;

SC_MODULE(And_using_Nand)
{
  sc_in<bool> a ,b ;
  sc_out<bool> y ;
  sc_signal<bool> y1 ;
  NAND N1 ,N2 ; //2 nand gate is required for getting and logic
  
  SC_CTOR(And_using_Nand) : a("a"),b("b"),y("y"),N1("N1"),N2("N2")
  {
    N1.a(a) ;N1.b(b) ;N1.y(y1) ;
    N2.a(y1) ;N2.b(y1) ;N2.y(y) ;
  }
} ;

SC_MODULE(testbench)
{
  And_using_Nand a1 ;
  sc_signal<bool> a, b, y;
  
  void test_cases() {
    cout<<"AND Gate Truth Table : "<<endl ;
    a = 0; b = 0;
    wait(1, SC_NS);
    cout << "a = " << a << ", b = " << b << ", y = "<< y << endl;

    a = 0; b = 1;
    wait(1, SC_NS);
    cout <<"a = " << a << ", b = " << b << ", y = "<< y << endl;

    a = 1; b = 0;
    wait(1, SC_NS);
    cout <<"a = " << a << ", b = " << b << ", y = "<< y << endl;
    
    a = 1; b = 1;
    wait(1, SC_NS);
    cout <<"a = " << a << ", b = " << b << ", y = "<< y << endl;
  

  }
  
  SC_CTOR(testbench) : a1("a1") 
  {

  	a1(a,b,y);   //positional binding occurs here
    SC_THREAD(test_cases);
  }

} ;
int sc_main(int argc, char* argv[])
{
  sc_trace_file* tf;
  tf = sc_create_vcd_trace_file("nor_and.vcd");
  
  // elaboration phase of systemc
  testbench tb1("tb1");
  sc_trace(tf, tb1.a, "tb1.a");
  sc_trace(tf, tb1.b, "tb1.b");
  sc_trace(tf, tb1.y, "tb1.y");

  // simulation phase of systemc
  sc_start();   // 1. initialization, 2. simulation

  sc_close_vcd_trace_file(tf);
  return 0;
}
    
    
    