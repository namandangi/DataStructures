#include<stdio.h>
#include<malloc.h>
struct node 
{
	int pow;
	int coeff;
	struct node *next;
}*start1,*start2,*start3,*temp,*newnode;

void display(struct node *start)
{
	temp = start;
	while(temp!=NULL)
	{	
		//printf("Power");
		printf("%dx^%d+",temp->coeff,temp->pow);
		//printf("Coeff");
		//printf("%d",temp->coeff);
		temp=temp->next;
	}
}
struct node *comp(int c,int p,struct node *start)
{
	//temp = start3;
	printf("Entered comp");
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->pow = p;
	newnode->coeff = c;	
	if(start3==NULL)
	{
		start3  = newnode;
		temp = newnode;
		newnode->next =NULL;
	}
	else
	{
		temp->next = newnode;		
		temp = newnode;
		newnode->next =NULL;
	}
	printf("exit comp");
	return start;
}
struct node *create(struct node *starts)
{
	printf("Entered create");
	int p,c;
	struct node *start = starts;
  while(1)
  {
	printf("Enter the power : ");
	scanf("%d",&p);
	printf("Enter the coefficient : ");
	scanf("%d",&c);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->pow=p;
	newnode->coeff=c;		
	if(p==-1)
	break;
	else if(start==NULL)
	{
		start=newnode;
		temp=newnode;
	}
	else
	{
		temp->next=newnode;
		temp = newnode;
	}
 }
//	display(start);
	return start;
}

struct node *addition(struct node *start1,struct node *start2,struct node *start3)
{
	
	int p,c;
	struct node *t1,*t2;
	t1=start1;
	t2=start2;
//	newnode=(struct node*)malloc(sizeof(struct node));
	while(t1->next!=NULL && t2->next!=NULL)
	{
	printf("Enered addition");
		if(t1->pow > t2->pow)
		{
			p = t1->pow;
			c = t1->coeff;
			//start3 = comp(c,p,start3);
			t1=t1->next;
		}
		if(t1->pow < t2->pow)
		{
			p = t2->pow;
			c = t1->coeff;	
			//start3 = comp(c,p,start3);
			t2=t2->next;
		}
		else
		{
			p = t1->pow + t2->pow;
			c = t1->coeff + t2->coeff;
			//start3 = comp(c,p,start3);
			t1=t1->next;
			t2=t2->next;
		}
		start3 = comp(c,p,start3);
		printf("back in addition");
	}
	if(t1==NULL)
	{
		while(t2!=NULL)
		{
			p=t2->pow;
			c=t2->coeff;
			start3 = comp(c,p,start3);
			t2=t2->next;
		}
	}
	else if(t2==NULL)
	{
		while(t1!=NULL)
		{
			p=t1->pow;
			c=t1->coeff;
			start3 = comp(c,p,start3);
			t2=t2->next;
		}
	}
	return start3;
}


void main()
{
	start1 = create(start1);
//	display(start1);
	start2 = create(start2);
//	display(start2);
	start3 = addition(start1,start2,start3);
	display(start3);
}
