#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/**
%d�����һ���з��ŵ� 10 ���� int ��
%o�����һ�� 10 ���� int ��
%x�����һ�� 16 ���� int �ͣ���ĸСд
%X�����һ�� 16 ���� int �ͣ���ĸ��д
%u�����һ�� 10 ���Ƶ��޷�����
%hd����� short ����
%d����� int ����
%l����� long ����
%ll����� long long ����
%hu����� unsigned short ����
%u����� unsigned int ����
%lu����� unsigned long ����
%llu����� unsigned long long ����
 */
void intDataTypeFn() {

  // ��� int �����ݷ�Χ
  printf("sizeof(int): %llu\n", sizeof(int));
  // ��� INT_MAX, INT_MIN ��ֵ
  printf("INT_MAX: %d, (2^31)-1\n", INT_MAX);
  printf("INT_MIN: %d, -(2^31)\n", INT_MIN);
  // ��� unsigned int �����ֵ
  printf("UINT_MAX: %u, (2^32)-1\n", UINT_MAX);
  printf("\n");

  // ��� short int �����ݷ�Χ
  printf("sizeof(short int): %llu\n", sizeof(short int));
  // ��� SHRT_MAX, SHRT_MIN ��ֵ
  printf("SHRT_MAX: %d, (2^15)-1\n", SHRT_MAX);
  printf("SHRT_MIN: %d, -(2^15)\n", SHRT_MIN);
  // ��� unsigned short int �����ֵ
  printf("USHRT_MAX: %u, (2^16)-1\n", USHRT_MAX);
  printf("\n");

  // ��� long int �����ݷ�Χ
  printf("sizeof(long int): %llu\n", sizeof(long int));
  // ��� LONG_MAX, LONG_MIN ��ֵ
  printf("LONG_MAX: %ld, (2^31)-1\n", LONG_MAX);
  printf("LONG_MIN: %ld, -(2^31)\n", LONG_MIN);
  // ��� unsigned long int �����ֵ
  printf("ULONG_MAX: %lu, (2^32)-1\n", ULONG_MAX);
  printf("\n");

  // ��� long long int �����ݷ�Χ
  printf("sizeof(long long int): %llu\n", sizeof(long long int));
  // ��� LLONG_MAX, LLONG_MIN ��ֵ
  printf("LLONG_MAX: %lld, (2^63)-1\n", LLONG_MAX);
  printf("LLONG_MIN: %lld, -(2^63)\n", LLONG_MIN);
  // ��� unsigned long long int �����ֵ
  printf("ULLONG_MAX: %llu, (2^64)-1\n", ULLONG_MAX);
  printf("\n");

  // size_t ���޷����������ͣ�ͨ�����ڱ�ʾ����Ĵ�С
  // long long unsigned int
  size_t size_of_int = sizeof(int);
  printf("sizeof(size_t): %llu\n", sizeof(size_of_int));

}

void floatDataTypeFn() {
  // float �� 6 λ��Ч����
  float a_float = 1234567.1234567f;
  printf("a_float: %f\n", a_float);
  printf("sizeof(float): %llu\n", sizeof(float));

  // double �� 15 λ��Ч����
  double a_double = 1234567.1234567;
  printf("a_double: %.15lf\n", a_double);
  printf("sizeof(double): %llu\n", sizeof(double));

  // ���������ȵ�����
  float f1 = 39.1234567f;
  printf("f1: %f\n", f1);
  float f2 = 39.1234567f;
  printf("f2: %f\n", f2);
  printf("f1 - f2 = %f", f1 - f2);
  printf("%f - 39.1234567 = %f\n", f1, f1 - 39.1234567);
  printf("%f - 39.123456 = %f\n", f1, f1 - 39.123456);
  printf("%f - 39.12345 = %f\n", f1, f1 - 39.12345);
  printf("%f - 39.1234 = %f\n", f1, f1 - 39.1234);
  printf("%f - 39.123 = %f\n", f1, f1 - 39.123);

  // ���� 39.1234567890 ��������תΪ�����ƣ����Ի��ж�ʧ���ȡ�
  double d1 = 39.1234567890;
  printf("d1: %.15lf\n", d1);
  double d2 = 39.1234567890;
  printf("d2: %.15lf\n", d2);
  printf("d1 - d2 = %.15lf\n", d1 - d2);
  printf("%.15lf - 39.1234567890 = %.15lf\n", d1, d1 - 39.1234567890);
  printf("%.15lf - 39.123456789 = %.15lf\n", d1, d1 - 39.123456789);
  printf("%.15lf - 39.12345678 = %.15lf\n", d1, d1 - 39.12345678);
  printf("%.15lf - 39.1234567 = %.15lf\n", d1, d1 - 39.1234567);
  printf("%.15lf - 39.123456 = %.15lf\n", d1, d1 - 39.123456);
  printf("%.15lf - 39.12345 = %.15lf\n", d1, d1 - 39.12345);
  printf("%.15lf - 39.1234 = %.15lf\n", d1, d1 - 39.1234);

  double d3 = 12.1234567890;
  printf("d3: %.15lf\n", d3);
  double d4 = 12.1234567890;
  printf("d4: %.15lf\n", d4);
  printf("d3 - d4 = %.15lf\n", d3 - d4);
  printf("%.15lf - 12.1234567890 = %.15lf\n", d3, d3 - 12.1234567890);
  printf("%.15lf - 12.123456789 = %.15lf\n", d3, d3 - 12.123456789);
  printf("%.15lf - 12.12345678 = %.15lf\n", d3, d3 - 12.12345678);
  printf("%.15lf - 12.1234567 = %.15lf\n", d3, d3 - 12.1234567);
  printf("%.15lf - 12.123456 = %.15lf\n", d3, d3 - 12.123456);

}


