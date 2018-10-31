#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start,*p,*q,*r;

struct node *insert_beg(struct node*);
struct node *delete_last(struct node*);
struct node *count(struct node*);

void main()
{
    int option;
    start=NULL;
    do
    {
        printf("linklist operations......\n1:insert at begining\n2:delete last node\n3:count no of nodes\n4:exit\n");
        printf("enter your choice \n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:start=insert_beg(start);
                   break;
            case 2:start=delete_last(start);
                   break;
            case 3:start=count(start);
                   break;
           default:printf("invalid option\n");
                   break;
        }
    }while(option!=4);
}

struct node *insert_beg(struct node* start)
{
  int val;
  printf("enter the element to be inserted\n");
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
      q->next=start;
      start=q;
  }
  return start;
}

struct node *delete_last(struct node*start)
{
  int val;
  if(start==NULL)
    printf("list is empty\n");
  else
  {
      q=start;
      r=start->next;
      while(r->next!=NULL)
      {
          r=r->next;
          q=q->next;
      }
      val=r->data;
      q->next=NULL;
      free(r);
      printf("element deleted from list is %d\n",val);
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
