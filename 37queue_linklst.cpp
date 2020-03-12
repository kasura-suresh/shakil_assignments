/*************************************************************
    C++ programe to implement a QUEUE using linked list 
    author : MD SHAKIL ANSARI
 *************************************************************/


#include<iostream>
using namespace std;
struct node
{
	int data ;
	node* next ;
};
class queue
{
	node* FRONT ;
	node* REAR ;
	public :
		queue() // constructor definition
		{
			FRONT = NULL ;
			REAR = NULL ;
		}
		void insert()
		{
			
			 node* temp = new node ;
			cout<<"enter the element to insert"<<endl;
		
			cin>>temp->data;
			temp->next = NULL ; // Upto here one node is created 
			if(FRONT == NULL)
			{
		     	FRONT = REAR = temp; // incase queue is empty , new node becomes the 1st node
	    	        }
	    	       else 
	    	       {
	    	
			REAR->next = temp;
			REAR = temp;	
		       }
		}
		void Delete() // deletes from the front
		{
			
			if (FRONT == NULL)
			{
				cout<<"UNDERFLOW..queue is empty"<<endl ;
			}
			else if(FRONT == REAR) // incase of only one node 
			{
			    delete FRONT ;
			    FRONT = REAR = NULL ;
		        }
		       else
		       {
		    	node* temp = new node ;
		     	temp = FRONT ;
		     	FRONT = FRONT->next ; // front is modified
		     	delete temp ; // actually front is deleted
		       }
			
		}
		void display()
		{
			if(FRONT == NULL)
			cout<<"sorry..Queue is recently empty"<<endl;
			else
			{
				node* temp = FRONT ;
				while (temp!=NULL )
				{
				cout<<temp->data<<" ";
				temp = temp->next ;
			        }
			       cout<<endl;
			}
		}
		
};
int main()
{
	queue obj; // object creation
	int option; 
	cout<<"queue operations Lists :"<<endl;
	cout<<"Enter 1 to enter element into the queue :"<<endl;
	cout<<"Enter 2 to delete element from the queue :"<<endl;
	cout<<"Enter 3 to see the elements of the queue :"<<endl;
	cout<<"Enter 4 to EXIT :"<<endl;
	do
	{
		cout<<" choose any option"<<endl;
		cin>>option;
		switch(option)
		{
			case 1 :
				
				obj.insert() ;
				break ;
			    
			case 2 :
		    	
				obj.Delete() ;
				break ;
			    
			case 3 :
			    
				obj.display() ;
				break ;
			     
			case 4 :
				
				 exit(0);
				break ;
			     
			default :
			    cout<<"Invalid Choice"<<endl;	   
		}
	}while(option != 4);
	return 0 ;
}
