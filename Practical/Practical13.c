#include<stdio.h>
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void selectionSort(int arr[],int n)
{
    int i,j,index_min,temp;
    for(i=0;i<n-1;i++)
    {
        index_min=i;
        for(j=i+1;j<n;j++)
        {
          if(arr[j]<arr[index_min])
          index_min=j;
        }
        temp=arr[i];
        arr[i]=arr[index_min];
        arr[index_min]=temp;
    }
}
int main()
{
    int arr[]={45,23,32,4,78,64};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    printf("sorted array is:");
    print(arr,n);
}
