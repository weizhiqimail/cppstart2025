#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 将整数格式化为带空格的32位二进制字符串
void formatBitset(uint32_t num, char *output) {
  for (int i = 31; i >= 0; --i) {
    output[31 - i + (31 - i) / 4] = (num & (1U << i)) ? '1' : '0';
    if (i % 4 == 0 && i != 0) {
      output[31 - i + (31 - i) / 4 + 1] = ' ';
    }
  }
  output[39] = '\0'; // 包括空格，一共是 39 个字符
}

void printArray(const char *arrName, int *arr, size_t size, int showAddress) {
  printf("===== 一维数组元素 (%s) 输出 =====\n", arrName);
  for (size_t i = 0; i < size; i++) {
    printf("%s[%zu] = %d", arrName, i, arr[i]);
    if (showAddress) {
      uintptr_t addr = (uintptr_t)&arr[i];
      char bitstr[40];
      formatBitset((uint32_t)addr, bitstr);
      printf("\t(%p)\t%s", (void*)addr, bitstr);
    }
    printf("\n");
  }
  printf("\n");
}

void print2DArray(const char *arrName, int arr[][4], size_t rows, size_t cols, int showAddress) {
  printf("===== 二维数组元素 (%s) 输出 =====\n", arrName);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      printf("%s[%zu][%zu] = %d", arrName, i, j, arr[i][j]);
      if (showAddress) {
        uintptr_t addr = (uintptr_t)&arr[i][j];
        char bitstr[40];
        formatBitset((uint32_t)addr, bitstr);
        printf("\t(%p)\t%s", (void*)addr, bitstr);
      }
      printf("\n");
    }
  }
  printf("\n");
}

void printText(const char *text) {
  printf("===== %s =====\n", text);
}

int main() {
  int c[10] = {1};
  printText("初始化一维数组 c[10]，所有元素为 0；只指定第一个元素为 1，其余元素自动填充为 0");
  printArray("c", c, 10, 1);
  printf("c: %p\n", (void*)c);
  printf("&c: %p\n", (void*)&c);

  int c1[3][4] = {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
  };
  printText("初始化二维数组 c1[3][4]，所有元素为 0；使用嵌套初始化列表显式指定每个元素");
  print2DArray("c1", c1, 3, 4, 1);

  int c2[3][4] = {1, 2, 3, 4};
  printText("初始化二维数组 c2[3][4]，仅提供部分元素；{1, 2, 3, 4} 会按行填充 c2[0][0] 到 c2[0][3]，其余元素自动为 0");
  print2DArray("c2", c2, 3, 4, 1);

  int a[] = {1,2,3,4,5,6,7,8,9,10};
  printText("初始化一维数组 a[]，编译器根据初始化列表推断大小为 10");
  printf("%p\n", (void*)&a);

  int b[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  printf("%lu\n", sizeof(b)); // 字节数

  char c_array[] = {'a','b','c','d','e'};
  printf("%lu\n", sizeof(c_array)); // 5 字节

  int d[10];
  for (int i = 0; i < 10; i++) {
    printf("d[%d] = %d\n", i, d[i]); // 未初始化，值不确定
  }

  printf("d = %p\n", (void *)d);
  printf("&d[0] = %p\n", (void *)&d[0]);
  printf("&d[1] = %p\n", (void *)&d[1]);
  printf("&d[2] = %p\n", (void *)&d[2]);
  printf("&d[3] = %p\n", (void *)&d[3]);
  printf("&d[4] = %p\n", (void *)&d[4]);

  return 0;
}
