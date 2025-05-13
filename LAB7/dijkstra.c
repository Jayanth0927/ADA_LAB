#include<stdio.h>
#define INF 999
#define MAX 20
int main()
{
    int n,v,c[MAX][MAX],d[MAX],s[MAX],u,min;
    printf("enter number of vertices:");
    scanf("%d",&n);
    printf("enter cost adjacency matrix (999) for no edge:) \n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    printf("enter source vertex:");
    scanf("%d",&v);
    for(int i=1;i<=n;i++)
    {
        s[i] = 0;
        d[i] = c[v][i];
    }
    d[v] = 0; s[v] = 1;\
    for(int k=2;k<=n;k++)
    {
        min = INF;
        for(int i=1;i<=n;i++)
        {
            if(!s[i] && d[i]<min)
            {
                min = d[i];
                u = i;
            }
        }   
        s[u] = 1;
        for(int i=1;i<=n;i++)
        {
            if(!s[i] && d[i] > d[u]+c[u][i])
             {
                 d[i] = d[u] + c[u][i];
             }
        }
        
    }
    printf("the shortes distance from vertex %d : \n",v);
    for(int i=1;i<=n;i++)
    {
        printf("%d-->%d = %d\n",v,i,d[i]);
    }
    return 0;
}