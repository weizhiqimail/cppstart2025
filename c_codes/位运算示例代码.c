#include <stdio.h>
#include <stdint.h>

// 输出32位二进制，带每4位分隔
void print_binary_32(uint32_t val) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (val >> i) & 1);
    if (i % 4 == 0 && i != 0) printf(" ");
  }
}

// 输出16位二进制，带每4位分隔
void print_binary_16(uint16_t val) {
  for (int i = 15; i >= 0; i--) {
    printf("%d", (val >> i) & 1);
    if (i % 4 == 0 && i != 0) printf(" ");
  }
}

// 按位与操作
void bitwise_and_fn() {
  printf("====== 按位与操作 ======\n");

  uint32_t a = 0x12345678;
  uint32_t maskInt = 0xFFFFFF00;
  uint32_t resultInt = a & maskInt;

  uint16_t s = 0x12FF;
  uint16_t maskShort = 0xFF00;
  uint16_t resultShort = s & maskShort;

  // int 类型
  printf("===== int 类型与运算 =====\n");
  printf("原始 a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("掩码 maskInt  = 0x%08X (", maskInt); print_binary_32(maskInt); printf(")\n");
  printf("结果 result   = 0x%08X (", resultInt); print_binary_32(resultInt); printf(")\n");

  // short 类型
  printf("\n===== short 类型与运算 =====\n");
  printf("原始 s        = 0x%04X (", s); print_binary_16(s); printf(")\n");
  printf("掩码 maskShort= 0x%04X (", maskShort); print_binary_16(maskShort); printf(")\n");
  printf("结果 result   = 0x%04X (", resultShort); print_binary_16(resultShort); printf(")\n");
}

// 按位或操作
void bitwise_or_fn() {
  printf("\n====== 按位或操作 (|) ======\n");
  uint32_t a = 0x0F0F0F0F;
  uint32_t b = 0x33333333;
  uint32_t result = a | b;

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("b        = 0x%08X (", b); print_binary_32(b); printf(")\n");
  printf("a | b    = 0x%08X (", result); print_binary_32(result); printf(")\n");
}

// 按位异或操作
void bitwise_xor_fn() {
  printf("\n====== 按位异或操作 (^) ======\n");
  uint32_t a = 0xAAAA5555;
  uint32_t b = 0xFFFF0000;
  uint32_t result = a ^ b;

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("b        = 0x%08X (", b); print_binary_32(b); printf(")\n");
  printf("a ^ b    = 0x%08X (", result); print_binary_32(result); printf(")\n");
}

// 按位取反操作
void bitwise_not_fn() {
  printf("\n====== 按位取反操作 (~) ======\n");
  uint32_t a = 0x0F0F0F0F;
  uint32_t result = ~a;

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("~a       = 0x%08X (", result); print_binary_32(result); printf(")\n");
}

// 左移操作
void left_shift_fn() {
  printf("\n====== 左移操作 (<<) ======\n");
  uint32_t a = 0x0000000F;
  int shift = 4;
  uint32_t result = a << shift;

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("a << %d   = 0x%08X (", shift, result); print_binary_32(result); printf(")\n");

  printf("\n====== 左移操作，移位 35 位（超范围）======\n");
  int shift_large = 35;
  result = a << (shift_large % 32);  // 避免未定义行为

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("a << %d  = 0x%08X (", shift_large, result); print_binary_32(result); printf(")\n");
}

// 右移操作
void right_shift_fn() {
  printf("\n====== 右移操作 (>>) ======\n");
  int32_t a = 0xF0000000;
  int shift = 4;
  int32_t result = a >> shift;

  printf("a        = 0x%08X (", a); print_binary_32((uint32_t)a); printf(")\n");
  printf("a >> %d  = 0x%08X (", shift, (uint32_t)result); print_binary_32((uint32_t)result); printf(")\n");

  printf("\n====== 右移操作，移位 35 位（超范围）======\n");
  int shift_large = 35;
  result = a >> (shift_large % 32);

  printf("a        = 0x%08X (", a); print_binary_32((uint32_t)a); printf(")\n");
  printf("a >> %d  = 0x%08X (", shift_large, (uint32_t)result); print_binary_32((uint32_t)result); printf(")\n");
}

int main() {
  bitwise_and_fn();
  bitwise_or_fn();
  bitwise_xor_fn();
  bitwise_not_fn();
  left_shift_fn();
  right_shift_fn();
  return 0;
}
