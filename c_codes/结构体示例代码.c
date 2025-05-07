#include <stdio.h>
#include <string.h>

// struct 结构体
void structWeaponFn() {
  struct Weapon {
    char name[20];
    int atk;
    int price;
  };

  struct Weapon weapon = {"ak47", 100, 200};
  printf("structWeaponFn 访问单个 weapon 结构体的成员\n");
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

  printf("structWeaponFn 访问 weapons 数组结构体的成员\n");
  for (int i = 0; i < 2; i++) {
    printf("Weapon[%d]: %s, ATK: %d, Price: %d\n",
           i, weapons[i].name, weapons[i].atk, weapons[i].price);
  }

  printf("\n");
}

// typedef 定义结构体类型
void typedefWeaponFn() {
  typedef struct {
    char name[20];
    int atk;
    int price;
  } Weapon;

  Weapon weapon = {"AK47", 100, 200};
  printf("typedefWeaponFn 访问 weapon 结构体的成员\n");
  printf("weapon.name = %s\n", weapon.name);
  printf("weapon.atk = %d\n", weapon.atk);
  printf("weapon.price = %d\n", weapon.price);
  printf("weapon.price++\n");
  weapon.price++;
  printf("weapon.price = %d\n", weapon.price);
  printf("\n");
}

// 指针访问结构体
void structWeaponPointerFn() {
  struct weapon {
    char name[20];
    int atk;
    int price;
  };

  printf("structWeaponPointerFn 通过指针取值\n");

  struct weapon w1 = {"AK47", 100, 200};
  printf("w1 的地址: %p\n", (void*)&w1);

  struct weapon *p = &w1;
  printf("*p 的地址: %p\n", (void*)p);

  printf("通过指针取值 p->name = %s\n", p->name);
  printf("通过引用取值 (*p).name = %s\n", (*p).name);

  struct weapon arr[2] = {
      {"AK47", 100, 200},
      {"AK48", 70, 120}
  };
  p = arr;
  printf("Arr[0]: %s\n", p->name);
  p++;
  printf("移动到下一个结构体 p++\n");
  printf("Arr[1]: %s\n", p->name);
}

int main() {
  structWeaponFn();
  typedefWeaponFn();
  structWeaponPointerFn();
  return 0;
}
