/******************************************************************
   C++ program to illustrate the 
   STACK class of Adaptive container
   note: Adaptive containers don't support iterators
         
  Author : Md Shakil Ansari date -16-mar-2020 
 ******************************************************************/ 

#include <iostream>
#include <stack>
#include <string>
 
using namespace std;
 
int main()
{
 
   stack<string> weekdays;
   weekdays.push("Saturday");
   weekdays.push("Friday");
   weekdays.push("Thursday");
   weekdays.push("Wednesday");
   weekdays.push("Tuesday");
   weekdays.push("Monday");
   weekdays.push("Sunday");
   cout<<"\n the size of the stack is :"<<weekdays.size()<<endl ;
   //printing the values 
   while(!weekdays.empty()) {
      cout<<weekdays.top()<<endl; //prints acc to LIFO 
      weekdays.pop();
   }
   cout<<"\nNow the size of the stack is :"<<weekdays.size()<<endl ;
   
 
   return 0;
}
