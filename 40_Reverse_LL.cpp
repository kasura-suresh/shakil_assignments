/****************************************
 c++ programe to REVERSE a  Linked_List 
 using structure and class 
 author :Md Shakil Ansari ;date- 6 mar,2020 
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
		    cout<<endl ;
		}
		void reverse()
		{
			if (START == NULL) // checks whether the list is empty
			cout<<"sorry... the list is empty"<<endl;
			int i,j,k,temp,len=0;
			node  *p,*q; // taking two pointer variables to reverse
			p = q = START ;
			int count = 0 ;
			//code for finding the length of list
			
				if(START == NULL)
				cout<<"sorry....List is empty"<<endl;
				else
				{
				node* ptr = START ;
				while ( ptr != NULL)
				{
					ptr = ptr->next ;
					count++ ;
				}
		    	}
			len = count;
			for(i=0,j=len-1 ; i<j ; i++,j--)
			{
				k = 0 ;
				while(k < j) // for q to point the last unswapped node 
				{
					q =q->next ;
					k++ ;
				}
			// swapping the two nodes
			
				temp = q->data ;
				q->data = p->data ;
				p->data = temp ;
				p = p->next ;
				q = START ; // after each swap q is again made to point 1st node
			}
			cout<<"Here is the REVERSED LIST"<<endl;
			node* ptr = START ;
			while( ptr != NULL)
			{
				cout<<ptr->data<<" ";
				ptr =ptr->next ;
			}
			cout<<"\n";
			
			
			
		}
	
}; 
int main()
{
	linkedList l; // creating object 
	int choice;
	do
	{
		cout<<" enter 1 to add elements in the list"<<endl;
		cout<<" enter 2 to display the elements in the list"<<endl;
		cout<<" enter 3  to reverse the list"<<endl;
		cout<<" OR enter 4  to exit"<<endl;
		cin>>choice;
		if (choice == 1)
		l.creatNode();
		else if(choice == 2)
		l.display();
		else if(choice == 3)
		l.reverse() ;
		else
	   	exit(0);
	}while(choice != 4);
	return 0;
} 
