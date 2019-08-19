#include <stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *prev;
}*newnode,*temp,*top;

void push()
{
	int d;
	printf("Enter -1 to exit\n");
	while(d!=-1)
	{
	newnode =(struct node*)malloc(sizeof(struct node));
	printf("Enter data : \t");
	scanf("%d",&d);
	if(d==-1)
		break;
	newnode->data = d;
	if(top==NULL)
	{
		top = newnode;
		//temp = newnode;
	}
	else
	{
		newnode->prev = top;
		top = newnode;
	}
	
	}
	
}

int pop()
{
	int y;
	temp = top;
	y = top->data;
	top = top->prev;
	free(temp);
	return y;
}

int peek()
{
	int y;
	y = top->data;
	return y;
}

void display()
{
	temp = top;
	while(temp!=NULL)
	{
		printf("%d \n",temp->data);
		temp = temp->prev;
	}
}

void main()
{
	int c =-1,y;
	do
	{
		printf("Enter your choice \n");
		printf("0. EXIT\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. PEEK\n");
		printf("4. DISPLAY\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				push();
				break;
			}
			case 2 :
			{
				y=pop();
				printf("The popped value is : %d \n",y);
				break;
			}
			case 3 :
			{
				y = peek();
				printf("The peak value is : %d \n",y);
				break;
			}
			case 4:
			{
				display();
				break;
			}
			default :
			printf("Please check your input");
		}
	}while(c!=0);
	
}