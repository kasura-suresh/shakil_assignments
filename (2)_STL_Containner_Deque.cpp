/*********************************************** 
   C++ program to illustrate the 
  various  functions in Deque class of STL
  author : Md Shakil Ansari date -15-mar-2020 
 ***********************************************/ 
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std ;
int main()
{
	deque <float> deq ;
	for (int i =0 ; i <5 ; i++)
	deq.push_back(i*5.5) ;
	for(auto itr = deq.begin() ; itr != deq.end() ; itr++)
	cout<<*itr<<"  " ;
	cout<<"\nthe size of deque is : "<<deq.size() ;
	deq.pop_front() ;
	cout<<"\nafter deleting from front \n" ;
	for(auto itr = deq.begin() ; itr != deq.end() ; itr++)
	cout<<*itr<<"  " ;
	deq.pop_back() ;
	cout<<"\nafter deleting from back \n" ;
	for(auto itr = deq.begin() ; itr != deq.end() ; itr++)
	cout<<*itr<<"  " ;
	cout<<"\nNow the size of deque is : "<<deq.size() ;
	return 0 ;
	
}
