/******************************************
 program to implement template functions 
 one function works for different data type promotes code reusability
 author : Md Shakil Ansari ,, date :4 mar,2020
 ******************************************/

#include<iostream>
using namespace std;
template <typename T>
void myCalcu(T x,T y) // template function for various types of operation
{
	cout<<"addition of two numbers is "<<x+y<<endl;
	cout<<"subtraction of two numbers is "<<x-y<<endl;
	cout<<"multiplication of two numbers is "<<x*y<<endl;
	cout<<"division of two numbers is "<<x/y<<endl;
}
int main()
{
  int a,b;
  float m,n;
  cout<<"enter two interger numbers for integer calculation : "<<endl;
  cin>>a>>b;
  myCalcu<int>(a,b);
  cout<<"enter two real numbers for float calculation : "<<endl;
  cin>>m>>n;
  myCalcu<float>(m,n);
  return 0;	
}
