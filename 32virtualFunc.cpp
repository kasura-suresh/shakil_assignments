/*************************************************************
    C++ programe to implement virtual function
   note -virtual keyword will enforce compiler to do late binding
         in order to run the actual target function
    author : MD SHAKIL ANSARI
 *************************************************************/
   
#include<iostream>
using namespace std;
class base    
{    
 public:    
 virtual void display()  //virtual function definition  
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
 a = &b; //pointer of base class is pointing to other class object   
 a->display();  //Late Binding or dynamic linkage occurs 
 return 0;     
}    
