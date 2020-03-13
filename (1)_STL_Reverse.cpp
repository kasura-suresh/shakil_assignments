/************************************************* 
    C++ program implement REVERSE function in STL algorithm class
    author : MD SHAKIL ANSARI ,date - 12-mar,2020
 *************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int main()
{
	vector <float> arr ;
	for (int i =0 ; i<= 7 ; i++)
	arr.push_back(i+2.5) ;
	cout<<"BEFORE REVERSING....The Array is"<<endl ;
	for (int i =0 ; i<= 7 ; i++)
	cout<<arr[i]<<"  " ;
	reverse(arr.begin() ,arr.end()) ; // reversing the whole array
	cout<<"\nAFTER REVERSING....The Array is"<<endl ;
	for (int i =0 ; i<= 7 ; i++)
	cout<<arr[i]<<"  " ;
	cout<<"\nto reverse the array from position 3 to 5 only \n ";
	reverse((arr.begin()+ 3) , (arr.end() + 5) ) ; // reverse only from position 3 to 5
	vector <float> :: iterator itr ; // iterator for traversing the vector
	for (itr = arr.begin() ; itr != arr.end() ; itr++ )
	cout<<(*itr)<<"  " ; // why misbehaving the code here ?
	return 0 ;

}
