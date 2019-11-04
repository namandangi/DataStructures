#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node{
int data;
struct Node *next;
}*top;
void push(){
int val;
struct Node *newnode,*temp;
printf("Enter the value of newnode ");
scanf("%d",&val);
newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=val;
if(top=='NULL'){
top=newnode;
}
else{
newnode->next=top;
top=newnode;
}}
int pop(){
int val;
struct Node *temp;
if (top=='NULL'){
printf("Stack empty\n");
return -1;
}
else{
temp=top;
val=temp->data;
top=top->next;
free(temp);
printf("Value popped is %d",val);
return(val);
}}
void peek(){
if(top=='NULL'){
printf("Stack empty\n");
}
else{
printf("Topmost element is %d",top->data);
}}
void main(){
int c=0;
int ele;
clrscr();
while(c!=4){
printf("\nMENU\n");
printf("1.push element\n2.pop element\n3.peek\n4.Exit case\nEnter Your Choice\n");
scanf("%d",&c);
switch(c){
case 1:{
push();
break;
}
case 2:{
ele=pop();
break;
}
case 3:{
peek();
break;
}
case 4:{
printf("EXIT CONDITION MET\n");
break;
}
default:{
printf("ERROR CHOICE TRY AGAIN\n");
}}}
printf("Thank You\n");
getch();}
