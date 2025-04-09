#include <stdio.h>
#include <iostream>

using namespace std;

// struct �ṹ��
void structWeaponFn() {
    struct Weapon {
        char name[20];
        int atk;
        int price;
    };

    struct Weapon weapon = {"ak47", 100, 200};
    printf("structWeaponFn ���ʵ��� weapon �ṹ��ĳ�Ա\n");
    printf("weapon.name = %s\n", weapon.name);
    printf("weapon.atk = %d\n", weapon.atk);
    printf("weapon.price = %d\n", weapon.price);
    printf("weapon.price++\n");
    printf("weapon.price = %d\n", weapon.price);
    printf("\n");

    struct Weapon weapons[2] = {
        {"AK47", 100, 200},
        {"AK48", 70, 120}
    };

    printf("structWeaponFn ���� weapons ����ṹ��ĳ�Ա\n");
    for (int i = 0; i < 2; i++) {
        printf("Weapon[%d]: %s, ATK: %d, Price: %d\n",
               i, weapons[i].name, weapons[i].atk, weapons[i].price);
    }

    printf("\n");
}

// typedef ����ṹ������
void typedefWeaponFn() {
    typedef struct {
        char name[20];
        int atk;
        int price;
    } Weapon;
    Weapon weapon = {"AK47", 100, 200};
    printf("typedefWeaponFn ���� weapon �ṹ��ĳ�Ա\n");
    printf("weapon.name = %s\n", weapon.name);
    printf("weapon.atk = %d\n", weapon.atk);
    printf("weapon.price = %d\n", weapon.price);
    printf("weapon.price++\n");
    printf("weapon.price = %d\n", weapon.price);
    printf("\n");
}

// ָ����ʽṹ��
void structWeaponPointerFn() {
    struct weapon {
        char name[20];
        int atk;
        int price;
    };

    printf("structWeaponPointerFn ͨ��ָ��ȡֵ\n");

    // w1 ����һ���ṹ�������&w1 ����һ���ṹ������ĵ�ַ
    struct weapon w1 = {"AK47", 100, 200};
    printf("w1 �ĵ�ַ: %p\n", &w1);

    // ָ����� p ָ��ṹ����� w1 �ĵ�ַ
    // ���Ҫָ�� w2����Ҫ p = &w2;
    struct weapon *p = &w1;
    printf("*p �ĵ�ַ: %p\n", p);

    printf("ͨ��ָ��ȡֵ p->name = %s\n", p->name); // ��ͷ�����
    printf("ͨ������ȡֵ (*p).name = %s\n", (*p).name); // �������

    struct weapon arr[2] = {{"AK47", 100, 200}, {"AK48", 70, 120}};
    p = arr;
    printf("Arr[0]: %s\n", p->name);
    // p++ �ƶ����ֽ������� sizeof(struct weapon)��������ָ��Ĳ������ԡ�
    p++; // �ƶ�����һ���ṹ��
    printf("�ƶ�����һ���ṹ�� p++\n");
    printf("Arr[1]: %s\n", p->name);
}

int main() {
    structWeaponFn();
    typedefWeaponFn();
    structWeaponPointerFn();
    return 0;
}
