#include<iostream>
using namespace std;
struct node // making a node of structure type
{
    int data;
    node *next;
};	
class stack
{
	private :
	node *TOP;
	public :
	stack( ) //constructor to intialize the top pointer
	{
		TOP = NULL ;
	}
	void push()
	{
		int val;
		cout<<"enter the data to insert into the stack"<<endl;
		cin>>val;
		node *newNode = new node ; // allocating memory to the new node
		newNode->data = val ;
		newNode->next = TOP ;
		TOP = newNode ;
	}
	void pop()
	{
		if(TOP == NULL)
		cout<<"stack underflow"<<endl;
		else
		{
		cout<<"the popped element is"<<TOP->data<<endl;
		TOP =TOP->next ;
		}
	}
	void display()
	{
		if(TOP == NULL)
		cout<<"sorry...the stack is empty"<<endl;
		else
		{
			node *ptr = TOP ;
			cout<<"the elements in the stack arearranged as :"<<endl;
			while(ptr != NULL)
			{
			cout<<ptr->data<<endl;
			ptr =ptr->next ;
		    }
		}
	}
};
int main()
{
	int choice;
	stack object ; // creating an object of stack class
	cout<<"1) Push into the stack"<<endl;
   cout<<"2) Pop from the stack"<<endl;
   cout<<"3) Display the element of stack"<<endl;
   cout<<"4) Exit"<<endl;
   do
   {
   	cout<<"Enter your choice: "<<endl;
      cin>>choice;
      switch(choice)
      {
      case 1:
      	{
      	object.push();
      	break ;
        }
      case 2:
      	{
      	object.pop();
      	break ;
        }
      case 3:
      	{
	    object.display();
		break ;
    	}
	  case 4:
	  	{
	    cout<<"EXIT"<<endl;
		break ;
    	}
	  default :
	  	{
		  cout<<" oops...invalid choice"<<endl;
	    }			
      }
    }while(choice != 4);
    return 0;
}
	
	
		
	
