//# Lab-19: WAP to insert a node at the end of given Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	 
	int data;
	struct node *next;
};
struct node *head,*ptr;
void insert()
{
	int DataToInsert;
	ptr=(struct node*) malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\n List is full !!");
	}
	else
	{
		struct node *curptr;
		printf("\n Enter the Data to be insterted : ");
		scanf("%d",&DataToInsert);
		if(head==NULL)
		{
			ptr->data=DataToInsert;
			head=ptr;
			ptr->next=NULL;
			printf("\n Element is Inserted @");
		}
		else
		{
			curptr=head;
			ptr->data=DataToInsert;
			while(curptr->next!=NULL)
			{
				curptr=curptr->next;
			}
			curptr->next=ptr;
			ptr->next=NULL;
			printf("\n Element is Inserted @");
		}
	}
}
void delete()
{
	struct node *frwrd,*bcwrd;
	frwrd=head;
	if(head==NULL)
		printf("\n List have no elements to Delete !! ");
	else
	{
		if(head->next==NULL)
		{
			printf("\n Element Deleted is :: %d",head->data);
			free(frwrd);	
			head=NULL;
		}
		else
		{
			while(frwrd->next!=NULL)
			{
				bcwrd=frwrd;
				frwrd=frwrd->next;
			}
		printf("\n Element Deleted is :: %d",frwrd->data);
		bcwrd->next=NULL;
		free(frwrd);
		}
	}
}
	
void display()
{
	ptr=head;
	if(ptr==NULL)
		printf("\n The list is Empty and had no elements to display !!");
	else
	{
		printf("\n Elements to be Display are :- ");
		while(ptr!=NULL)
		{
			printf("\t%d",ptr->data);
			ptr=ptr->next;
		}
	}
}
void main()
{
	int choice;
	while(1)
	{
		printf("\n*********** Linked List Operations **********************");
		printf("\n1.Insert the element \n2.Delete the element \n3.Display the List \n4.Exit from operations");
		printf("\nEnter Your Choice :: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
			break;
			case 2:delete();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:printf("\nYou have entered the wrong choice !!");
		}
	}
}

