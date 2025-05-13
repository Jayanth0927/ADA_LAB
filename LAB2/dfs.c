#include <stdio.h>

int adj[10][10], vis[10], n;

void dfs(int v) {
    vis[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !vis[i])
            dfs(i);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    dfs(0);
    return 0;
}
