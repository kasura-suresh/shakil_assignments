#include<iostream>
using namespace std;
class A{
	int num;
	public:
		A(int x){ //parameterised constructor
			num=x;
		}
		int operator --(){ //overloading the unary negative operator
			num=((num*10)-10);
			cout<<"\n The number after operator overloading becomes = "<<num<<endl;
			return num;
		}
};
int main()
{ 
    int n;
    cout<<"enter any number as operand"<<endl;
    cin>>n;
	A object(n);
   --(object);
	return 0;
}
