#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], indegree[MAX], queue[MAX];
int n;

void computeIndegree() {
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j])
                indegree[j]++;
}

void kahnTopoSort() {
    int front = 0, rear = 0;

    computeIndegree();

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
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

    kahnTopoSort();
    return 0;
}
