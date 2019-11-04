//Completly Works
#include<stdio.h>
#include<ctype.h>//for using isalpha()
//PENDING : ERROR DEBUGING
int i=0,j=0,top=-1,c;
char st[50],postfix[50],infix[50],x,y;

void push(int val)
{
//	printf("Enter a Value\n");
//	scanf("%d",&val);
	if(top!=50-1)
	{
		top++;
		st[top]=val;
	}
	else if(top==49)
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
	int pr(char x)
	{
		if(x=='+'||x=='-')
			return 2;
		else if(x=='/'||x=='*'||x=='%')
			return 3;
		else 
			return 1;
	}
void infixToPostFix()
{
	x=infix[i];
	while(x!=0)
	{
		if(isalnum(x))
		{
			//printf("%c",x);
			postfix[j]=x;
			j++;
		}
		else if(x=='(')
		{
			push(x);
		}
		else if(x==')')
		{
			y=pop();
			while(y!='(')
			{
				postfix[j]=y;
				j++;
				y=pop();
			}
		}
		else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%')
		{
			if(top==-1||pr(x)>=pr(st[top]))
			{
				push(x);
			}
			else 
			{
				while(top!=-1&&pr(x)<=pr(st[top]))
				{
					y=pop();
					postfix[j]=y;
					j++;
					y=pop();
				}
				push(x);
			}
		}
			i++;
			x=infix[i];
	}
		while(top!=-1)
		{
			y=pop();
			postfix[j]=y;
			j++;
		}
}
	void main()
	{
		printf("Enter an algebric equation : ");
		gets(infix);
		for(int i=0;i<19;i++)
		printf("%c",infix[i]);
		infixToPostFix();
		printf("\n");
		//for(int i=0;i<3;i++)
		//printf("%c",postfix[i]);		
		puts(postfix);
	}
