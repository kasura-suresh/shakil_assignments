/**************************************************** 
    C++ program implement OSTREAM operator overloading 
    author : MD SHAKIL ANSARI ,date - 12-mar,2020
 ****************************************************/


#include<iostream> 
using namespace std; 

class Complex 
{ 
private: 
	int real, imag; 
public:
    Complex() // for fixing error
	{
	 cout<<"one object is created "<<endl ;	
	} 
	Complex(int r , int i ) 
	{ 
	real = r; 
	imag = i; 
	} 
	friend void operator << (ostream &output, Complex &c); // frnd fun to access private member
	friend void operator >> (istream &input, Complex &c); 
}; 
void operator << (ostream& output, Complex& c) // output and c1 is copied here as parameter
{ 
    output<<"The complex number is "<<endl ;
	output << c.real; 
	output <<" + "<<c.imag <<"i" <<endl; 
	
} 

void operator >> (istream& input, Complex& c) // input and c1 is copied here as parameter
{ 
    
        cout << "Enter Real Part "; 
	input >> c.real; 
	cout << "Enter Imaginary Part "; 
	input >> c.imag; 
	 
} 

int main() 
{ 
Complex c1; 
cin >> c1; // calling overloaded oprtr " >> " 
cout << c1; // calling overloaded oprtr " << " 
return 0; 
}

