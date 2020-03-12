/*************************************************************
    C++ programe to implement dynamic memory allocation using calloc
    note : initializes all memory blocks with zero
    
    author : MD SHAKIL ANSARI ,date : 7 mar , 2020
 *************************************************************/




#include<iostream>
#include<stdlib.h>
using namespace std ;
int main()
{
	int* pointer = NULL ;
	int i,n ;
	cout<<" enter the size of memory block you want\n";
	cin>>n ;
	pointer = (int*)calloc(n,sizeof(int)) ; // will allocate memory in array of n blocks
	if (pointer == NULL)
	{
		cout<<"Sorry... Memory allocation is failed"<<endl;
	}
	cout<<pointer<<endl ;
	cout<<"Before entering values ,the array is"<<endl ;
	for(i = 0 ; i < n ; i++)
	cout<<pointer[i]<<" " ;
	// asking user to input values into the memory block
	cout<<"\n enter your values "<<endl;
	for(i = 0 ;i <n ; i++)
	{
		cin>>pointer[i];
	}
	cout<<"After entering values ,the array is"<<endl ;
	for(i = 0 ;i <n ; i++)
	{
		cout<<pointer[i]<<" ";
	}
	free(pointer) ; // freeing the memory
	cout<<pointer<<endl ;
	retrun 0 ;
}
