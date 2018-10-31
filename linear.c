#include<stdio.h>
void linear_search(int [],int,int);
void main()
{
    int arr[50],n,val,i;
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the elements of array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to search\n");
    scanf("%d",&val);
    linear_search(arr,n,val);
}

void linear_search(int arr[],int n,int val)
{
    int i,found=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==val)
        {
            found=1;
            break;
        }
    }
    if(found==1)
        printf("element found at %d location\n",i);
    else
        printf("element not found\n");
}
