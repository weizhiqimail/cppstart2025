#include <stdio.h>

void fun() {
    int i = 0;
    i++;
    printf("fun i = %d\n", i);
}

void staticFun() {
    static int i = 0;
    i++;
    printf("staticFun i = %d\n", i);
}

int main() {
    staticFun();
    staticFun();
    staticFun();
    fun();
    fun();
    fun();
    return 0;
}