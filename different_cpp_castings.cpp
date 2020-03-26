/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

class Base {
    // virtual void der1_func() = 0;
    public:
    // Base() { }
    virtual ~Base() { }
};

class Derived1 : public Base {
    public:
    // Derived1() { }
    void der1_func() { 
        cout << "I am in der1_func()\n";
    }
};
class Derived2 : public Base {
    public:
    void der2_func() {
        cout << "I am in der2_func()\n";
    }
};
class Derived3 : public Base { };

void func(Base* b) {
    if (b == NULL)
        return;
    // do we know whether b points to Base or Derived1 or Derived2
    // if (b is of type Base) do Base functionality
    // if (b is of type Derived1 ) do Derived1 functionality
    if (dynamic_cast<Derived1*>(b) != NULL) {
        ((Derived1*)b)->der1_func();
        dynamic_cast<Derived1*>(b)->der1_func();
    } else if (dynamic_cast<Derived2*>(b) != NULL) {
        ((Derived2*)b)->der2_func();
        dynamic_cast<Derived2*>(b)->der2_func();
    } else  {
        cout << "B is not of any of the expected types\n";
    }
}

class A {
    virtual void f() { }
};

class B {
    
};

int main()
{
    Base* b = new Base;
    Base* b1 = new Derived1;  // base pointer pointing to derived object (created dynamically)
    Base* b2 = new Derived2;
    Base* b3 = new Derived3;
    
    func(b1);
    func(b2);
    func(b);
    func(b3);
    
    char a = 'A';
    int x = static_cast<int>(a);
    cout << x << endl;
  
    A* aptr = new B;
    cout << aptr << endl;
    B* bptr;
    bptr = reinterpret_cast<B*>(aptr);
    cout << bptr << endl;
    bptr = dynamic_cast<B*>(aptr);
    cout << bptr << endl;
    
    return 0;
}
