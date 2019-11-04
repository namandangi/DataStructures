//Completly works
#include<ctype.h>
#include<stdio.h>
#include<malloc.h>
char postfix[50],infix[50],x;
 int top=-1;
struct Node{
    char data;
    struct Node *l,*r;    
}*newnode,*root,*temp;
struct Node *s[50],*op1,*op2;
void push(struct Node *val)
{
//	printf("Enter a Value\n");
//	scanf("%d",&val);
	if(top!=49)
	{
		top++;
		s[top]=val;
	}
	else if(top==49)
	{
		printf("Stack full\n"); 
	}
}
struct Node * pop()
{
	if(top!=-1)
	{
		struct Node * popval = s[top];
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

void create()
{
    int i=0;
    x =infix[i];
    while(x!='\0')
    {
        if(isalnum(x))
        {
            newnode=(struct Node *)malloc(sizeof(struct Node));
            newnode->data=x;
            newnode->l =NULL;
            newnode->r=NULL;
            push(newnode);
        }
        else
        {
            op2 = pop();
            op1 = pop();
            newnode=(struct Node *)malloc(sizeof(struct Node));
            newnode->data=x;
            newnode->l=op1;    newnode->r=op2;
            // newnode->l->l=NULL; newnode->l->r =NULL;
            // newnode->r->l=NULL; newnode->r->r =NULL;
            push(newnode);
        }
        i++;
        x = infix[i];
    }
    root = s[top];
//    printf("%c %c %c",root->data,root->l->data,root->r->data);
    printf("%c",root->data);
}
void inorder(struct Node *temp)
{
    if(temp!=NULL)
    {
        if(isalnum(temp->data))
        {
            inorder(temp->l);            
            //printf("\nbfr prnt\n");
            printf("%c",temp->data);
            //printf("\naftr prnt\n");
            inorder(temp->r);
        }
        else
        {
            printf("(");
            inorder(temp->l);
            printf("%c",temp->data);
            inorder(temp->r);
            printf(")");
        }
    }    
}
void main()
{
    printf("Enter an algebric equation : ");
	gets(infix);
	for(int i=0;i<15;i++)
	printf("%c",infix[i]); printf("\nbfr create\n");
    create();
    printf("\n");
    inorder(root);		
}