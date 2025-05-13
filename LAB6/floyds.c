#include<stdio.h>
int a[10][10],d[10][10],n;
void floyd(int [][10],int);
int min(int,int);
int main()
{
    printf("enter the no of vertices:\n");
    scanf("%d",&n);
    printf("enter cost adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    floyd(a,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void floyd(int a[][10],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            d[i][j] = a[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                d[i][j] = min(d[i][j],(d[i][k] + d[k][j]));
            }
        }
    }
}
int min(int a,int b)
{
    return (a<b ? a : b);
}
