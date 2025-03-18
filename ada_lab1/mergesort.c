#include<stdio.h>
#include<stdlib.h>
void merge(int *a,int l,int mid,int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a1[n1],a2[n2];
    for(int i=0;i<n1;i++)
    {
        a1[i] = a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        a2[j] = a[mid+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a1[i] < a2[j])
        {
            a[k] = a1[i];
            k++;i++;
        }
        else 
        {
            a[k] = a2[j];
            k++;j++;
        }
    }
    while(i<n1)
    {
        a[k] = a1[i];
        k++;i++;
    }
    while(j<n2)
    {
        a[k] = a2[j];
        k++;j++;
    }
}
void mergesort(int *a,int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int n;
    printf("enter n: \n");
    scanf("%d",&n);
    if(n==0) return 0;
    int a[n];
    printf("enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("array after sorting :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}