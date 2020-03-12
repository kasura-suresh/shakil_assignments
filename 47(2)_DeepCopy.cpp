/*************************************************************
    C++ programe to implement DEEP COPY
    note : all value type  as well as reference type
	      members(along with content of memory)  of one object
        are succesfully  copied to another object  
    author : MD SHAKIL ANSARI ,date : 10 mar , 2020
 *************************************************************/


#include<iostream>
using namespace std ;
class A
{
	int a ,b ,*ptr ;
	public :
		A()
		{
			ptr = new int ;
		}
		void setData(int x, int y,int z)
		{
			a = x ;
			b = y ;
		*ptr  = z ;
		}
		A (A &obj) // copy constructor for deep copy
		{
		   a = obj.a ;
		   b = obj.b ;
		   ptr = new int ;
		   *ptr = *(obj.ptr) ; // the content of memory block is copied now	
		}
		void showData()
		{
			cout<<a<<" "<<b<<" "<< *ptr<< endl ;
		}
	
};
int main()
{
A obj1 ;
obj1.setData(1,2,3) ;
cout<<"data in source object is"<<endl ;
obj1.showData() ;
cout<<"after applying deep copy , data in destination object is"<<endl ;
A obj2(obj1) ; // appying deep copy throgh copy constructor
obj2.showData() ;
return 0 ;
}
