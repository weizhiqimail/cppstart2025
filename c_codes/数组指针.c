#include <stdio.h>

void pointerAndArray() {
  printf("====== pointerAndArray ======\n");

  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printf("arr: %p\n", (void *) arr);       /* 输出数组首地址 */
  printf("&arr: %p\n", (void *) &arr);     /* 输出数组的地址（和 arr 相同） */

  int *p = arr;
  printf("p: %p\n", (void *) p);           /* 指针 p 指向数组首元素 */
  printf("&p: %p\n", (void *) &p);         /* 指针 p 本身的地址 */

  for (int i = 0; i < 10; i++) {
    printf("arr[%d] == p[%d], arr[%d] = %d\n", i, i, i, arr[i]);
  }

  printf("====================\n");
}

void pointerAndChar() {
  printf("====== pointerAndChar ======\n");

  char s1[10] = "abcde";

  printf("s1: %s\n", s1);         // s1: abcde
  printf("&s1: %p\n", &s1);      // &s1:000000d5649ff8b6

  char *p = s1;
  printf("p: %p\n", p);           // p: 000000d5649ff8b6
  printf("&p: %p\n", &p);        // &p:000000d5649ff8a8

  printf("%d\n", sizeof(s1));         // 10
  printf("%d\n", sizeof(p));          // 8

  printf("====================\n");

}

int main() {
  pointerAndArray();
  pointerAndChar();
  return 0;
};