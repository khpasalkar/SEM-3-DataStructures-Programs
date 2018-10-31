#include<stdio.h>
void index_sequential_search(int [],int,int);
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
    index_sequential_search(arr,n,val);
}

void index_sequential_search(int arr[],int n,int val)
{
    int kin[20],pin[20],n1=0,i,end,beg,found=0;
    for(i=0;i<n;i+=3)
    {
        kin[n1]=arr[i];
        pin[n1]=i;
        n1++;
    }

    if(val<kin[0])
    {
        printf("element not present\n");
    }
    else
    {
        for(i=1;i<n1;i++)
        {
            if(kin[i]>val)
            {
                beg=pin[i-1];
                end=pin[i];
            }
        }
        for(i=beg;i<=end;i++)
        {
            if(arr[i]==val)
            {
                found=1;
                break;
            }
        }
        if(found==1)
        {
            printf("element found at %d location\n",i);
        }
    }

}

