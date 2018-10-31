#include<stdio.h>
void insertion(int [],int);
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
insertion(arr,n);
printf("\n sorted array is\n");
for(i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
}

void insertion(int arr[],int n)
{
   int i,j,temp;
   for(i=1;i<n;i++)
   {
       j=i-1;
       temp=arr[i];
       while(j>=0&&temp<arr[j])
       {
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=temp;
   }
}
