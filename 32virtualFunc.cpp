/*************************************************************
    C++ programe to implement virtual function
    author : MD SHAKIL ANSARI
 *************************************************************/
   
#include<iostream>
using namespace std;
class base    
{    
 public:    
 virtual void display()  //virtual class definition  
 {    
  cout << "Base class is invoked"<<endl;    
 }    
};    
class derived:public base    
{    
 public:    
 void display()    
 {    
  cout<<"you are in derived class"<<endl;    
 }    
};    
int main()    
{    
 A* a;    //pointer of base class    
 B b;     //object of derived class    
 a = &b;    
 a->display();  //Late Binding or dynamic linkage  
 return 0;     
}    
