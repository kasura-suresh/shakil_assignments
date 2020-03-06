/*************************************************************
    C++ programe to implement Ostream operator 
    author : MD SHAKIL ANSARI
 *************************************************************/


#include <iostream> 
using namespace std; 
  
int main() 
{ 
    char x;
	cout<<"enter a character\n" ;
    cin.get(x); // used to scan a single character ,an istream file 
    cout<<"this is what you entered\n" ;
	cout.put(x);  // ostream file to print single char 
    cout<<endl;
	cout.write("Ostream example",15); // public method to write a string
	cout<<"\n";
	cout.write("Ostream example",7);
	return 0;
} 
