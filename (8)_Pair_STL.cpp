/******************************************************************
   C++ program to illustrate the 
   pairs in STL 
   Author : Md Shakil Ansari date -17-mar-2020 
 ******************************************************************/ 

#include<iostream>
#include<utility>
using namespace std ;
int main()
{
	pair <int ,string > p1 ; // decalring pairs
	pair <string ,float > p2 ;
	pair <int ,int > p3 ;
	pair <int ,int > p4 (23,22);
	
	
	
	p1 = make_pair(1,"Shakil") ;
	p2 = make_pair("madhyamik", 82.28) ;
	p3 = make_pair(13,15) ;
/*	if(p1 == p2) // throws error , apply on similar data pairs
	cout<<"equal"<<endl ;
	else
	cout<<"Not equal"<<endl ; */
	
	cout<<"pair\tcontent"<<endl ;
	cout<<"pair1-"<<"\t"<<p1.first<<", "<<p1.second<<endl ;
	cout<<"pair2-"<<"\t"<<p2.first<<", "<<p2.second<<endl ;
	cout<<"pair3-"<<"\t"<<p3.first<<", "<<p3.second <<endl;
	cout<<"pair4-"<<"\t"<<p4.first<<", "<<p4.second <<endl;
	cout<<"Before Swapping\n"<<endl ;
	cout<<"pair3-"<<"\t"<<p3.first<<", "<<p3.second <<endl;
	cout<<"pair4-"<<"\t"<<p4.first<<", "<<p4.second <<endl;
	p3.swap(p4) ;
	cout<<"After Swapping\n"<<"pair3 :"<<endl ;
	cout<<"pair3-"<<"\t"<<p3.first<<", "<<p3.second <<endl;
	
	cout<<"pair4-"<<"\t"<<p4.first<<", "<<p4.second <<endl;
	return 0 ;
	
}
