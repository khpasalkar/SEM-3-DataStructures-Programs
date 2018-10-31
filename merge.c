#include<stdio.h>
void merge(int [],int,int,int);
void merge_sort(int[],int,int);
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
merge_sort(arr,0,n-1);
printf("\n sorted array is\n");
for(i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
}

void merge_sort(int arr[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

void merge(int arr[],int beg,int mid,int end)
{
    int i,j,index,temp[20],k;
    i=beg;
    j=mid+1;
    index=beg;
    while(i<=mid&&j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[index]=arr[i];
            i++;
        }
        else
        {
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
             temp[index]=arr[j];
             index++;
             j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=arr[i];
            index++;
            i++;
        }
    }
    for(k=beg;k<index;k++)
    {
        arr[k]=temp[k];
    }
}
