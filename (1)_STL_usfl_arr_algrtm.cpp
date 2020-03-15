/***************************************************
  C++ program for demonstration of useful array algorithms 
    function in STL
  Author - Md Shakil Ansari ,date - 14-mar-2020 
 ***************************************************/
#include<iostream>
#include<algorithm> //includes all_of,any_of,none_of methods
#define size 5 
using namespace std ;
int main()
{
	int i ;
	int arr[size] ;
	cout<<"\nenter "<<size<<" array elements\n" ;
	for (i =0 ;i <size ; i++)
	cin>>arr[i] ;
	all_of(arr ,arr+size ,[](int x){ return x>0 ;}) ? // checks for all elements to be positive ?
	        cout<<"All elements in the array are positive\n" :
	        cout<<"All elements in the array are NOT positive\n" ;	
	any_of(arr ,arr+size ,[](int x){ return x<0 ;}) ? // checks if any single element to be negative ?
	        cout<<"atleast one element in the array is negative\n" :
	        cout<<"none of the elements are negative\n" ;	
	none_of(arr ,arr+size ,[](int x){ return x<0 ;}) ? // checks for all elements to be positive ?
	        cout<<"None of the elements are negative\n" :
	        cout<<"there exists negative elements in the array\n" ;	
	int new_arr[size] ;
	copy_n(arr ,size ,new_arr) ; // copy elmenets into naother arr
	cout<<"the new copied array is :"<<endl ;
	for (i =0 ;i <size ; i++)
	cout<<new_arr[i]<<" " ;
	return 0 ;
}
