#include <stdio.h>
#include <stdlib.h>
#include <time.h> // ���� srand �� rand

struct weapon {
    int price;
    int atk;
    struct weapon *next;
};

// �ͷ������ڴ�
void free_list(struct weapon *head) {
    struct weapon *p = head;
    while (p != NULL) {
        struct weapon *next = p->next;
        free(p);
        p = next;
    }
    printf("�����ڴ����ͷš�\n");
}

// ������̬�������� size ������Ϊ malloc ����Ĵ�С
struct weapon *create(int size, int node_count) {
    struct weapon *head = NULL, *p1, *p2 = NULL;
    int n = 0;

    // ��� size �Ƿ��㹻���� struct weapon
    if (size < sizeof(struct weapon)) {
        printf("���󣺷����С %d С�� struct weapon ���� %zu �ֽ�\n", size, sizeof(struct weapon));
        return NULL;
    }

    // ��ʼ�����������
    srand((unsigned) time(NULL));

    // ����ָ�������Ľڵ�
    for (int i = 0; i < node_count; i++) {
        p1 = (struct weapon *) malloc(size);
        if (!p1) {
            printf("�ڴ����ʧ�ܣ�\n");
            free_list(head); // �ͷ��ѷ���Ĳ���
            return NULL;
        }

        // ������� price �� atk����Χʾ����1-1000��
        p1->price = rand() % 1000 + 1; // 1 �� 1000
        p1->atk = rand() % 1000 + 1;

        if (n++ == 0) {
            head = p1; // ��һ���ڵ���Ϊͷ
        } else {
            p2->next = p1; // ���ӵ���һ���ڵ�
        }
        p2 = p1; // ������һ���ڵ�
    }

    // ��������β
    if (p2) {
        p2->next = NULL;
    }

    return head;
}

// ��ӡ��������
void print_list(struct weapon *head) {
    struct weapon *p = head;
    printf("��������:\n");
    while (p != NULL) {
        printf("Price: %d, ATK: %d\n", p->price, p->atk);
        p = p->next;
    }
}


int main() {
    struct weapon *p;
    int alloc_size = sizeof(struct weapon); // �����С
    int node_count = 5; // ���� 5 ���ڵ�

    printf("ʹ�÷����С: %d �ֽڣ����� %d ���ڵ�\n", alloc_size, node_count);
    p = create(alloc_size, node_count);
    if (p) {
        print_list(p);
        free_list(p);
    } else {
        printf("������ʧ�ܡ�\n");
    }

    return 0;
}
