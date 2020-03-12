/****************************************
 c++ programe to implement SORTING and SEARCHING in ALGORITHM in STL  
 author :Md Shakil Ansari ;date- 11 mar,2020 
 ****************************************/


#include<iostream>
#include<algorithm>
using namespace std ;
void display(int array[] , int size)
{
	for (int i = 0 ;i <size ; i++)
	cout<<array[i]<<" " ;
}
int main()
{
	int size ,i ,arr[size] ;
	cout<<"enter the size of the array"<<endl ;
	cin>>size ;
	cout<<"Now enter the array manually "<<endl ;
	for (i=0 ; i<size ; i++)
	cin>>arr[i] ;
	cout<<"SORTING"<<endl ;
	cout<<"\nBefore Sorting the array is \n"<<endl ;
	display(arr , size) ;
	sort (arr , arr+size ) ; // sort is a function member of algorithm class ,we can call it
	cout<<"\n After Sorting the array is \n"<<endl ;
    display(arr , size) ;
   
	int element ;
	cout<<"SEARCHING"<<endl ;
	cout<<"enter the element you want to search"<<endl ;
	cin>>element ;
	if (binary_search(arr , arr+size ,element)) // first sort then apply this,binary search works on sorted array   
	{
	cout<<element<<" is present in the array"<<"at arr_at"endl ;
    }
	else
	{
	cout<<element<<" is not present in the array"<<endl ;
    }
    
	
}
