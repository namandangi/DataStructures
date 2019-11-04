#include<stdio.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node *l,*r;
}*root,*newnode,*temp,*par,*succ,*psucc;

void insert()
{
    int val;
    printf("Enter a value to be inserted :");
    scanf("%d",&val);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->l=NULL; newnode->r=NULL;
     
    if(root==NULL)
    {
        root = newnode;        
    }        
    else
    {
        temp=root;
        while(temp!=NULL)
        {
            if(temp->data>val)
            {
                par =temp;
                temp=temp->l;
            }
            else
            {
                par = temp;
                temp =temp->r;
            }   
        }
        
            if(par->data>val)
            par->l=newnode;
            else
            par->r=newnode;
    }        
}
void display(struct Node *t)
{
    if(t!=NULL)
    {
    
     //   if (t->l != NULL)
        display(t->l);
        printf("%d\n",t->data);
     //   if (t->r != NULL)
        display(t->r);
    }
    
}
void delete()
{
    int val;
    printf("Enter a value to be deleted :");
    scanf("%d",&val);
    temp =root;
    while(temp!=NULL&&temp->data!=val)
        {
            if(temp->data>val)
            {
                par =temp;
                temp=temp->l;
            }
            else
            {
                par = temp;
                temp =temp->r;
            }   
        }
        if(temp==NULL)
        printf("Tree empty\n");
        else if(temp->l==NULL && temp->r==NULL)
        free(temp);
        else if(temp->l!=NULL && temp->r==NULL)
        {
            if(temp==par->l)
            {
                par->l=temp->l;
            }
            else
            {
                par->r=temp->l;
            }
            free(temp);
        }
        else if(temp->l==NULL && temp->r!=NULL)
        {
            // if(temp==par->l)
            // par->l = temp->r;
            // else
            // {
            //     par->r = temp->r;
            // }
            if(temp==par->r)
            par->r=temp->r;
            else 
            par->l=temp->r;
            free(temp);
        }
        else
        {
            temp = root;
            succ =root->l;
            while(succ->r!=NULL)
            {
                psucc = succ;
                succ =succ->r;
            }
            root->data = succ->data;
            psucc->r = succ->l;
            free(succ);
        }
        
}
void main()
{
    int c;
     do{
            printf("Please select your choice\n");
            printf("0.  EXIT\n");
            printf("1.  INSERT\n");
            printf("2.  DISPLAY\n");
            printf("3.  DELETE\n");
            scanf("%d",&c);
            switch(c)
            {
                case 0 :
                break;
                case 1 :
                {
                    insert();
                    break;
                }
                case 2 :
                {
                    display(root);
                    break;
                }
                case 3 :
                {
                    delete();
                    break;
                }
                default :
                printf("Please check ur input");
            }
        }while(c!=0);
}