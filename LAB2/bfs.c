#include <stdio.h>

int adj[10][10], vis[10], queue[100], front = 0, rear = 0, n;

void bfs(int start) {
    vis[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !vis[v]) {
                vis[v] = 1;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    bfs(0);
    return 0;
}
