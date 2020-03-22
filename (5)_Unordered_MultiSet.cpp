/***************************************************************************
                  C++ program to illustrate the 
           UNORDERED_MULTISET class of Assosiative container
   note: irresepective of order of insertion ,o/p will be in different order
         dupilicate value will hold place in the set
   Author : Md Shakil Ansari date -19-mar-2020 
 ****************************************************************************/ 

#include<iostream>
#include<unordered_set>
using namespace std ;

int main()
{
	unordered_multiset <int> s1  ;
	s1.insert(15) ; 
	s1.insert(5)  ;
	s1.insert(25) ;
	s1.insert(30) ;
	s1.insert(10) ;
	s1.insert(10) ;// multiset will consider dupilicate values in the list
	cout<<"the size of the unordered set is :"<<s1.size()<<endl ;
	
	unordered_set <int> :: iterator itr =s1.begin() ;
	for (itr =s1.begin() ; itr != s1.end() ; itr++)
	cout<<*itr<<" " ;  // will print in unordered manner
	s1.erase(15) ;
	itr =s1.begin() ;
	cout<<"\nAfter erasing 15 \n" ;
	if(s1.empty())
	cout<<"\nthe list is empty"<<endl ;
	else
	cout<<"\nthe list is NOT empty"<<endl ;
	cout<<"And the size of the unordered_set  is :"<<s1.size()<<endl ;
	for (itr =s1.begin() ; itr != s1.end() ; itr++)
	cout<<*itr<<" " ;
	cout<<endl ;
	// removing all elements
	s1.clear() ; 
	cout<<"\nafter clear operation the size of the unordered_set  is :"<<s1.size()<<endl ;
	if(s1.empty())
	cout<<"\nthe list is NOW empty"<<endl ;
	else
	cout<<"\nthe list is NOT empty"<<endl ;
	
	return 0 ;
	
}

