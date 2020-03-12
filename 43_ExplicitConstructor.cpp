/*************************************************************
    C++ programe to implement explicit constructor
    
    USE of EXPLICIT CONSTRUCTOR : it avoids implicit call to constructor
    
    NOTE : this is a demonstration for the use of explicit contructor ...
 to run the code ,just erase the "explicit" keyword preceding the constructor
    
    author : MD SHAKIL ANSARI
 *************************************************************/


#include<iostream>
using namespace std ;
class A{
	int val ;
	public :
	explicit A (int x)
		{
			val = x ;
		}
		int get(){
			return val;
		}
};
int main()
{
	A obj1(12) ;   //Normal call to constructor
	
	cout<<obj1.get()<<endl ;
	int v;
	v = obj1.get();
	cout<<v <<endl;
	 
	//Implicit call to constructor , should through an error
	// But won't iff constructor is not EXPLICIT
	
	A obj2 = 15 ; // int type data is being assigned to class type object ,will through an error if
	              // constructor is type EXPLICIT 
	int u = obj2.get() ;
	cout<< u<<endl ; 
	return 0;
}
