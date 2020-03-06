/*************************************************************
    C++ programe to implement parameterised constructor
    author : MD SHAKIL ANSARI
 *************************************************************/


#include<iostream>
using namespace std;
class A{
	public:
		int a;
		float f;
		A(int i,float f){ // parametarised constructor
			a=i;
			this->f=f;
			cout<<"constructor is invoked when object is created."<<endl;
		}
};
int main()
{
	A obj(15,20.5); // creating object
	/*obj.a=15; // accessing public member
	obj.f=20.0;*/
	cout<<"The value of a and f is "<<obj.a<<"and "<<obj.f<<endl;
	return 0;
}
