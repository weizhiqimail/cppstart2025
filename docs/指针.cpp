#include <stdio.h>

int main () {
    int a = 100;
    int *p = &a;

    printf("%d\n", p);
    printf("%d\n", p + 1);

    char b = 'a';
    char *q = &b;
    printf("%d\n", q);
    printf("%d\n", q + 1);
    return 0;
}