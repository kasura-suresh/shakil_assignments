/***************************************************
   C++ program for illustration of Accumulate ,
  Max_Element ,Min_Element functions in STL
  Author - Md Shakil Ansari ,date - 13-mar-2020 
 ***************************************************/
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm> 
using namespace std; 

int main() 
{ 
    int i ;
	vector <int> v ;
	for (i =1 ;i <=10 ; i++)
	v.push_back(i*5) ;
	cout<<"the array is"<<endl ;
	for( i= 0 ; i<v.size() ;i++)
    cout<<v[i]<<"  ";
    cout<<"\ninitial size of vector is "<<v.size() ;
	// to insert element in vector at any position
	vector <int> :: iterator itr =v.begin() ; // iterator for traversing
	v.insert(itr+2 ,1, 12) ; // insert after 2 blocks in array
    cout<<"\nafter inserting the size of array is "<<v.size()<<endl ;
    cout<<"and the array is\n";
    for( i= 0 ; i<v.size() ;i++)
    cout<<v[i]<<"  ";
    cout<<"\nafter applying accumulate on the array..the sum of elements is :"<<endl ;
    cout<<accumulate(v.begin() ,v.end() , 0) ;
    cout<<"\nThe maximum element is :\n" ;
    cout<<*max_element(v.begin() ,v.end()) ;
    cout<<"\nThe minimum element is :\n" ;
    cout<<*min_element(v.begin() ,v.end()) ;

	return 0; 
} 

