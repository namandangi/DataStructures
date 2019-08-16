#include<stdio.h>
#include<ctype.h>//for using isalpha()
//PENDING : BASIC STACK STRUCTURE,ERROR DEBUGING
int i=0,j=0,top=-1;
char st[20],postfix[10],infix[10],x,y;
	int pr(char x)
	{
		if(x=='+'||x=='-')
			return 2;
		else if(x=='/'||x=='*'||x=='%')
			return 3;
		else if(x=='(')
			return 1;
	}
void infixToPostFix()
{
	x=infix[i];
	while(x!='\0')
	{
		if(isalpha(x))
		{
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
				y=pop();
				while(top!=-1&&pr(x)>=pr(st[top]))
				{
					postfix[j]=y;
					j++;
					y=pop();
				}
				push(x);
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
		printf("Enter an algebric equation");
		gets(infix);
		infixToPostFix();
		puts(postfix);
	}
}