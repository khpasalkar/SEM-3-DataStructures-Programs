#include<stdio.h>
#include<string.h>
#include<process.h>
#define max 100

float stack[max];
int top=-1;

void push(float [],float);
float pop(float[]);
float evaluation(char[]);

void main()
{
    float val;
    char postfix[max];
    printf("enter any postfix expression\n");
    gets(postfix);
    val=evaluation(postfix);
    printf("evaluation is %f\n",val);
}

float evaluation(char postfix[])
{
    int i=0;
    float p1,p2,p;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        {
            push(stack,(float)(postfix[i]-'0'));
            i++;
        }
        else
        {
            p2=pop(stack);
            p1=pop(stack);
            switch(postfix[i])
            {
                case '+':p=p1+p2;
                         break;
                case '-':p=p1-p2;
                         break;
                case '*':p=p1*p2;
                         break;
                case '/':p=p1/p2;
                         break;
                case '%':p=(int)p1%(int)p2;
            }
            push(stack,p);
            i++;
        }
    }
    return (pop(stack));
}

void push(float stack[],float val)
{
    if(top==max-1)
        printf("stack overflow\n");
    else
    {
        top++;
        stack[top]=val;
    }
}

float pop(float stack[])
{
    float val;
    if(top==-1)
        printf("stack underflow\n");
    else
    {
        val=stack[top];
        top--;
    }
    return val;
}
