/*************************************************************
    C++ programe to implement OBJECT SLICING
    note : the additional members of derived class object are sliced off 
           when object of derived class is assigned to base class object
    
    author : MD SHAKIL ANSARI ,date : 7 mar , 2020
 *************************************************************/


#include <iostream> 
using namespace std; 

class Base 
{ 
protected: 
	int i,j; 
public: 
	Base(int a,int b)	 
	{
	 i = a ;
	 j = b ; 
	} 
	virtual void display() 
	{ 
	cout << " Base class object, i  and j are = " << i << " "<< j << endl; 
	} 
}; 
class Derived : public Base //inherting base class
{ 
	int k; 
public: 
	Derived(int a, int b,int c) : Base(a,b) 
	{ 
	    k = c;
    } 
	virtual void display() 
	{ cout << " Derived class object, i , j and k = "
		<< i <<" "<< j <<" "<<k << endl; } 
}; 

// Global method, Base class object is passed by value 
void func (Base obj) // derived object is being assigned here as an argument
{ 
	obj.display(); 
} 

int main() 
{ 
	Base b(33,43); 
	Derived d(45, 54,65); 
	func(b); 
	func(d); // Object Slicing, the member k of d is sliced off here 
	return 0; 
} 

