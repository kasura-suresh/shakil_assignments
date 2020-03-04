#include<iostream>
using namespace std;
class Student
{
    public:
    int marks;
    void accept()
	{
        cout<<" Enter marks\n";
        cin>>marks;
        
    }
};
 
class Test :public Student{ // 1st level inheritance
    public:
    int p=0;	
    void check()
	{
        if(marks>60)
		{
            p=1;
        }
    }
};
 
class Result :public Test{ // 2nd level inheritance i.e multiple inheritance
    public:
    void print(){
        if(p==1)
        cout<<"\n The student is passed";
        else
        cout<<"\n The student is not passed";
    }
};
int main()
{
    Result r;
    r.accept(); // r object has access to all its parent classes
    r.check();
    r.print();
    return 0;
}
