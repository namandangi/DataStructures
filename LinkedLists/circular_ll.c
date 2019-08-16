#include<stdio.h>
#include<malloc.h>
//PENDING : INSERT AFTER ,INSERT BEFORE,DELETE AT 
struct node 
{
	int data;
	struct node *next;
}*newnode,*temp,*start;

void create()
{
	temp = start;
	int d=0,i;
	printf("Enter -1 to exit\n");
	while(d!=-1)
	{
		printf("Enter a value :");
		scanf("%d",&d);
		if(d==-1)
			break;
		else
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			
			//temp = start; logical-error :this statement is inside while loop so for after the first iteration all the remaining iterations get overwritten and thus we have only 2 values 
			if(start==NULL)
			{
				start=newnode;
				temp=newnode;
				newnode->data=d;
				temp->next = start;
			}
			else
			{	
				temp->next=newnode;
				newnode->next=start;
				newnode->data=d;
				temp=newnode;
			}
		}			
	}//
}

void insertBeg()
{
	int d;
	temp=start;
	printf("Enter a no.\n");
	scanf("%d",&d);
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=start;
	do
	{
		temp=temp->next;
	}while(temp->next!=start);
	temp->next = newnode;
	start=newnode;
}

void insertEnd()
{
	int d;
	temp = start;
	printf("Enter a no.\n");
	scanf("%d",&d);
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = d;
	do
	{
		temp=temp->next;
	}while(temp->next!=start);
	temp->next = newnode;
	newnode->next = start;
}

void deleteBeg()
{
	struct node *temp1;
	temp = start;
	temp1 = start;
	if(start==NULL)
	{
		printf("Link List is empty\n");
	}
	else
	{
		do
		{
			temp1=temp1->next;
		}while(temp1->next!=start);		
		start = start->next;
		temp1->next = start;		
		free(temp);
	}
}

void deleteEnd()
{
	struct node *pre;
	pre = start;
	temp = start;
	do
	{
		pre=temp;
		temp=temp->next;
	}while(temp->next!=start);
	pre->next = start;
	free(temp);
}

void display()
{
	temp = start;
	if(start!=NULL)
	{
		do
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}while(temp!=start);
	}
	else
		printf("Link List is empty\n");
		
}

void main()
{
	int c;
	do
	{
		printf("Enter your choice\n");
		printf("0. EXIT\n");
		printf("1. CREATE\n");
		printf("2. INSERT AT BEGINING\n");
		printf("3. INSERT AT END\n");
		printf("4. DELETE AT BEGINING\n");
		printf("5. DELETE AT END\n");
		printf("6. DISPLAY\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
			break;
			case 1:
			{
				create();
				break;
			}
			case 2:
			{
				insertBeg();
				break;
			}
			case 3:
			{
				insertEnd();
				break;
			}
			case 4:
			{
				deleteBeg();
				break;
			}
			case 5:
			{
				deleteEnd();
				break;
			}
			case 6:
			{
				display();
				break;
			}
			default:
			printf("Check Your Input");
		}
	}while(c!=0);
}
