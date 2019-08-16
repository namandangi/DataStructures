#include<stdio.h>
#include<malloc.h>
//COMPLETED 
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*start,*temp,*newnode;

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
			newnode->data=d;			
			if(start==NULL)
			{
				start=newnode;
				temp=newnode;
				newnode->next=NULL;
				newnode->prev=NULL;
			}
			else
			{	
				temp->next=newnode;
				newnode->prev=temp;
				newnode->next=NULL;
				temp=newnode;
			}
		}			
	}
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
	newnode->prev=NULL;
	temp->prev=newnode;
	start=newnode;
}

void insertEnd()
{
	int d;
	temp = start;
	printf("Enter a no.\n");
	scanf("%d",&d);
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	while(temp->next!=NULL)
	{
		temp = temp->next;		
	}
	temp->next = newnode;
	newnode->prev = temp;
	newnode->next = NULL;
}

void insertAfter()
{
	int d,n;
	temp = start;
	printf("Enter the no. after which u want to insert\n");
	scanf("%d",&n);
	printf("Enter data\n");
	scanf("%d",&d);
	newnode = (struct node*)malloc(sizeof(struct node));
	while(temp->data!=n)
	{
		temp=temp->next;
	}
	newnode->data=d;
	newnode->next = temp->next;	
	newnode->prev = temp;
	temp->next->prev = newnode;
	temp->next = newnode;
}

void insertBefore()
{
	int d,n;
	temp = start;
	printf("Enter the no. before which u want to insert\n");
	scanf("%d",&n);
	printf("Enter data\n");
	scanf("%d",&d);
	newnode = (struct node*)malloc(sizeof(struct node));
	while(temp->data!=n)
	{
		temp=temp->next;
	}
	newnode->data=d;
	newnode->prev = temp->prev;
	newnode->next = temp;	
	temp->prev->next = newnode;
	temp->prev = newnode;
}

void deleteBeg()
{
	struct node *temp1;
	temp = start;
	if(start==NULL)
	{
		printf("Link List is empty\n");
	}
	else
	{
		start = start->next;
		start->prev = NULL;
		free(temp);
	}
}

void deleteEnd()
{
	temp = start;
	while(temp->next!=NULL)
	{
		temp = temp->next;		
	}
	temp->prev->next = NULL;
	free(temp);
}

void deleteAt()
{
	int d;
	temp = start;
	printf("Enter the no. which u want to delete\n");
	scanf("%d",&d);
	while(temp->data!=d)
	{
		temp = temp->next;		
	}
	temp->prev->next= temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}

void display()
{
	temp = start;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

void main()
{
	int c;
	do
	{
		printf("Enter your choices : ");
		printf("\n0. EXIT\n");
		printf("1. CREATE\n");
		printf("2. INSERT AT BEGINING\n");
		printf("3. INSERT AT END\n");
		printf("4. INSERT AFTER\n");		
		printf("5. INSERT BEFORE\n");		
		printf("6. DELETE AT BEGINING\n");
		printf("7. DELETE AT END\n");
		printf("8. DELETE AT\n");		
		printf("9. DISPLAY\n");
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
				insertAfter();
				break;
			}
			case 5:
			{
				insertBefore();
				break;
			}
			case 6:
			{
				deleteBeg();
				break;
			}
			case 7:
			{
				deleteEnd();
				break;
			}
			case 8:
			{
				deleteAt();
				break;
			}
			case 9:
			{
				display();
				break;
			}
			default:
			printf("Check Your Input");
		}
	}while(c!=0);
}
