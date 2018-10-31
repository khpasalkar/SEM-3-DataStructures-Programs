#include<stdio.h>
void shell(int [],int);
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
shell(arr,n);
printf("\n sorted array is\n");
for(i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
}

void shell(int arr[],int n)
{
    int gap_size,temp,i,flag=1;
    gap_size=n;
    while(gap_size>1||flag==1)
    {
        flag=0;
        gap_size=(gap_size+1)/2;
        for(i=0;i<(n-gap_size);i++)
        {
            if(arr[i]>arr[i+gap_size])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=1;
            }

        }
    }
}

