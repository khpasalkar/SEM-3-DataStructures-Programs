#include<stdio.h>
void interpolation_search(int [],int,int);
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
    interpolation_search(arr,n,val);
}

void interpolation_search(int arr[],int n,int val)
{
    int beg=0,end=n-1,mid,i;
    while(beg<=end)
    {
        mid=beg+(end-beg)*(val-arr[beg])/(arr[end]-arr[beg]);
        if(arr[mid]==val)
        {
            printf("element found at %d location\n",mid);
            break;
        }
        else if(arr[mid]>val)
        {
            end=mid-1;
        }
        else
            beg=mid+1;
    }
    if(beg>end)
        printf("element not found\n");
}

