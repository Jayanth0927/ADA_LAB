#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char *exp) {
    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isalnum(c)) printf("%c", c);
        else if (c == '(') push(c);
        else if (c == ')') {
            while (peek() != '(') printf("%c", pop());
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
    }
    while (top != -1)
        printf("%c", pop());
    printf("\n");
}

int main() {
    char exp[MAX];
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}
