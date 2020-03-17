/******************************************************************
   C++ program to illustrate the 
   priority Queue class of Adaptive container
   note: priority will be given to larger elements to be printed first
         
  Author : Md Shakil Ansari date -16-mar-2020 
 ******************************************************************/ 

#include <iostream>
#include <queue>
#include <string>
 
using namespace std;
 
int main()
{
 
   priority_queue<int> nums;
   ///data are inserted in unsorted manner
   nums.push(9);
   nums.push(2);
   nums.push(7);
   nums.push(1);
   nums.push(4);
 
   cout<<"Size of the stack: "<<nums.size()<<endl;
 
   while(!nums.empty()) {
      cout<<nums.top()<<endl; // larger element will be printed first
      nums.pop();
   }
  cout<<"\nNow the Size of the stack: "<<nums.size()<<endl;
   return 0;
}
