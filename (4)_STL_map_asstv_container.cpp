/******************************************************************
   C++ program to illustrate the 
  various  functions in MAP class of Assosiative container
  Author : Md Shakil Ansari date -16-mar-2020 
 ******************************************************************/ 

#include<iostream>
#include<map>
using namespace std ;
int main()
{
	map <int , string> student ;
	
	// assigning values into map
	student[1] = "azim" ;
	student[4] = "waqar" ;
	student[2] = "shakil" ;
	student[6] = "nehal" ;
	student[3] = "arman" ;
	// displaying the map list via iterator
	map <int ,string> :: iterator itr = student.begin();
	while(itr != student.end())
	{
		cout<< itr->second<<endl ; // will print in ascending order of the key or index
		itr++ ;
	}
	
	cout<<"\n Initially The size of the map is :"<<student.size()<<endl ; // will print the size of map list
	
	// to insert value
	itr = student.begin();
	student.insert(pair <int ,string>(5 , "danish")) ; // will insert in sorted manner
	while(itr != student.end())
	{
		cout<< itr->second<<endl ; // will print in ascending order of the key or index
		itr++ ;
	}
	cout<<"\n After insertion, The size of the map is :"<<student.size()<<endl ;
	
	if( student.empty()) // checks whether the list is empty or not
	cout<<"\n the map is empty\n" ;
	else
	cout<<"\n the map is NOT empty\n" ;
	return 0 ;
	
	
}
