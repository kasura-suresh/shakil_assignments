/*************************************************************
    C++ programe to implement dynamic memory allocation using NEW & DELETE
    
    can allocate single block as well as an array of memory blocks
    
    author : MD SHAKIL ANSARI ,date : 7 mar , 2020
 *************************************************************/
#include<iostream>
using namespace std ;
int main()
{
	int data = 15 ;
	int size ;
	int* p = new int ; // allocating single block dynamically
	cout<<"address of memory block pointed by p is : "<<p<<endl ;
	p = &data ; // p holding the address of data variable
	cout<< "value at p is : "<<*p<<endl ;
	delete p ; // freeing memory block pinted by p
	cout<<"after deleting p is holding the address " << p<<endl ;
	cout<<"enter the size of memory to be allocated"<<endl ;
	cin>>size;   
	float* arr_ptr = new float[size] ; // allocating an array of memory blocks
	cout<<"the array is allocated at \n" ; 
	cout<<arr_ptr<<endl ; // prints the address
	delete arr_ptr ;
	return 0 ;  
}
