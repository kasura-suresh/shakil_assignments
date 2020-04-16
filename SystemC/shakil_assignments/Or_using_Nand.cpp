/**************************************************** 
  systenC :- Or Gate realisation using NAND Gate
  Author -Md Shakil Ansari  date - 05-04-2020
*****************************************************/
#include <systemc.h>

SC_MODULE(Nand) 
{
  sc_in<bool> a, b;
  sc_out<bool> y;
  
  void Nand_logic() 
  { 
     y = !(a & b); 
  }
  SC_CTOR(Nand) : a("a"), b("b"), y("y") 
  {
    SC_METHOD(Nand_logic);
    sensitive << a << b;
  }
};

SC_MODULE(Or_using_Nand) 
{
    sc_in<bool> a , b;
    sc_out<bool> y;
  
    sc_signal<bool> y1, y2;
  
    Nand n1, n2 ,n3 ; //instances of Nand module
  
    SC_CTOR(Or_using_Nand) : n1("n1"), n2("n2"),n3("n3"), a("a"), b("b"), y("y")   {
    n1.a(a); n1.b(a); n1.y(y1);
    n2.a(b); n2.b(b); n2.y(y2);
    n3.a(y1); n3.b(y2); n3.y(y);
  }
};

SC_MODULE(testbench) {
  Or_using_Nand a1;
  sc_signal<bool> a, b, y;
  
  void combinations() 
  {
    cout<<"OR Gate Truth Table : "<<endl ;
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
     a1(a,b,y) ; //positional binding ?
     SC_THREAD(combinations) ;
   }
};

int sc_main(int argc, char* argv[])
{
  sc_trace_file* tf;
  tf = sc_create_vcd_trace_file("Nands_Or.vcd");
 
  testbench tb1("tb1");
  sc_trace(tf, tb1.a, "tb1.a");
  sc_trace(tf, tb1.b, "tb1.b");
  sc_trace(tf, tb1.y, "tb1.y");

  sc_start(); 
  sc_close_vcd_trace_file(tf);
  return 0;
}



