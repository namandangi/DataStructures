#include<stdio.h>

int st[5] ,top=-1,val,y,c;
void push()
{
	printf("Enter a Value\n");
	scanf("%d",&val);
	if(top!=4)
	{
		top++;
		st[top]=val;
	}
	else if(top==4)
	{
		printf("Stack full\n");
	}
}
void pop()
{
	if(top!=-1)
	{
		printf("The deleted element is : %d\n",st[top]);
		top--;
	}
	else
	{
		printf("Stack is empty");
	}
}
void peek()
{
	if(top!=-1)
	{
		printf("The topmost element is  : %d\n",st[top]);
	}
	else
	{
		printf("Stack empty\n");
	}
}
void display()
{
	for(int i=0;i<=top;i++)
	{
		printf("%d",st[i]);
	}
}
void maximum()
{
	int max = st[top];
	for(int i=top;i>-1;i--)
	{
		if(st[i]>max)
			max = st[i];
	}	
	printf("The current maximum element in the stack is : %d\n",max);
}
void main()
{
	do{

	printf("\nEnter your choice\n");
	printf("0. EXIT\n");
	printf("1. PUSH\n");
	printf("2. POP\n");
	printf("3. PEEK\n");
	printf("4. DISPLAY\n");
	printf("5. MAXIMUM ELEMENT\n");
	scanf("%d",&c);
	switch(c)
	{
		case 0 :
		break;
		case 1:
		{
			push();
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			peek();
			break;
		}
		case 4:
		{
			display();
			break;
		}		
		case 5 :
		{
			maximum();
			break;
		}
		default:
		{
			printf("Check your input");
		}						
	}
	}while(c!=0);
}