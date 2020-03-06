/****************************************
 c++ programe to implement CIRCULAR LinkedList 
 using structure and class 
 author :Md Shakil Ansari ;date- 5 mar,2020 
 ****************************************/



#include<iostream>
#include<stdio.h>
using namespace std;
struct node // making a node of structure type
{
    int data;
    node *next;
};	
class Circular_LL
{
	private :
	node *START;
	public :
	Circular_LL( ) //constructor to intialize the start pointer
	{
		START = NULL ;
	}
	void createNode()
	{
		int data;
		cout<<"enter an element"<<endl;
		cin>>data;
	//	node* temp = new node ;
		node* ptr = START ;
		
		//if the list is NOT empty
		if(START != NULL)
		{
			while(ptr->next != START)
			{
				ptr = ptr->next ;
			    ptr->next = ptr ; // last node pointing the newly created node
			}
			ptr->data = data ;
		    ptr->next = START ;		
		}
		else{ // Incase of empty node
		ptr->data = data ;
		ptr->next = START ;	
		START=ptr;
		//temp->next = temp ;// new node pointing to itself
		//START = temp ;
	}
	}
	void display() 
	{ 
       node*  ptr;
       ptr = START;
       while(ptr->next != START){
       	cout<< ptr->data <<" "; 
      ptr = ptr->next; 
	   }
   
   
    cout<<ptr->next<<endl; //JUST trying to see the address of START node here
    
	 if(ptr == START)       // to ensure circular linked list 
   cout<<"yes it is a circular linked list"<<endl;
   else
    cout<<"NO it is NOT a circular linked list"<<endl; 
    
   }
}; 
int main()
{
	Circular_LL obj ; // creating an object of class circular_LL
	int option ;
	cout<<"CIRCULAR LINKED LIST"<<endl;
	cout<<"enter 1 to insert element"<<endl;
	cout<<"enter 2 to display the list"<<endl;
	cout<<"enter 3 to exit"<<endl;
	do
	{
		cout<<"choose any one option"<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
				obj.createNode();
			    break;
			case 2:
				obj.display();
			case 3:
				exit(0);
				break ;
			default :
				cout<<"oops...Invalid Choice"<<endl;
				break;
	    }
	}while(option != 3);
	return 0;
}

