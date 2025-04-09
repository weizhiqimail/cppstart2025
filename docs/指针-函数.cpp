#include <stdio.h>

int main() {

    int x = 10;
    int *p = &x;
    printf("x = %d\n", x);
    printf("p = %X\n", p);
    printf("*p = %d\n", *p);
    *p = 20;
    printf("update------\n");
    printf("x = %d\n", x);
    printf("p = %X\n", p);
    printf("*p = %d\n", *p);
}