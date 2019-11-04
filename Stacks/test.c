#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char st[50];
char infix[50];
char postfix[50];
float stack[30];
int top=-1;
int top2=-1;
void push(char x)
{
  if(top!=50-1)
  	{
  	    st[++top]=x;
  	}
  else
  	{
  	    printf("stack full");
	}

}

char pop()
{
    char y;
if(top!=-1)
	{y=st[top];
	 top--;
	 return y;}
else
	{printf("stack empty");
	return 0 ;}
}

int priority(char x)
	{if (x=='*'||x=='/'||x=='%')
		return 3;
	 if (x=='+'||x=='-')
	 	return 2;
	 else
	 	return 1;
	 }

void infixtopostfix()
{ int j=0,i=0;
  char x,y;
  x=infix[0];

  while(x!=0)
	{ if(isalnum(x))
		{postfix[j]=x;
		 j++;
		 }
	 else if(x=='(')
	 	{push(x);
		}
	 else if(x==')')
	 	{ y=pop();
	 	  while(y!='(')
	 	  	{postfix[j]=y;
	 	  	 j++;
	 	  	  y=pop();
	 	  	 }
	 	 }
	 else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%')
			{if(top==-1||priority(st[top])<priority(x))
			 	{push(x);
				}
			 else
			 		{while(top!=-1&&priority(st[top])>=priority(x) )
						{y=pop();
						 postfix[j]=y;
						 j++;
						 }
			 		 push(x);
					}
			}
		i++;
		x=infix[i];
	}

	while(top!=-1)
		{y=pop();
		 postfix[j]=y;
		 j++;
		 }
}

void push2(float m)
{
  top2++;
  stack[top2] = m;

}
float pop2()
{       float m;
	m = stack[top2];
	top2--;
	return m;

}
void postfix_eval()
{
int i=0;
char c;
float d;
float op1,op2,r;
c = postfix[i];
while(c!='\0')
{
	if(c<='9'&&c>='0')
	{
		d= (float) c - '0';
		push2(d);
	}
	else
	{
		op2 = pop2();
		op1 = pop2();
		if(c=='%')
		 r = (int) op1 % (int) op2;
		if(c=='*')
		r = op1 * op2;
		if(c=='/')
		r = op1/ op2;
		if(c=='+')
		r = op1+op2;
		if(c=='-')
		r = op1-op2;
		push2(r);
	}
	i++;
	c = postfix[i];

}
}

void main()
{int i;
 printf("enter infix expression");
 gets(infix);
 infixtopostfix();
 for(i=0;i<strlen(postfix);i++)
 	{printf("%c  ",postfix[i]);
 	}
postfix_eval();
printf("\nthe answer is %f",stack[top2]);
}


