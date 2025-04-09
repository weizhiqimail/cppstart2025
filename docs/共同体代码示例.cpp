#include <stdio.h>

void printSimpleUnion() {
    union data {
        int a;
        char b;
        double c; // 增加 double 测试对齐
    };

    printf("输出单个联合体的大小和对齐\n");
    union data d = {10}; // 仅初始化一个成员
    printf("a = %d\n", d.a); // 输出: 10

    d.b = 'x'; // 覆盖之前的 a
    printf("b = %c\n", d.b); // 输出: x
    printf("Size of union: %zu\n", sizeof(d)); // 输出: 8（因 double 对齐）
}

void printSimpleStruct() {
    struct Weapon {
        // 20 字节
        char name[20];
        // 4 字节
        int atk;
        // 4 字节
        int price;
        // 总大小：20 + 4 + 4 = 28。总大小 28 是 最大基本类型 int 4 字节的整数倍，所以直接对齐。
    };
}

int main() {
    printSimpleUnion();
    return 0;
}