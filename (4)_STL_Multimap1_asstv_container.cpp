/******************************************************************
   C++ program to illustrate the 
  various  functions in MULTI_MAP class of Assosiative container
  NOTE- it can contain dupilicate value provided pairs should be unique 
  Author : Md Shakil Ansari date -16-mar-2020 
 ******************************************************************/ 

#include<iostream>
#include<map>
using namespace std ;
int main()
{
	multimap <int ,string> student ;
	
	// assigning values into map
	student.insert(pair <int, string> (1, "Azim")); 
    student.insert(pair <int, string> (2, "Shakil")); 
    student.insert(pair <int, string> (3, "waqar")); 
    student.insert(pair <int, string> (4, "arman")); 
	// displaying the multimap list via iterator
	map <int ,string> :: iterator itr = student.begin();
	cout << "\nThe multimap  is : \n"; 
    cout << "KEY\tELEMENT\n"; 
	while(itr != student.end())
	{
		cout<< itr->first<<" " ;
		cout<<"\t"<<itr->second<<" " ; // will print in ascending order of the key or index
		cout<<endl ;
		itr++ ;
	}
	cout<<"\n Initially The size of the map is :"<<student.size()<<endl ; // will print the size of map list
	
	// to insert value
	itr = student.begin();
	student.insert(pair <int ,string>(3 , "danish")) ; // inserting at dupilicate key value
    cout << "\nThe multimap  is : \n"; 
    cout << "KEY\tELEMENT\n"; 
	while(itr != student.end())
	{
		cout<< itr->first<<" " ;
		cout<< "\t"<<itr->second<<" " ; // will print in ascending order of the key or index
		cout<<endl ;
		itr++ ;
	}
	cout<<"\n After insertion, The size of the map is :"<<student.size()<<endl ;
	
	if( student.empty()) // checks whether the list is empty or not
	cout<<"\n the map is empty\n" ;
	else
	cout<<"\n the map is NOT empty\n" ;
	return 0 ;
}
