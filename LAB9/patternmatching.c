#include <stdio.h>
#include <string.h>

void patternMatch(char *text, char *pat) {
    int n = strlen(text), m = strlen(pat);
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pat[j])
            j++;
        if (j == m)
            printf("Found at index %d\n", i);
    }
}

int main() {
    char text[100], pat[100];
    scanf("%s %s", text, pat);
    patternMatch(text, pat);
    return 0;
}
