/****************************************
 c++ programe to implement TYPECASTNG 
   it shows both implicit and explicit typecasting
 author :Md Shakil Ansari ;date- 6 mar,2020 
 ****************************************/

#include<iostream>
using namespace std ;
class A
{

};
class B {
	public :
		B(A a){ // constructor taking obj of class A as parameter
			
		}
};
int main()
{
A a ;
B b =a ; // implicit conversion between objects of classes A and B 
short int i=20;
int y=0;
y=i; // implicit conversion  ;
cout<< "B is :"<<y<<endl; 
float f = 3.5 ;
int x=0;
x = int(f)*2 ; // typecasting float into int
cout<<"X is : "<<x<<endl;
return 0 ;
}
