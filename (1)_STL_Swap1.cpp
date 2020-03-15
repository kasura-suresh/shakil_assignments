/***************************************************
 C++ program for illustration of swap() function in STL
  Author - Md Shakil Ansari ,date - 13-mar-2020 
 ***************************************************/

#include<iostream>
#include<algorithm>
using namespace std ;
int main()
{
	int a = 5 ;
	int b = 15 ;
	cout<<"\nBEFORE SWAP\n" ;
	cout<<"a = "<<a<<"\tb = "<<b<<endl ;
	swap(a,b) ;
	cout<<"\nAFTER SWAP"<<endl ;
	cout<<"a = "<<a<<"\tb = "<<b<<endl ;
	return 0 ;
}
