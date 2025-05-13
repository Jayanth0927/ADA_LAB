#include <stdio.h>
#define MAX 100

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, W, w[MAX], p[MAX], dp[MAX][MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    printf("Enter weights of items:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter profits of items:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], p[i] + dp[i - 1][j - w[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("Maximum profit: %d\n", dp[n][W]);
    return 0;
}
// Enter number of items: 3
// Enter knapsack capacity: 5
// Enter weights of items:
// 1 3 4
// Enter profits of items:
// 15 20 30
