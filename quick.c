#include<stdio.h>
int partition(int [],int,int);
void quick_sort(int[],int,int);
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
quick_sort(arr,0,n-1);
printf("\n sorted array is\n");
for(i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
}

void quick_sort(int arr[],int beg,int end)
{
    int loc;
    if(beg<end)
    {
        loc=partition(arr,beg,end);
        quick_sort(arr,beg,loc-1);
        quick_sort(arr,loc+1,end);
    }
}

int partition(int arr[],int beg,int end)
{
    int left,right,loc,i,j,flag,temp;
    left=loc=beg;
    right=end;
    flag=0;
    while(flag!=1)
    {
        while(arr[right]>=arr[loc]&&loc!=right)
            right--;
        if(loc==right)
            flag=1;
        else if(arr[loc]>arr[right])
        {
            temp=arr[right];
            arr[right]=arr[loc];
            arr[loc]=temp;
            loc=right;
        }
        if(flag!=1)
        {
            while(arr[left]<=arr[loc]&&loc!=left)
                left++;
            if(loc==left)
                flag=1;
            else if(arr[loc]<arr[left])
            {
                temp=arr[left];
                arr[left]=arr[loc];
                arr[loc]=temp;
                loc=left;
            }
        }
    }
    return loc;
}
