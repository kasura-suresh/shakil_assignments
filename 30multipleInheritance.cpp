/*************************************************************
    C++ programe to implement Multiple Inheritance
    author : MD SHAKIL ANSARI
 *************************************************************/


#include<iostream>
using namespace std;
class class1{
	    public:
		int data;
		class1(){
			cout<<"constructtor of 1st class is invoked"<<endl;
		}
		
			
		
	
};
class class2{
	public:
	int num;	
	class2(){
			cout<<"constructtor of 2nd class is invoked"<<endl;
			
			}
			
			
		
	
};
class class3 :public class2,public class1{ // implementing multiple inheritance
    public:
	class3(){
			cout<<"constructtor of 3rd class is invoked"<<endl;
			
		}
	
};
int main()
{
	class3 object; // constructors are called as per the order of inheritance 2,1,3  
	return 0;
}
