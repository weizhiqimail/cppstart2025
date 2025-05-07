#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 用于 srand 和 rand

struct weapon {
    int price;
    int atk;
    struct weapon *next;
};

// 释放链表内存
void free_list(struct weapon *head) {
    struct weapon *p = head;
    while (p != NULL) {
        struct weapon *next = p->next;
        free(p);
        p = next;
    }
    printf("链表内存已释放。\n");
}

// 创建动态链表，接受 size 参数作为 malloc 分配的大小
struct weapon *create(int size, int node_count) {
    struct weapon *head = NULL, *p1, *p2 = NULL;
    int n = 0;

    // 检查 size 是否足够容纳 struct weapon
    if (size < sizeof(struct weapon)) {
        printf("错误：分配大小 %d 小于 struct weapon 所需 %zu 字节\n", size, sizeof(struct weapon));
        return NULL;
    }

    // 初始化随机数种子
    srand((unsigned) time(NULL));

    // 创建指定数量的节点
    for (int i = 0; i < node_count; i++) {
        p1 = (struct weapon *) malloc(size);
        if (!p1) {
            printf("内存分配失败！\n");
            free_list(head); // 释放已分配的部分
            return NULL;
        }

        // 随机生成 price 和 atk（范围示例：1-1000）
        p1->price = rand() % 1000 + 1; // 1 到 1000
        p1->atk = rand() % 1000 + 1;

        if (n++ == 0) {
            head = p1; // 第一个节点作为头
        } else {
            p2->next = p1; // 链接到上一个节点
        }
        p2 = p1; // 更新上一个节点
    }

    // 设置链表尾
    if (p2) {
        p2->next = NULL;
    }

    return head;
}

// 打印链表内容
void print_list(struct weapon *head) {
    struct weapon *p = head;
    printf("链表内容:\n");
    while (p != NULL) {
        printf("Price: %d, ATK: %d\n", p->price, p->atk);
        p = p->next;
    }
}


int main() {
    struct weapon *p;
    int alloc_size = sizeof(struct weapon); // 分配大小
    int node_count = 5; // 生成 5 个节点

    printf("使用分配大小: %d 字节，生成 %d 个节点\n", alloc_size, node_count);
    p = create(alloc_size, node_count);
    if (p) {
        print_list(p);
        free_list(p);
    } else {
        printf("链表创建失败。\n");
    }

    return 0;
}
