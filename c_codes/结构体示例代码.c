#include <stdio.h>
#include <string.h>

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
  weapon.price++;
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
  weapon.price++;
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

  struct weapon w1 = {"AK47", 100, 200};
  printf("w1 �ĵ�ַ: %p\n", (void*)&w1);

  struct weapon *p = &w1;
  printf("*p �ĵ�ַ: %p\n", (void*)p);

  printf("ͨ��ָ��ȡֵ p->name = %s\n", p->name);
  printf("ͨ������ȡֵ (*p).name = %s\n", (*p).name);

  struct weapon arr[2] = {
      {"AK47", 100, 200},
      {"AK48", 70, 120}
  };
  p = arr;
  printf("Arr[0]: %s\n", p->name);
  p++;
  printf("�ƶ�����һ���ṹ�� p++\n");
  printf("Arr[1]: %s\n", p->name);
}

int main() {
  structWeaponFn();
  typedefWeaponFn();
  structWeaponPointerFn();
  return 0;
}
