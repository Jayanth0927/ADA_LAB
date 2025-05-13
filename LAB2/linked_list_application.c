#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, pow;
    struct Node *next;
};

struct Node* create(int c, int p) {
    struct Node *t = malloc(sizeof(struct Node));
    t->coeff = c;
    t->pow = p;
    t->next = NULL;
    return t;
}

void insertEnd(struct Node **head, int c, int p) {
    struct Node *newNode = create(c, p);
    if (!*head) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

struct Node* addPoly(struct Node *a, struct Node *b) {
    struct Node *res = NULL;
    while (a && b) {
        if (a->pow == b->pow) {
            insertEnd(&res, a->coeff + b->coeff, a->pow);
            a = a->next; b = b->next;
        } else if (a->pow > b->pow) {
            insertEnd(&res, a->coeff, a->pow);
            a = a->next;
        } else {
            insertEnd(&res, b->coeff, b->pow);
            b = b->next;
        }
    }
    while (a) { insertEnd(&res, a->coeff, a->pow); a = a->next; }
    while (b) { insertEnd(&res, b->coeff, b->pow); b = b->next; }
    return res;
}

void print(struct Node *head) {
    while (head) {
        printf("%dx^%d ", head->coeff, head->pow);
        head = head->next;
        if (head) printf("+ ");
    }
    printf("\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL;
    int n, c, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d %d", &c, &p); insertEnd(&p1, c, p); }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d %d", &c, &p); insertEnd(&p2, c, p); }
    struct Node *res = addPoly(p1, p2);
    print(res);
    return 0;
}
