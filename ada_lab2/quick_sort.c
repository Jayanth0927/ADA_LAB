#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int x,int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
int partition(int *a,int l,int r)
{
    int pivot = a[r];
    int i = l-1;
    for(int j = l;j<r;j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,r);
    return i+1;
}
void QuickSort(int *a,int l,int r)
{
    if(l<r)
    {
        int pi = partition(a,l,r);
        QuickSort(a,l,pi-1);
        QuickSort(a,pi+1,r);
    }
}
int main()
{
    int n;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    if(n == 0)
    {
        printf("invalid array");
        return 0;
    }
    int start = clock();
    int *a = (int*)malloc(n*sizeof(int));
    printf("enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    QuickSort(a,0,n-1);
    int end = clock();
    printf("array after sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("time taken = %d",end-start);
    free(a);
    return 0;
}