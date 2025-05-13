#include <stdio.h>

int n, g[10][10], vis[10], minCost = 1e9;

void tsp(int start, int count, int cost, int origin) {
    if (count == n && g[start][origin]) {
        if (cost + g[start][origin] < minCost)
            minCost = cost + g[start][origin];
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i] && g[start][i]) {
            vis[i] = 1;
            tsp(i, count + 1, cost + g[start][i], origin);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    vis[0] = 1;
    tsp(0, 1, 0, 0);
    printf("%d\n", minCost);
    return 0;
}
