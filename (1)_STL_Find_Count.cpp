/************************************************* 
    C++ program implement FIND & COUNT function in STL 
    author : MD SHAKIL ANSARI ,date - 12-mar,2020
 *************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

int main() 
{ 
    int num ;
	vector <int> arr{2,4,2,7,4,2};
	cout<<"enter the number you want the frequency of"<<endl ;
	cin>>num ;

	cout << "Number of times "<<num <<"appears is : "<<count(arr.begin(), arr.end(), num); //count is a algorithm class method
		
	vector <int> :: iterator i ; // defining an iterator
	int key ;
	cout<<"\nIn the new array or vector"<<endl ;
	cout<<"\nenter the number you want to find "<<endl ;
	cin>>key ;
	vector <int> arr1 ; // taking new array for find operation
	for (int i = 0 ; i<5 ;i++)
	arr1.push_back(i*2) ; // entering data into vector
	i = find (arr1.begin() , arr1.end() ,key ) ;
	if(i != arr1.end())
	cout<<key<<" is found at position :"<<i-arr1.begin() ;
	else
	cout<<key<<" is not there in the list"<<endl ;

	return 0; 
} 

