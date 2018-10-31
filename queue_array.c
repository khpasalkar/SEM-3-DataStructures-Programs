#include<stdio.h>
#define max 3
void insert();
void delete();
void peek();
void display();
int queue[max];
int front=-1,rear=-1;

void main()
{
    int option;
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
    printf("enter the element to insert\n");
    scanf("%d",&val);
    if(rear==-1)
    {
        front=rear=0;
        queue[rear]=val;
    }
    else if(rear==max-1)
    {
        printf("queue overflow\n");
    }
    else
    {
        rear++;
        queue[rear]=val;
    }
}

void delete()
{
    int val;
    if(front==-1)
    {
        printf("queue is empty\n");
        val=-1;
    }
    else if(front==rear)
    {
        val=queue[front];
        front=rear=-1;
    }
    else
    {
        val=queue[front];
        front++;
    }
    if(val!=-1)
    {
        printf("element deleted from queue is %d\n",val);
    }
}

void peek()
{
    int val;
    if(front==-1)
        printf("queue is empty\n");
    else
    {
        val=queue[front];
        printf("element present at front is %d\n",val);
    }
}

void display()
{
    int i;
    i=front;
    while(i<=rear)
    {
        printf("%d\t",queue[i]);
        i++;
        printf("\n");
    }
}
