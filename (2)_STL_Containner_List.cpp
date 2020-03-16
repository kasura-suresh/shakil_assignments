/******************************************************************
   C++ program to illustrate the 
  various  functions in LIST class of container
  note :apart from the functions used below ,
        we can also use sort() ,reverse() ,clear() ,pop_front/back 
    # list implements doubly linked list
         
  Author : Md Shakil Ansari date -16-mar-2020 
 ******************************************************************/ 

#include<iostream>
#include<list>
using namespace std ;
int main()
{
	list <string> arr {"India->" ,"New Delhi :" , "Pakistan->" , "Islamabad :"} ; // initializing the list
	
	//for printing the content of list
    list <string> :: iterator itr = arr.begin() ;
    while (itr != arr.end())
    {
    	cout<< *itr<<" ";
    	itr++ ;
	}
	cout<<"\nthe size of the list is :"<<arr.size()<<endl ;
	arr.push_front("COUNTRIES & IT'S CAPITAL -:") ; //inserting at the begining
	arr.push_back("America-> Washington "); //inserting at the end
	itr = arr.begin() ;
	//again printing the content of list
	while (itr != arr.end())
    {
    	cout<< *itr<<" ";
    	itr++ ;
	}
	cout<<"\nNow the size of the list is :"<<arr.size()<<endl ;
	
}
