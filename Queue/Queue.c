#include <stdio.h>
int q[5],front=-1,rear=-1;
void enqueue()
{
	int d;
	scanf("%d",&d);
	if(front==-1)
	{
		front=0;
		rear=0;
		q[rear] = d;
	}
	else
	{
		rear++;
		q[rear] = d;	
	}
}
void dequeue()
{
	int y;
	if(rear==-1)
	{
		printf("Queue is empty\n");
	}
	else if(front!=rear)
	{
		printf("The deleted element is : %d \n",q[rear]);
		rear--;
	}
	else
	{
		printf("The deleted element is : %d \n",q[rear]);
		front=0;
		rear=0;
	}
}

void display()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("The element is : %d \n",q[i]);
	}
}

void main()
{
	int c;
	 	do{

			printf("\nEnter your choice\n");
			printf("0. EXIT\n");
			printf("1. ENTER_QUEUE\n");
			printf("2. DELETE_QUEUE\n");
			printf("3. DISPLAY\n");
			scanf("%d",&c);
			switch(c)
			{
				case 0 :
				break;
				case 1:
				{
					enqueue();
					break;
				}
				case 2:
				{
					dequeue();
					break;
				}
				case 3:
				{
					display();
					break;
				}
				default:
				{
					printf("Check your input");
				}						
		}
	}while(c!=0);
}

