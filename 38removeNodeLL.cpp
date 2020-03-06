/****************************************
 c++ programe to REMOVE a node using  linkedList 
  
 author :Md Shakil Ansari ;date- 5 mar,2020 
 ****************************************/

#include<iostream>
using namespace std;
struct node // making a node of structure type
{
    int data;
    node *next;
};	
class linkedList
{
	private :
	node *START;
	public :
	linkedList( ) //constructor to intialize the start pounter
	{
		START = NULL ;
	}
	void creatNode()
	{
		int data;
		node *temp;
		temp = new node ; // allocating memory to the new node 
		cout<<"enter the value to enter into the list"<<endl;
		cin>>data;
		temp->data = data ;
		temp->next = NULL ;
		if(START == NULL)
	    START = temp ; //makes new node as the first node
	    else
	    {
	    	node *ptr ;
	    	ptr = START ; //for not disturbing START pointer
	    	while(ptr->next != NULL) // checks the last node of the list
	    	ptr = ptr->next ;
	    	ptr->next = temp ; // inserts the new node at end
		}
	}
		void display()
		{
			if (START == NULL) // checks whether the list is empty
			cout<<"sorry... the list is empty"<<endl;
			node *ptr;
			ptr = START ;
			while(ptr != NULL) // untill reaches the end of the list 
			{
			cout<<ptr->data<<" "; //prints the data of currently pointed node
			ptr = ptr->next ; // after printing , points to the next node
		    }
			
		}
		void deleteNode(int n)
		{
			node* temp = new node ;
			temp = START ;
			if(n == 1)
			{
				START = temp->next ; //start will point to the next(2nd) node
				delete(temp) ;
			}
			else
			{
				int i ;
				for(i = 0;i<n-2;i++) // loop upto previous node of target node
				{
					temp = temp->next ; // temp points to (n-1)th node
				}
				node* temp1 = temp->next ; // temp1 will point to nth node
				temp->next = temp1->next ; //fixing link between (n-1)th node & (n+1)th node
				delete(temp1);
			}
		}
}; 
int main()
{
	linkedList l; // creating object 
	int choice,position;
	do
	{
		cout<<" enter 1 to add elements in the list"<<endl;
		cout<<" enter 2 to display the elements in the list"<<endl;
		cout<<"OR enter 3  to delete"<<endl;
		cout<<" enter 4 to exit"<<endl;
		cin>>choice;
		if (choice == 1)
		l.creatNode();
		else if(choice == 2)
		l.display();
		else if(choice == 3)
		{
			cout<<"enter the position"<<endl;
			cin>>position;
	    	l.deleteNode(position);
	    }
		else
		exit(0);
	}while(choice !=4);
	return 0;
} 
