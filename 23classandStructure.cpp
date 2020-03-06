/*************************************************************
    C++ programe to implement structure and class
    author : MD SHAKIL ANSARI
 *************************************************************/


#include<iostream>
using namespace std;

/* creating class */
class A{
	public:
		int a,b;
		A(){      /* defining a constructor to ensure object creation*/
			cout<<"constructor is invoked"<<endl;
		}
		
};
/* creating a structure*/
struct employee{
	int id;
	float salary;
};
int main()
{
	A obj;/* creating an object of class A*/
	employee e1; // defining an instance variable of structure ;
	e1.id=123;
	e1.salary=25000.00;
	cout<<"the employee id and salary is "<<e1.id<<" "<<"and "<<e1.salary<<" " <<"respectively"<<endl;
	return 0;
}

