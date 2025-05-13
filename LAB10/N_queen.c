#include <stdio.h>

int board[20][20];
int n, count = 0;

int isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j]) return 0;

    return 1;
}

void printBoard() {
    printf("Solution %d:\n", ++count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(board[i][j] ? "Q " : ". ");
        printf("\n");
    }
    printf("\n");
}

void solve(int col) {
    if (col == n) {
        printBoard();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    solve(0);
    if (count == 0)
        printf("No solution\n");
    return 0;
}
