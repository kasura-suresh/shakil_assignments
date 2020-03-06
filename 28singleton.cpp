/*************************************************************
    C++ programe to implement singleton class
    author : MD SHAKIL ANSARI
 *************************************************************/



#include<iostream>
using namespace std;
class Singleton
{
	static Singleton *instance;
	int data;
	Singleton()
	{
		cout<<" object is created"<<endl;
	}
	public:
		static Singleton* Instance()
		{
			if (instance == NULL) // ensures only 1 object creation
			instance = new Singleton();
			return instance;
		}
		void obtainData(int value)
		{
			data=value;
		}
		int giveData()
		{
			return data;
		}
};
Singleton *Singleton::instance =NULL;
int main()
{
	int val;
	cout<<" enter the number :\n";
	cin>>val;
	Singleton::Instance()->obtainData(val); /* "::" operator is used since we are accessing members without 
	                                                creating any object */
	cout<<"you entered : "<<Singleton::Instance()->giveData()<<endl;
	return 0;
}
