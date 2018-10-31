#include<stdio.h>
#include<string.h>
#include <process.h>
#define max 50

void push(char[],char);
char pop(char[]);
int get_priority(char);
void infix_postfix(char[],char[]);

char stack[max];
int top=-1;

void main()
{
    char infix[100],postfix[100];
    printf("enter the infix expression\n");
    gets(infix);
    strcpy(postfix,"");
    infix_postfix(infix,postfix);
    printf("postfix expression is\n");
    puts(postfix);
}

void infix_postfix(char source[],char target[])
{
    int i=0,j=0;
    char temp;
    strcpy(target,"");
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(stack,source[i]);
            i++;
        }
        else if(source[i]==')')
        {
            while(top!=-1&&stack[top]!='(')
            {
                target[j]=pop(stack);
                j++;
            }
            if(top==-1)
                printf("invalid expression\n");
            temp=pop(stack);
            i++;
        }
        else if((isdigit(source[i]))||(isalpha(source[i])))
                 {
                     target[j]=source[i];
                     j++;
                     i++;
                 }
       else if(source[i]=='+'||source[i]=='-'||source[i]=='/'||source[i]=='*'||source[i]=='%')
       {
           while(top!=-1&&stack[top]!='('&&get_priority(stack[top])>get_priority(source[i]))
           {
               target[j]=pop(stack);
               j++;
           }
           push(stack,source[i]);
           i++;
       }
       else
       {
           printf("invalid expression\n");
       }
    }
    while(top!=-1&&stack[top]!='(')
    {
        target[j]=pop(stack);
        j++;
    }
    target[j]='\0';
}

int get_priority(char op)
{
    if(op=='*'||op=='/'||op=='%')
        return 1;
    else
        return 0;
}

void push(char stack[],char op)
{
    if(top==max-1)
        printf("stack overflow\n");
    else
    {
        top++;
        stack[top]=op;
    }
}

char pop(char stack[])
{
    char val;
    if(top==-1)
        printf("stack under flow\n");
    else
    {
      val=stack[top];
      top--;
    }
    return val;
}
