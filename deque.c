#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
struct node *p,*q,*r;

void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void peek();
void display();

void main()
{
    int option;
    front=rear=NULL;
    do
    {
        printf("queue operations.....\n1:insert from front\n2:insert from rear\n3:delete from front\n4:delete from rear\n5:peek\n6:display\n7:exit\n");
        printf("enter your choice\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:insert_front();
                   break;
            case 2:insert_rear();
                   break;
            case 3:delete_front();
                   break;
            case 4:delete_rear();
                   break;
            case 5:peek();
                   break;
            case 6:display();
                   break;
            default:printf("invalid choice\n");
        }
    }while(option!=7);
}

void insert_front()
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
        q->next=front;
        front=q;
    }
}

void insert_rear()
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

void delete_front()
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

void delete_rear()
{
    int val;
    if(front==NULL)
    {
        printf("queue  is empty\n");
    }
    else
    {
        p=front;
        r=p->next;
        val=rear->data;

        while(r->next!=NULL)
        {
            r=r->next;
            p=p->next;
        }
        rear=p;
        rear->next=NULL;
        free(r);
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

