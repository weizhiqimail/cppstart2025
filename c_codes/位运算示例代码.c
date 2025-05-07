#include <stdio.h>
#include <stdint.h>

// ���32λ�����ƣ���ÿ4λ�ָ�
void print_binary_32(uint32_t val) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (val >> i) & 1);
    if (i % 4 == 0 && i != 0) printf(" ");
  }
}

// ���16λ�����ƣ���ÿ4λ�ָ�
void print_binary_16(uint16_t val) {
  for (int i = 15; i >= 0; i--) {
    printf("%d", (val >> i) & 1);
    if (i % 4 == 0 && i != 0) printf(" ");
  }
}

// ��λ�����
void bitwise_and_fn() {
  printf("====== ��λ����� ======\n");

  uint32_t a = 0x12345678;
  uint32_t maskInt = 0xFFFFFF00;
  uint32_t resultInt = a & maskInt;

  uint16_t s = 0x12FF;
  uint16_t maskShort = 0xFF00;
  uint16_t resultShort = s & maskShort;

  // int ����
  printf("===== int ���������� =====\n");
  printf("ԭʼ a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("���� maskInt  = 0x%08X (", maskInt); print_binary_32(maskInt); printf(")\n");
  printf("��� result   = 0x%08X (", resultInt); print_binary_32(resultInt); printf(")\n");

  // short ����
  printf("\n===== short ���������� =====\n");
  printf("ԭʼ s        = 0x%04X (", s); print_binary_16(s); printf(")\n");
  printf("���� maskShort= 0x%04X (", maskShort); print_binary_16(maskShort); printf(")\n");
  printf("��� result   = 0x%04X (", resultShort); print_binary_16(resultShort); printf(")\n");
}

// ��λ�����
void bitwise_or_fn() {
  printf("\n====== ��λ����� (|) ======\n");
  uint32_t a = 0x0F0F0F0F;
  uint32_t b = 0x33333333;
  uint32_t result = a | b;

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("b        = 0x%08X (", b); print_binary_32(b); printf(")\n");
  printf("a | b    = 0x%08X (", result); print_binary_32(result); printf(")\n");
}

// ��λ������
void bitwise_xor_fn() {
  printf("\n====== ��λ������ (^) ======\n");
  uint32_t a = 0xAAAA5555;
  uint32_t b = 0xFFFF0000;
  uint32_t result = a ^ b;

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("b        = 0x%08X (", b); print_binary_32(b); printf(")\n");
  printf("a ^ b    = 0x%08X (", result); print_binary_32(result); printf(")\n");
}

// ��λȡ������
void bitwise_not_fn() {
  printf("\n====== ��λȡ������ (~) ======\n");
  uint32_t a = 0x0F0F0F0F;
  uint32_t result = ~a;

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("~a       = 0x%08X (", result); print_binary_32(result); printf(")\n");
}

// ���Ʋ���
void left_shift_fn() {
  printf("\n====== ���Ʋ��� (<<) ======\n");
  uint32_t a = 0x0000000F;
  int shift = 4;
  uint32_t result = a << shift;

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("a << %d   = 0x%08X (", shift, result); print_binary_32(result); printf(")\n");

  printf("\n====== ���Ʋ�������λ 35 λ������Χ��======\n");
  int shift_large = 35;
  result = a << (shift_large % 32);  // ����δ������Ϊ

  printf("a        = 0x%08X (", a); print_binary_32(a); printf(")\n");
  printf("a << %d  = 0x%08X (", shift_large, result); print_binary_32(result); printf(")\n");
}

// ���Ʋ���
void right_shift_fn() {
  printf("\n====== ���Ʋ��� (>>) ======\n");
  int32_t a = 0xF0000000;
  int shift = 4;
  int32_t result = a >> shift;

  printf("a        = 0x%08X (", a); print_binary_32((uint32_t)a); printf(")\n");
  printf("a >> %d  = 0x%08X (", shift, (uint32_t)result); print_binary_32((uint32_t)result); printf(")\n");

  printf("\n====== ���Ʋ�������λ 35 λ������Χ��======\n");
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
