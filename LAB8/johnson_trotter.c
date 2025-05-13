#include <stdio.h>

#define MAX 10
#define LEFT 0
#define RIGHT 1

int a[MAX], dir[MAX], n;

void printPerm() {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int getMobileIndex() {
    int mobile = 0, idx = -1;
    for (int i = 0; i < n; i++) {
        int d = dir[i] == LEFT ? -1 : 1;
        int next = i + d;
        if (next >= 0 && next < n && a[i] > a[next] && a[i] > mobile) {
            mobile = a[i];
            idx = i;
        }
    }
    return idx;
}

void swap(int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t;
    t = dir[i]; dir[i] = dir[j]; dir[j] = t;
}

void reverseDir(int mobileVal) {
    for (int i = 0; i < n; i++)
        if (a[i] > mobileVal)
            dir[i] = !dir[i];
}

void johnsonTrotter() {
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    while (1) {
        printPerm();
        int m = getMobileIndex();
        if (m == -1)
            break;

        int d = dir[m] == LEFT ? -1 : 1;
        swap(m, m + d);
        reverseDir(a[m + d]);
    }
}

int main() {
    scanf("%d", &n);
    johnsonTrotter();
    return 0;
}