// ��Сд��ĸת���ı������ڣ�������ĸ�������Ǵ�д����Сд���� ASCII ��ľ��루����˵������ĸ�� ASCII �Ĳ�ֵ����һ���ġ�
// ��д��ĸ A-Z ����Ϊ 65-90
// Сд��ĸ a-z ����Ϊ 97-122

// �ַ�תΪ��д
char to_upper(char c) {
  // �ж���ĸ�Ƿ���Сд��ĸ������
  if (c >= 'a' && c <= 'z') {
    // c - 'a' �õ�Сд��ĸ�� 'a' ��ʼ��ƫ������
    // ���� c ����ĸ 'd'����ĸ 'd' �� ASCII ���� 100
    // 'd' - 'a' = 100 - 97 = 3���� 'd' ��Сд��ĸ�����ƫ������ 3
    // Ҳ����˵ 'D' ���� 'A' �ľ���Ҳ�� 3��
    // + 'A' ��ʾ�� 'A' ��ʼ������ƫ���� 3���Ϳ��Եõ� 'D'��
    return c - 'a' + 'A';
  }
  return c;
}

// �ַ�תΪСд
char to_lower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  }
  return c;
}

void charDataTypeFn() {
  // ����һ���ַ� a
  char a_char = 'a';
  printf("a_char: %c\n", a_char);
  // �� �ַ� a ת��Ϊ int ����
  // �õ�һ�� int ���ͣ�ֵΪ �ַ� a �� ASCII ��
  // �ַ� a �� ASCII ��ֵ�� 97������ a_int �� 97
  int a_int = (int) a_char;
  printf("a_int: %d\n", a_int);

  char A_char = to_upper(a_char);
  printf("A_char: %c\n", A_char);
  int A_int = (int) A_char;
  printf("A_int: %d\n", A_int);

  // �ַ� '0' �� ASCII ���� 48
  char char_0 = '0';
  printf("char_0: %c\n", char_0);
  int char_0_int = (int) char_0;
  printf("char_0_int: %d\n", char_0_int);

//   ���ַ���C95 ֧��
//  wchar_t bian = L'��';
//  printf("bian: %lc\n", bian);
//
//  wchar_t cheng = L'��';
//  printf("cheng: %lc\n", cheng);

}

void constantTypeFn() {
  // ������Ҳ����˵��ֻ������������е�ַ��Ҳ�����޸�ֵ��
  const int a = 10;
  printf("a: %d\n", a);

  // ����������ȫ����Ϊ�����޸�ָ��ָ���ֵ������Ҫ�����á�
//  int *p = &a;
  // ���ԣ�Ҫȷ����ȫ��Ӧ��ʹ�á�Ҫ�����á�
  const int *p = &a;

  printf("p: %p\n", p);
  // ͨ��ָ�� p �޸��� a ��ֵ��
//  *p = 20;
  printf("a: %d\n", a);
}

void operatorTypeFn() {
  printf(" 3 > 2 %d\n", 3 > 2);
  printf(" 3 >= 2 %d\n", 3 >= 2);
  printf(" 3 < 2 %d\n", 3 < 2);
  printf(" 3 <= 2 %d\n", 3 <= 2);
  printf(" 3 == 2 %d\n", 3 == 2);
  printf(" 3 != 2 %d\n", 3 != 2);

  // �߼���������� �� ��
  printf(" 3 && 2 %d\n", 3 && 2);
  printf(" 3 || 2 %d\n", 3 || 2);
  printf(" !3 %d\n", !3);

  // ��λ�롢��λ�򡢰�λȡ������λ�����ơ�����
  int bit_a = 0b0001;
  int bit_b = 0b0101;
}

void ioOperationFn() {
  // ������������
  int a = 0;

  printf("������һ��������");
  scanf("%d\n", &a);
  printf("�������������: %d\n", a);

  // ����ַ���
  char str[100];
  printf("������һ���ַ���: ");
  scanf("%s", str);
  printf("��������ַ�����: %s\n", str);
}

int main() {
//  intDataTypeFn();
//  floatDataTypeFn();
//  charDataTypeFn();
//  constantTypeFn();
//  operatorTypeFn();
  ioOperationFn();
};
