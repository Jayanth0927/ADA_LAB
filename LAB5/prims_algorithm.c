#include <stdio.h>
#define INF 999

int cost[10][10], n, sum = 0, t[10][2];

void prims()
{
    int d[10], p[10], s[10] = {0};
    int i, j, u, v, min, k = 0;
    
   
    for (i = 0; i < n; i++)
    {
        d[i] = cost[0][i];
        p[i] = 0;
    }
    s[0] = 1;
    
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        u = -1;
        
       
        for (j = 0; j < n; j++)
        {
            if (!s[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        
        if (u == -1)  
            return;
        
       
        t[k][0] = u;
        t[k][1] = p[u];
        
        
        if (cost[u][p[u]] != INF) 
            sum += cost[u][p[u]];
        
        s[u] = 1;
        k++;
        
       
        for (v = 0; v < n; v++)
        {
            if (!s[v] && cost[u][v] < d[v] && cost[u][v] != INF) 
            {
                d[v] = cost[u][v];
                p[v] = u;
            }
        }
    }
}

int main() {
    printf("Enter number of vertices:\n");
    scanf("%d", &n);
    
    printf("Enter cost adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)  
                cost[i][j] = INF;
        }
    }
    
    prims();

   
    if (sum == 0) {
        printf("Graph is disconnected. MST cannot be formed.\n");
    } else {
        printf("Edges in MST:\n");
        for (int i = 0; i < n - 1; i++)
        {
            printf("(%d, %d)\n", t[i][0], t[i][1]);
        }
        printf("Total cost: %d\n", sum);
    }
    
    return 0;
}
