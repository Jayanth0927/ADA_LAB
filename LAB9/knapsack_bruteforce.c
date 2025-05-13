#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int knapsack(int wt[], int val[], int n, int cap) {
    if (n == 0 || cap == 0) return 0;
    if (wt[n-1] > cap)
        return knapsack(wt, val, n-1, cap);
    return max(
        val[n-1] + knapsack(wt, val, n-1, cap - wt[n-1]),
        knapsack(wt, val, n-1, cap)
    );
}

int main() {
    int n, cap, wt[100], val[100];
    scanf("%d %d", &n, &cap);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &wt[i], &val[i]);
    printf("%d\n", knapsack(wt, val, n, cap));
    return 0;
}
