#include<iostream>
using namespace std;
class A{ // definning a class
    int a;
	public:
	struct structure{ // definning a structure 
	int i;
	char c;
	float f;
    };
    structure s1; // declaring a node structure variable here 
};
class B : public A{ //inherting class A by child class B which inturn inherits structure
    
    public:
    B(){
    cout<<"constructor for class B is invoked "<<endl;
    }
};
int main()
{
	B b1;
	A a1;
	a1.s1.i = 5;
	b1.s1.i = 10; // accessing structure member by child class object
	cout<<"for B i="<<b1.s1.i<<endl; 
	cout<<"for A i="<<a1.s1.i<<endl;
	
	return 0;
	
}
