/*************************************************************
    C++ programe to implement virtual destructor
    USE : helps in destructing the derived class object 
    when it is being pointed by parent class pointer
    author : MD SHAKIL ANSARI ,date : 7 mar , 2020
 *************************************************************/


#include<iostream>
using namespace std ;
class parent
{
	public :
		parent()
		{
			cout<<" constructing parent object \n";
		}
		virtual ~parent() // virtual destructor to delete a derived class object
		{
			cout<<"destructing parent object"<<endl ;
		}
		void f1()
		{
			cout<<"f1 invoked"<<endl;
		}
};
class child : public parent
{
	public :
		child()
		{
			cout<<" constructing derived object \n";
		}
		~ child () // won't be called if virtual keyword is not used
		{
			cout<<" destructing derived object \n";
		}
		void f2()
		{
			cout<<"f2 invoked"<<endl;
		}
};
int main()
{
	child *c = new child() ; // dynamic memory allocation
	parent *p = c ; // pointer of parent type points to child object 
	p->f1() ;
//	p->f2() ;
	delete p ;
}
