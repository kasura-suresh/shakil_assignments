/* c++ program to implement virtual function  
   and its application */
   
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
 base* a;    //pointer of base class    
 derived b;     //object of derived class    
 a = &b;    
 a->display();  //Late Binding or dynamic linkage  
 return 0;     
}    
