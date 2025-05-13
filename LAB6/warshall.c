#include<stdio.h>
int n;
int a[10][10];
int p[10][10];
void write()
{
    printf("path matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}
void read_data()
{
    int i,j;
    printf("enter the no of nodes:\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void path_matrix()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            p[i][j] = a[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(p[i][k] && p[k][j])
                {
                    p[i][j] = 1;
                }
            }
        }
    }
}
void main()
{
    read_data();
    path_matrix();
    write();
    getch();
}