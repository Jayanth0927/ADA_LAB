#include <stdio.h>
#define INF 999

int cost[10][10], n, sum = 0, t[10][2];

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void kruskal() 
{
    int parent[10], u, v, min, count = 0, k = 0;
    
    for (int i = 0; i < n; i++) 
    {
        parent[i] = i;
    }
    
    while (count < n - 1)
     {
        min = INF;
        u = v = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && find(parent, i) != find(parent, j) && cost[i][j] < min)
                 {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        
        if (u == -1 || v == -1)
            return;
        
        parent[find(parent, u)] = find(parent, v);
        t[k][0] = u;
        t[k][1] = v;
        sum += min;
        k++;
        count++;
    }
}

int main() {
    printf("Enter number of vertices: ");
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
    
    kruskal();
    
    if (sum == 0) 
    {
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
