//Lab-21: WAP to perform searching in given Doubly Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL,*End=NULL,*ptr;////
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
			End=NULL;//
			ptr->next=NULL;
			ptr->prev=NULL;
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
			ptr->prev=curptr;
			ptr->next=NULL;
			End=ptr;//
			printf("\n Element is Inserted @");
		}
	}
}
void deletee()
{
	struct node *trav;
	trav=head;
	if(trav==NULL)
		printf("\n List is Empty !!");
	else
	{
		if(head->next==NULL)
		{
			printf("\n This is the last element deleted of the list : %d ",head->data);
			free(head->next);
			head=NULL;
			End=NULL;
		}
		else
		{
			trav=End->prev->next;
			printf("\n The Deleted element is : %d ",trav->data);
			End->prev->next=NULL;
			End=trav->prev;
			free(trav);
		}
	}
}
void display()
{
	struct node *trav;
	trav=head;
	if(trav==NULL)
		printf("\n List is Empty and have No Element to Display !!");
	else
	{
		printf("\nElements in the list are : ");
		while(trav!=NULL)
		{ 
			printf("-->%d",trav->data);
			trav=trav->next;
		}
	}
}
void displayInBack()
{
	struct node *curptr;
	if(End==NULL)
		printf("\n List is Empty and have No Element to Display !!");
	else
	{
		printf("\nElements in the list are : ");
		curptr=End;
		while(curptr!=NULL)
		{
			printf("-->%d",curptr->data);
			curptr=curptr->prev;
		}
	}
}
int searchElement()
{
	struct node *curptr;
	curptr=head;
	int dataToFind=0,flag=0,count=1;
	if(head==NULL)
	{
		printf("\n List is Empty Cannot Search !! ");
		return 0;
	}		
	else
	{
		printf("Enter the data to Find in Linked List : ");
		scanf("%d",&dataToFind);
		while(curptr!=NULL)
		{
			if(curptr->data==dataToFind)
			{
				flag++;
				break;
			}	
			count++;
			curptr=curptr->next;
		}
	}
	if(flag==1)
		printf("Element is found in the list at position :: %d  ",count);
	else
		printf("Element is not found in the List ");
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n\n ************************************* Doubly Linked List Operations **************************************************");
		printf("\n1.Insert\n2.Delete\n3.Display the Linked list\n4.Display in reverse \n5.Search the element in the linked list  \n6.Exit from operations ");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
			break;
			case 2:deletee();
			break;
			case 3:display();
			break;
			case 4:displayInBack();
			break;
			case 5:searchElement();
			break;
			case 6:exit(0);
			default : printf("\nYou have Entered the Wrong choice .... ");
		}
	}
	return 0;
}
