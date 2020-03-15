/*************************************************
  c++ programe to illustrate queue in STL 
  author :Md shakil Ansari date:14-mar-2020
  ************************************************/
#include <iostream> 
#include <queue> 

using namespace std; 

void display (queue <int> q) 
{ 
	queue <int> g = q; 
	while (!g.empty()) 
	{ 
		cout << '\t' << g.front(); 
		g.pop(); // removes the first element
	} 
	cout << '\n'; 
} 

int main() 
{ 
	queue <int> g; 
	g.push(5); 
	g.push(15); 
	g.push(20);
	cout<<"\nthe size of array is :"<<g.size() ; 
    cout << "\nThe queue is : "; 
	display(g); 
	cout << "\ng.front() : " << g.front(); 
	cout << "\ng.back() : " << g.back(); 
    cout << "\ng.pop() : "; 
	g.pop();
	cout<<"After pop , the queue is :"  ;
	display(g); 
    return 0; 
} 

