#include <iostream>
using namespace std ; 
// A normal function with an int parameter 
void add(int a ,int b) 
{ 
	cout<<"the result of addition is :"<<a+b<<endl ;
} 

int main() 
{ 
	// fun_ptr is a pointer to function add() 
	void (*fun_ptr)(int,int) = &add; 

	/* The above line is equivalent of following two 
	void (*fun_ptr)(int); 
	fun_ptr = &add; 
	*/
    (*fun_ptr)(10,20); // Invoking add() using fun_ptr
     return 0; 
} 

