/*************************************************************
    C++ programe to implement dynamic memory allocation using realloc
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
	cout<<pointer<<endl ; // prints the address
	cout<<"Before entering values ,the array is"<<endl ;
	for(i = 0 ; i < n ; i++)
	cout<<pointer[i]<<" " ;
	// asking user to input values into the memory block
	cout<<"\n enter your values "<<endl;
	for(i = 0 ;i <n ; i++)
	{
		cin>>pointer[i];
	}
	int newsize ;
	cout<<"do you want to resize the aray ? enter the updated size"<<endl ;
	cin>>newsize;
	pointer = (int*)realloc(pointer , newsize*sizeof(int)) ; //resize the allocated space from n to newsize
	cout<<"After entering values ,the array is"<<endl ;
	for(i = 0 ;i <n ; i++)
	{
		cout<<pointer[i]<<" ";
	}
	free(pointer) ; // freeing the memory
//	cout<<pointer<<endl ;
	return 0 ;
}
