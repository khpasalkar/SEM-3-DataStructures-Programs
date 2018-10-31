#include<stdio.h>
void radix(int [],int);
void main()
{
int i,n,arr[50];
printf("enter the size of array\n");
scanf("%d",&n);
printf("enter the elements of array\n");
for(i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
printf("unsorted array is\n");
for(i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
radix(arr,n);
printf("\n sorted array is\n");
for(i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
}

void radix(int arr[],int n)
{
    int i,j,bucket_count[10],bucket[10][10],remainder,pass,nop,large,div=1,k=0;
    large=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
        }
    }
    nop=0;
    while(large>0)
    {
        nop++;
        large=large/10;
    }
    for(pass=0;pass<nop;pass++)
    {
       for(i=0;i<10;i++)
       {
           bucket_count[i]=0;
       }
       for(i=0;i<n;i++)
       {
           remainder=(arr[i]/div)%10;
           bucket[remainder][bucket_count[remainder]]=arr[i];
           bucket_count[remainder]+=1;
       }
       i=0;
       for(k=0;k<10;k++)
       {
           for(j=0;j<bucket_count[k];j++)
           {
               arr[i]=bucket[k][j];
               i++;
           }
       }
       div*=10;
    }
}
