/*************************************************************
    C++ programe : copy constructor
    author : MD SHAKIL ANSARI
 *************************************************************/

#include<iostream>
using namespace std;
class A{
    public:
	int a;
	A(int i){ // parametarized constructure
		    a=i;
		}
		A(A &n){ // defining copy constructure
			a= n.a;
		}
};
int main()
{
	A obj1(5);
	A obj2(obj1); // invoking copy constucture
	cout<<"before copy constructure ,value of object1 ="<<obj1.a<<endl;
	cout<<"after copy constructure ,value of object2 ="<<obj2.a<<endl;
	return 0;
}
