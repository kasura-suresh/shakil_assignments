/*************************************************************
    C++ programe to implement SHALLOW COPY
    note : all value type members of one object are succesfully 
           copied to another object  
    author : MD SHAKIL ANSARI ,date : 10 mar , 2020
 *************************************************************/


#include<iostream>
using namespace std ;
class A
{
	int a ,b ;
	public :
		void setData(int x, int y)
		{
			a = x ;
			b = y ;
		}
		void showData()
		{
			cout<<a<<" "<<b<< endl ;
		}
	
};
int main()
{
A obj1 ;
obj1.setData(5,6) ;
A obj2 = obj1 ; // implementing shallow copy 
cout<<" the data of the destination (second) object are" <<endl ; 
obj2.showData() ; // obj1 data is copied here to obj2
return 0 ;
}
