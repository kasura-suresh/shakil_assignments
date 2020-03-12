/*************************************************************
    C++ programe to implement dynamic memory allocation using malloc
    
    
    author : MD SHAKIL ANSARI ,date : 7 mar , 2020
 *************************************************************/


#include<iostream>
#include<stdlib.h>
using namespace std ;
int main()
{
	int* pointer = NULL ;
	pointer = (int*)malloc(sizeof(int)) ;
	if( pointer == NULL)
	cout<<"Sorry....Memory allocation failed"<<endl ;
	*pointer = 50 ;
	cout<<*pointer<<endl ; //will print the value
	cout<<pointer<<endl ; // will print the memory address allocated
	delete(pointer);
	cout<<pointer<<endl ; // should print any garbage address ?
	return 0 ;
	
}
