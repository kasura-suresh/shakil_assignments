/***************************************************************************
                  C++ program to illustrate the 
           UNORDERED_SET class of Assosiative container
   note: irresepective of order of insertion ,o/p will be in different order
         dupilicate value won't consume memory
   Author : Md Shakil Ansari date -19-mar-2020 
 ****************************************************************************/ 

#include<iostream>
#include<unordered_set>
using namespace std ;
int main()
{
	unordered_set <int> s1  ;
	s1.insert(15) ; 
	s1.insert(5)  ;
	s1.insert(20) ;
	s1.insert(30) ;
	s1.insert(10) ;
	s1.insert(10) ;// set won't consider dupilicate values in the list
	cout<<"the size of the unordered set is :"<<s1.size()<<endl ;
	int key = 31 ;
	if (s1.find(key) == s1.end()) // search for an element
	cout<<key<<" is not present in the list"<<endl ;
	else
	cout<<key<<" is  present in the list"<<endl ;
	unordered_set <int> :: iterator itr =s1.begin() ; //iterator to traverse
	for (itr =s1.begin() ; itr != s1.end() ; itr++)
	cout<<*itr<<" " ;  // will print in unorderd manner
	s1.erase(15) ;
	itr =s1.begin() ;
	cout<<"\nAfter erasing 15 \n" ;
	cout<<"the size of the unordered_set  is :"<<s1.size()<<endl ;
	for (itr =s1.begin() ; itr != s1.end() ; itr++)
	cout<<*itr<<" " ;
	cout<<endl ;
	//erasing multiple elements
	s1.erase(s1.begin() ,s1.find(20)) ; // will delete all elements before 20
	cout<<"\n after deleting multiple elements \nNow the size of the unordered set is :"<<s1.size()<<endl ;
	return 0 ;
}

