//#Lab-18: WAP to reverse a Linked List
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
		printf("\n Enter the Data to be insterted : ");
		scanf("%d",&DataToInsert);
		ptr->data=DataToInsert;
		ptr->next=head;
		head=ptr;
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
void reverse()
{
	struct node *frwrd,*bcwrd,*curptr;
	if(head==NULL)
		printf("\n List is Empty !! ");
	else
	{
		frwrd=NULL;bcwrd=NULL;curptr=head;
		printf("\n Reversing the Linked list ..... ");
		if(head->next==NULL)
		{
			printf("%d",frwrd->data);
		}
		else
		{
			while(curptr!=NULL)
			{
				frwrd=curptr->next;
				curptr->next=bcwrd;
				bcwrd=curptr;
				curptr=frwrd;
			}
			head=bcwrd;
		}
	}
}
/*void reverse11()
{
	int auxdata;
	struct node *curptr,*auxptr;
	if(head==NULL)
		printf("List is Empty !!");
	else
	{
		curptr=head;auxptr=head;
		while(curptr!=NULL)
		{
			curptr=curptr->next;
		}
		while(curptr==auxptr)
		{
			auxdata=curptr->data;
			curptr->data=auxptr->data;
			auxptr->data=auxdata;
			auxptr=auxptr->next;
		}
		
	}
}*/
void main()
{
	int choice;
	while(1)
	{
		printf("\n*********** Linked List Operations **********************");
		printf("\n1.Insert the element \n2.Delete the element \n3.Display the List \n 4.Reverse \n5.Exit from operations");
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
			case 4:reverse();
			break;
			case 5:exit(0);
			default:printf("\nYou have entered the wrong choice !!");
		}
	}
}
