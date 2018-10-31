#include<stdio.h>
#define max 3
void push();
void pop();
void peek();
void display();
int stack[max];
int top=-1;

void main()
{
    int option;
    do
    {
     printf("stack operations....\n1:push\n2:pop\n3:peek\n4:display\n5:exit\n");
     printf("enter your choice\n");
     scanf("%d",&option);
     switch(option)
     {
         case 1:push();
                break;
         case 2:pop();
                break;
         case 3:peek();
                break;
         case 4:display();
                break;
        default:printf("invalid choice\n");
                break;
     }
    }while(option!=5);
}

void push()
{
    int val;
    printf("enter the element to push\n");
    scanf("%d",&val);
    if(top==max-1)
        printf("stack overflow\n");
    else
    {
        top++;
        stack[top]=val;
        printf("element is pushed\n");
    }
}

void pop()
{
    int val;
    if(top==-1)
        printf("stack underflow\n");
    else
    {
        val=stack[top];
        top--;
        printf("element poped from stack is %d\n",val);
    }
}

void peek()
{
    int val;
    if(top==-1)
        printf("stack is empty\n");
    else
    {
        val=stack[top];
        printf("element present at top is %d\n",val);
    }
}

void display()
{
    int i;
    i=top;
    while(i!=-1)
    {
        printf("%d\t",stack[i]);
        i--;
    }
    printf("\n");
}
