/******************************************************************
   C++ program to illustrate the 
  various  functions in FORWARD LIST class of container
  note : implements singly linked list
  Author : Md Shakil Ansari date -16-mar-2020 
 ******************************************************************/ 

#include<iostream>
#include<forward_list>
using namespace std ;
int main()
{
    forward_list <int> arr ;
    arr.assign({2,4,6,10,15,10}) ;
    arr.push_front(1) ;
    //arr.push_end(8) ;
    forward_list <int> :: iterator itr =arr.begin() ;
    cout<<"BEFORE"<<endl ;
    while (itr != arr.end())
    {
        cout<<*itr<<" ";
        itr++ ;
    }
    cout<<"\n" ;
    arr.pop_front() ; // removes first element
    arr.remove(10) ; // removes all 10s present in the list
	itr = arr.begin() ;
	cout<<"AFTER"<<endl ;
	while (itr != arr.end())
    {
        cout<<*itr<<" ";
        itr++ ;
    }
    
}
