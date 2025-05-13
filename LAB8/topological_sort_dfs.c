#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;
int n;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
    stack[++top] = v;
}

void topoSortDFS() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    while (top >= 0)
        printf("%d ", stack[top--]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    topoSortDFS();
    return 0;
}
