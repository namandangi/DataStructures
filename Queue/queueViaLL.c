
#include <conio.h>
#include <stdio.h>

struct Node{
int data;
struct Node* next;
}*f,*r;
void enqueue()
{
int i;
struct Node *newnode;
 newnode=(struct Node*) malloc(sizeof(struct Node));

 printf("enter data\n");
 scanf("%d",&(newnode->data));
 if(f=='\0')
 {   f=newnode;
 r=newnode;
 }
 else
 {
    r->next=newnode;
    r=newnode;
 }
}
void displaylist()
{
struct Node *temp;
temp=f;
if (f=='\0'){
    printf("Queue is empty\n");
}
else{
while(temp!=r)
{
  printf("%d\n",temp->data);
  temp=temp->next;
}
printf("%d\n", r->data);
}
}

void dequeue()
{
    int val;
struct Node *temp;
temp=f;
if(f=='\0')
{
    printf("Queue is empty\n");
}
else if (f!=r->next){
printf("%d\n",f->data);
f=f->next;
free(temp);
}
else{
    printf("Queue is empty\n");
}
}

void main()
{
int ch=-1;
while(ch<4)
{
printf("Menu\n");
printf("1.Enqueue\n");
printf("2.Dequeue\n");
printf("3.Display\n");
printf("4.Exit\n");
scanf("%d",&ch);
printf("\n");
switch(ch)
{
 case 1:{enqueue();break;}
 case 2:{dequeue();break;}
 case 3:{displaylist();break;}
 case 4:{printf("EXIT CONDITION MET");break;}

}
}}
