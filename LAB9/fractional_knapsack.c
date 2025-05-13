#include <stdio.h>

struct Item {
    int weight;
    int value;
};

void sortItems(struct Item a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            float r1 = (float)a[j].value / a[j].weight;
            float r2 = (float)a[j+1].value / a[j+1].weight;
            if (r1 < r2) {
                struct Item t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
}

float fractionalKnapsack(struct Item a[], int n, int capacity) {
    sortItems(a, n);
    float total = 0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (a[i].weight <= capacity) {
            total += a[i].value;
            capacity -= a[i].weight;
        } else {
            total += a[i].value * ((float)capacity / a[i].weight);
            break;
        }
    }
    return total;
}

int main() {
    int n, cap;
    struct Item a[100];
    scanf("%d %d", &n, &cap);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].weight, &a[i].value);
    printf("%.2f\n", fractionalKnapsack(a, n, cap));
    return 0;
}
