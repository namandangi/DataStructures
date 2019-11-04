#include<stdio.h>
int q[10],f=-1,r=-1,v,c1,c2,i;

void Nenqueue(int n)
{
    if(f==-1)
    {
        f=0;r=0;
        q[r]=n;
    }
    else if((r+1)%10!=f)
    {
        r = (r+1)%10;
        q[r]=n;
    }
    else
    {
        printf("Queue is full");
    }
    
}
void Senqueue(int n)
{
    if(f==-1)
    {
        f=0;r=0;
        q[f]=n;
    }
    else if((r+1)%10!=f)
    {
        f = (f+9)%10;
        q[f]=n;
    }
    else
    {
        printf("Queue is full");
    }
}
int Ndequeue()    
{
    if(f==-1)
    {
        printf("Queue is empty");
        return -1;
    }
    else if(f==r)
    {
        v = q[f];
        f=-1;r=-1;
        return v;
    }
    else
    {
        v=q[f];
        f++;
        return v;
    }    
}
int Sdequeue()
{
    if(f==-1)
    {
        printf("Queue is empty");
        return -1;
    }
    else if(f==r)
    {
        v = q[f];
        f=-1;r=-1;
        return v;
    }
    else
    {
        v=q[r];
        r = (r+9)%10;
        return v;
    }
}
void main()
    {
        do
        {
            printf("Please select your choice\n");
            printf("0.  EXIT\n");
            printf("1.  INPUT RESTRICTED QUEUE\n");
            printf("2.  OUTPUT RESTRICTED QUEUE\n");
            scanf("%d",&c1);
            switch(c1)
            {
                case 0 :
                break;
                case 1 :
                {
                    do
                    {
                        printf("Please select your choice\n");
                        printf("0.  MAIN MENU\n");
                        printf("1.  ENQUEUE USING REAR\n");
                        printf("2.  DEQUEUE USING REAR\n");
                        printf("3.  DEQUEUE USING FRONT\n");
                        scanf("%d",&c2);
                        switch(c2)
                        {
                            case 0 :
                            break;
                            case 1 :
                            {
                                printf("Please enter a number : ");
                                scanf("%d",&i);
                                Nenqueue(i);
                                break;
                            }
                            case 2 :
                            {
                                v = Sdequeue();
                                if(v!=-1)
                                printf("The deleted value is : %d\n",v);
                                break;
                            }
                            case 3 :
                            {
                                v = Ndequeue();
                                if(v!=-1)
                                printf("The deleted value is : %d\n",v);
                                break;
                            }
                            default :
                            printf("Please check your input");
                        }
                    }while(c2!=0);
                    break;
                }
                case 2 :
                {
                    do
                    {
                        printf("Please select your choice\n");
                        printf("0.  MAIN MENU\n");
                        printf("1.  ENQUEUE USING FRONT\n");
                        printf("2.  DEQUEUE USING FRONT\n");
                        printf("3.  ENQUEUE USING REAR\n");
                        scanf("%d",&c2);
                        switch(c2)
                        {
                            case 0 :
                            break;
                            case 1 :
                            {
                                printf("Please enter a number : ");
                                scanf("%d",&i);
                                Senqueue(i);
                                break;
                            }
                            case 2 :
                            {
                                v = Ndequeue();
                                if(v!=-1)
                                printf("The deleted value is : %d\n",v);
                                break;
                            }
                            case 3 :
                            {
                                printf("Please enter a number : ");
                                scanf("%d",&i);
                                Nenqueue(i);
                                break;
                            }
                            default :
                            printf("Please check your input");
                        }
                    }while(c2!=0);
                    break;                
                }
                default :
                printf("check your input");
            }
        }while(c1!=0);        
    }

