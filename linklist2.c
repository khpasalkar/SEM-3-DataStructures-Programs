#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start1,*start2,*p,*q,*r;

struct node *copy(struct node*);
struct node *insert_end(struct node*);
struct node *count(struct node*);
struct node *start1=NULL;
struct node *start2=NULL;

void main()
{
    int option;
    do
    {
        printf("linklist operations......\n1:copy a list\n2:insert at the end\n3:count no of nodes\n4:exit\n");
        printf("enter your choice \n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:start1=copy(start1);
                   break;
            case 2:start1=insert_end(start1);
                   break;
            case 3:start1=count(start1);
                   break;
           default:printf("invalid option\n");
                   break;
        }
    }while(option!=4);
}

struct node *copy(struct node*start)
{
 p=start;
 while(p!=NULL)
 {
     r=(struct node*)malloc(sizeof(struct node));
     r->data=p->data;
     r->next=NULL;
     if(start2==NULL)
     {
         start2=r;
     }
     else
     {
         q=start2;
         while(q->next!=NULL)
            q=q->next;
         q->next=r;
     }
     p=p->next;
}
 printf("copied list is\n");
 r=start2;
 while(r!=NULL)
 {
     printf("%d\t",r->data);
     r=r->next;
 }
 printf("\n");
 return start;
}

struct node *insert_end(struct node*start)
{
  int val;
  printf("enter the value to be inserted\n");
  scanf("%d",&val);
  q=(struct node*)malloc(sizeof(struct node));
  q->data=val;
  q->next=NULL;
  if(start==NULL)
  {
      start=q;
  }
  else
  {
      p=start;
      while(p->next!=NULL)
      {
          p=p->next;
      }
      p->next=q;
  }
  return start;
}

struct node *count(struct node *start)
{
  int count=0;
  p=start;
  while(p!=NULL)
  {
      p=p->next;
      count++;
  }
  printf("no of nodes are %d\n",count);
  return start;
}
