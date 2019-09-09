#include<stdio.h>
#include<ctype.h>
int st[10],y1,y2,y,x,i=0;
char postfix[10];

int top=-1,c;
void push(int val)
{
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
int pop()
{
	if(top!=-1)
	{
		int popval = st[top];
	//	printf("The deleted element is : %d\n",st[top]);
		top--;
		return  popval;
	}
	else
	{
	//	printf("Stack is empty");
		return 0;
	}
}


void postfixToInfix()
{	
	x = postfix[i];
	while(x!='\0')
	{
		if(isNum(x))
		{
			
			y = float (x-'0');
			push(y);
		}
		else
		{
			y1 = pop();
			y2 = pop();
			if(x=='+')
			push(y1+y2);
			else if(x=='-')
			push(y1-y2);
			else if(x=='*')
			push(y1*y2);
			else if(x=='/')
			push(y1/y2);
			else(x=='%')
			push(int(y1)%int(y2));
		}
		i++;
		x = postfix[i];
	}
	printf("The infix value is : %f",st[i]);
}
				