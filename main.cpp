#include <iostream>

using namespace std;

int main() {
  char a = 'a';
  char b = 'b';
  char c = 'c';
  char d = 'd';

  char e = 'e';
  int a1 = 0x20;
  int a2 = 0x50;
  double a3 = 12.25;

  typedef struct User {
    double salary;
    int age;
    char name[20];
    char gender;
    char code[3];
  } User;

  User u1 = {
    10000,
    18,
    "ABC",
    'm',
    "M1",
  };
  printf("a = %c\n", a);
  printf("b = %c\n", b);
  printf("c = %c\n", c);
  printf("d = %c\n", d);
  printf("e = %c\n", e);
  printf("a1 = %d\n", a1);
  printf("a2 = %d\n", a2);
  printf("a3 = %f\n", a3);
  printf("u1.name = %s, gender = %c, code = %s, age = %d, salary = %f\n", u1.name,
         u1.gender, u1.code, u1.age, u1.salary);
  printf("sizeof(u1) = %llu\n", sizeof(u1));
  return 0;
}