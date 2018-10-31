#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
struct node *p,*q;

void insert();
void delete();
void peek();
void display();

void main()
{
    int option;
    front=rear=NULL;
    do
    {
        printf("queue operations.....\n1:insert\n2:delete\n3:peek\n4:display\n5:exit\n");
        printf("enter your choice\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:peek();
                   break;
            case 4:display();
                   break;
            default:printf("invalid choice\n");
        }
    }while(option!=5);
}


void insert()
{
    int val;
    printf("enter the element to be inserted\n");
    scanf("%d",&val);
    q=(struct node*)malloc(sizeof(struct node));
    q->data=val;
    q->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=q;
        rear=q;
    }
    else
    {
        rear->next=q;
        rear=rear->next;
    }
}

void delete()
{
    int val;
    if(front==NULL)
        printf("queue is empty\n");
    else
    {
        p=front;
        val=front->data;
        front=front->next;
        p->next=NULL;
        free(p);
        printf("element deleted from queue is %d\n",val);
    }
    if(front==NULL)
        rear=NULL;
}

void peek()
{
    int val;
    if(front==NULL)
        printf("queue is empty\n");
    else
    {
        val=front->data;
        printf("element present at front is %d\n",val);
    }
}

void display()
{
    p=front;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
