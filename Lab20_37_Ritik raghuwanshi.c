//# Lab-20: WAP to implement a Doubly Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL,*ptr;
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
			//printf("\n Element is Inserted @");
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
		}
		else
		{
			while(trav->next!=NULL)
			{
				trav=trav->next;
			}
			printf("\n The Deleted element is : %d ",trav->data);
			trav->prev->next=NULL;
			free(trav);
		}
	}
}
void delet_At_Loc()
{
    struct node *ptr,*prePtr;
    int i,pos;
    if(head==NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        ptr=head;
        printf("Enter location you want to delet Node:");
        scanf("%d",&pos);
        for(i=1;i<=pos-1;i++)
        {
            prePtr=ptr;
            ptr=ptr->next;
        }
        printf("%d is deleted!!",ptr->data);
        ptr->prev->next=ptr->next;
       	ptr->next->prev=ptr->prev;
	    free(ptr);
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
	curptr=head;
	if(curptr==NULL)
		printf("\n List is Empty and have No Element to Display !!");
	else
	{
		printf("\nElements in the list are : ");
		while(curptr->next!=NULL)
			curptr=curptr->next;
		while(curptr!=NULL)
		{
			printf("-->%d",curptr->data);
			curptr=curptr->prev;
		}
	}
}

void searchElement()
{
	struct node *curptr;
	curptr=head;
	int dataToFind=0,flag=0,count=1;
	if(head==NULL)
		printf("\n List is Empty Cannot Search !! ");
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
			case 2:delet_At_Loc();//deletee();
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
