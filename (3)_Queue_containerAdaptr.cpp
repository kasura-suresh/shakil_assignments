/******************************************************************
   C++ program to illustrate the 
   QUEUE class of Adaptive container
   note: Adaptive containers don't support iterators
         
  Author : Md Shakil Ansari date -16-mar-2020 
 ******************************************************************/ 

#include <iostream>
#include <queue>
#include <string>
 
using namespace std;
 
int main()
{
 
   queue<string> weekdays;
 
   weekdays.push("Saturday");
   weekdays.push("Friday");
   weekdays.push("Thursday");
   weekdays.push("Wednesday");
   weekdays.push("Tuesday");
   weekdays.push("Monday");
   weekdays.push("Sunday");
   
   cout<<"Size of the queue is: "<<weekdays.size()<<endl;
 
   while(!weekdays.empty()) {
      cout<<weekdays.front()<<endl; // prints acc to FIFO
      weekdays.pop();
   }
   cout<<"\n Now the Size of the queue is: "<<weekdays.size()<<endl;
   return 0;
}
