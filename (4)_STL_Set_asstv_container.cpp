/******************************************************************
   C++ program to illustrate the 
   SET class of Asosiative container
   note: irresepective of order of insertion ,o/p will be sorted
         dupilicate value won't consume memory
   Author : Md Shakil Ansari date -17-mar-2020 
 ******************************************************************/ 

#include<iostream>
#include<set>
using namespace std ;

int main()
{
	set <int> s1  ;
	s1.insert(15) ; 
	s1.insert(5)  ;
	s1.insert(25) ;
	s1.insert(20) ;
	s1.insert(30) ;
	s1.insert(10) ;
	s1.insert(10) ;// set won't consider dupilicate values in the list
	cout<<"the size of the set is :"<<s1.size()<<endl ;
	set <int> :: iterator itr =s1.begin() ;
	for (itr =s1.begin() ; itr != s1.end() ; itr++)
	cout<<*itr<<endl ;  // will print in sorted manner
	s1.erase(15) ;
	itr =s1.begin() ;
	cout<<"\nAfter erasing 15 \n" ;
	cout<<"the size of the set is :"<<s1.size()<<endl ;
	for (itr =s1.begin() ; itr != s1.end() ; itr++)
	cout<<*itr<<endl ;
	cout<<endl ;
	//erasing multiple elements
	s1.erase(s1.begin() ,s1.find(20)) ; // will delete all elements before 20
	cout<<"\nNow the size of the set is :"<<s1.size()<<endl ;
	for (itr =s1.begin() ; itr != s1.end() ; itr++)
	cout<<*itr<<endl ;
	
}
