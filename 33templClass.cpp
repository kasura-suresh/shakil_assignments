/*************************************************************
    C++ programe to implement Template Class
    author : MD SHAKIL ANSARI
 *************************************************************/



#include<iostream>
using namespace std;
template <class T> // defining a template for class
class calculator
{
	public:
		T num1,num2;
		T add()
		{
			return (num1+num2);
		}
		T sub()
		{
			if(num1>num2)
			return (num1-num2);
			else
			return (num2-num1);
		}
		T mul()
		{
			return (num1*num2);
		}
		T div()
		{
			return (num1/num2);
		}
		void display()
		{
			cout<<" addition result is "<<add()<<endl;
			cout<<" multiplication result is "<<mul()<<endl;
			cout<<" subtraction result is "<<sub()<<endl;
			cout<<" modulus division result is "<<div()<<endl;
		}
 };
 int main()
 {
 	calculator<int> intCal; // creating object for integer calculation
 	calculator<float> floatCal;  // creating object for float calculation
 	cout<<"enter two integers for integer calculation: "<<endl;
    cin>>intCal.num1>>intCal.num2;
    intCal.display();
    cout<<"enter two float values  for decimal calculation: "<<endl;
    cin>>floatCal.num1>>floatCal.num2;
    floatCal.display();
    return 0;
  } 
