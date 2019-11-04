#include <stdio.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear =-1;
int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}
int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}
void enQueue()
{
    int element;
    printf("Enter a number : ");
    scanf("%d",&element);
    if(isFull()) printf("\n Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}
int deQueue()
{
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else {
            front = (front + 1) % SIZE;
            
        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}
void display()
{
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);       
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
                    enQueue();
                    break;
                }
                case 2:
                {
                    deQueue();
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

