#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root,*t,*p,*q,*r;

struct node* insert(struct node*);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);

void main()
{
    int option;
    root=NULL;
    do
    {
        printf("binary search tree operations.....\n1:insert\n2:preorder\n3:inorder\n4:postorder\n5:exit\n");
        printf("enter your option\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:root=insert(root);
                   break;
            case 2:{
                   preorder(root);
                   printf("\n");
                   break;
                  }
            case 3:{
                   inorder(root);
                   printf("\n");
                   break;
                   }
            case 4:{
                   postorder(root);
                   printf("\n");
                   break;
                   }
           default:printf("invalid choice\n");
        }
    }while(option!=5);
}

struct node *insert(struct node *root)
{
    int val;
    printf("enter the element to be inserted\n");
    scanf("%d",&val);
    q=(struct node*)malloc(sizeof(struct node));
    q->data=val;
    q->left=NULL;
    q->right=NULL;
    t=root;
    if(t==NULL)
    {
        root=t=q;
        printf("element inserted\n");
    }
    else
    {
        r=NULL;
        p=root;
        while(p!=NULL&&p->data!=val)
        {
            r=p;
            if(val>p->data)
                p=p->right;
            else
                p=p->left;
        }
        if(p==NULL)
        {
            if(r->data>val)
                r->left=q;
            else
                r->right=q;
            printf("element inserted\n");
        }
        else
        {
            printf("duplicate insertion\n");
        }
    }
    return root;

}

void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d\t",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d\t",p->data);
        inorder(p->right);
    }
}


void postorder(struct node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\t",p->data);
    }
}
