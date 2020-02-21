#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* START=NULL; /* initializing START pointer with NULL to avoid any garbage value*/
struct node* creatNode()
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node)); /* allocating memory to the new node*/
	return new;
	
}
void insertNode()  /* inserts at the end*/
{
	struct node* temp,*ptr;
	temp=creatNode();
	printf("\n enter a data to the new node\t");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(START==NULL)
	START=temp;
	else
	{
	ptr=START;     /* for not disturbing START*/
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=temp;
    }
}
void deleteNode() /* deletes the very first node of the list*/
{
	struct node* ptr;
	if(START==NULL)
	printf("\n Deletion is not possible... List is empty!");
	else
	{
		ptr=START;
		START=START->next;
		free(ptr);
	}
}
void displayList()
{
	struct node* ptr;
	if(START==NULL)
	printf("\n sorry.. the list is empty:");
	else
	{
		ptr=START;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
int menu()
{
	int option;
	printf("\n add data to the list:");
	printf("\n delete first data of the list:");
	printf("\n view the list:");	
	printf("\n EXIT:");
	printf("\n // ***************** //");
	printf("\n CHOOSE YOUR OPTION:");
	scanf("%d",&option);
	return option;
}
int main()
{
	while(1)
	{
		switch(menu())
	{
		case 1:
			insertNode();
			break;
		case 2:
			deleteNode();
			break;
		case 3:
		    displayList();
			break;
		case 4:
		    exit(0);
		default:
		    printf("\n oops..! invalid choice");
		}
			
	}
	return 0;
	
}

	
	
	




