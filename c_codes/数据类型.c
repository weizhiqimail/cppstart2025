#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

/**
%d，输出一个有符号的 10 进制 int 型
%o，输出一个 10 进制 int 型
%x，输出一个 16 进制 int 型，字母小写
%X，输出一个 16 进制 int 型，字母大写
%u，输出一个 10 进制的无符号数
%hd，输出 short 类型
%d，输出 int 类型
%l，输出 long 类型
%ll，输出 long long 类型
%hu，输出 unsigned short 类型
%u，输出 unsigned int 类型
%lu，输出 unsigned long 类型
%llu，输出 unsigned long long 类型
 */
void intDataTypeFn() {

  // 输出 int 的数据范围
  printf("sizeof(int): %llu\n", sizeof(int));
  // 输出 INT_MAX, INT_MIN 的值
  printf("INT_MAX: %d, (2^31)-1\n", INT_MAX);
  printf("INT_MIN: %d, -(2^31)\n", INT_MIN);
  // 输出 unsigned int 的最大值
  printf("UINT_MAX: %u, (2^32)-1\n", UINT_MAX);
  printf("\n");

  // 输出 short int 的数据范围
  printf("sizeof(short int): %llu\n", sizeof(short int));
  // 输出 SHRT_MAX, SHRT_MIN 的值
  printf("SHRT_MAX: %d, (2^15)-1\n", SHRT_MAX);
  printf("SHRT_MIN: %d, -(2^15)\n", SHRT_MIN);
  // 输出 unsigned short int 的最大值
  printf("USHRT_MAX: %u, (2^16)-1\n", USHRT_MAX);
  printf("\n");

  // 输出 long int 的数据范围
  printf("sizeof(long int): %llu\n", sizeof(long int));
  // 输出 LONG_MAX, LONG_MIN 的值
  printf("LONG_MAX: %ld, (2^31)-1\n", LONG_MAX);
  printf("LONG_MIN: %ld, -(2^31)\n", LONG_MIN);
  // 输出 unsigned long int 的最大值
  printf("ULONG_MAX: %lu, (2^32)-1\n", ULONG_MAX);
  printf("\n");

  // 输出 long long int 的数据范围
  printf("sizeof(long long int): %llu\n", sizeof(long long int));
  // 输出 LLONG_MAX, LLONG_MIN 的值
  printf("LLONG_MAX: %lld, (2^63)-1\n", LLONG_MAX);
  printf("LLONG_MIN: %lld, -(2^63)\n", LLONG_MIN);
  // 输出 unsigned long long int 的最大值
  printf("ULLONG_MAX: %llu, (2^64)-1\n", ULLONG_MAX);
  printf("\n");

  // size_t 是无符号整数类型，通常用于表示对象的大小
  // long long unsigned int
  size_t size_of_int = sizeof(int);
  printf("sizeof(size_t): %llu\n", sizeof(size_of_int));

}

void floatDataTypeFn() {
  // float 有 6 位有效数字
  float a_float = 1234567.1234567f;
  printf("a_float: %f\n", a_float);
  printf("sizeof(float): %llu\n", sizeof(float));

  // double 有 15 位有效数字
  double a_double = 1234567.1234567;
  printf("a_double: %.15lf\n", a_double);
  printf("sizeof(double): %llu\n", sizeof(double));

  // 浮点数精度的问题
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

  // 由于 39.1234567890 不能完美转为二进制，所以会有丢失精度。
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


// 大小写字母转换的本质在于：两个字母，无论是大写还是小写，在 ASCII 里的距离（或者说两个字母的 ASCII 的差值）是一样的。
// 大写字母 A-Z 区间为 65-90
// 小写字母 a-z 区间为 97-122

// 字符转为大写
char to_upper(char c) {
  // 判断字母是否在小写字母区间内
  if (c >= 'a' && c <= 'z') {
    // c - 'a' 得到小写字母从 'a' 开始的偏移量。
    // 假设 c 是字母 'd'，字母 'd' 的 ASCII 码是 100
    // 'd' - 'a' = 100 - 97 = 3，即 'd' 在小写字母区间的偏移量是 3
    // 也就是说 'D' 距离 'A' 的距离也是 3。
    // + 'A' 表示从 'A' 开始，补齐偏移量 3，就可以得到 'D'。
    return c - 'a' + 'A';
  }
  return c;
}

// 字符转为小写
char to_lower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  }
  return c;
}

void charDataTypeFn() {
  // 定义一个字符 a
  char a_char = 'a';
  printf("a_char: %c\n", a_char);
  // 将 字符 a 转换为 int 类型
  // 得到一个 int 类型，值为 字符 a 的 ASCII 码
  // 字符 a 的 ASCII 的值是 97，所以 a_int 是 97
  int a_int = (int) a_char;
  printf("a_int: %d\n", a_int);

  char A_char = to_upper(a_char);
  printf("A_char: %c\n", A_char);
  int A_int = (int) A_char;
  printf("A_int: %d\n", A_int);

  // 字符 '0' 的 ASCII 码是 48
  char char_0 = '0';
  printf("char_0: %c\n", char_0);
  int char_0_int = (int) char_0;
  printf("char_0_int: %d\n", char_0_int);

//   宽字符，C95 支持
//  wchar_t bian = L'编';
//  printf("bian: %lc\n", bian);
//
//  wchar_t cheng = L'程';
//  printf("cheng: %lc\n", cheng);

}

void constantTypeFn() {
  // 常量，也可以说是只读变量。如果有地址，也可以修改值。
  const int a = 10;
  printf("a: %d\n", a);

  // 这样做不安全，因为可以修改指针指向的值。【不要这样用】
//  int *p = &a;
  // 所以，要确保安全，应该使用【要这样用】
  const int *p = &a;

  printf("p: %p\n", p);
  // 通过指针 p 修改了 a 的值。
//  *p = 20;
  printf("a: %d\n", a);
}

typedef struct {
  char name[20];
  int age;
  union {
    char phone[20];
    char email[30];
  };
} User;

inline static const char *findAddr(const User *user) {
  assert(user != NULL);
  return user->phone[0] != '\0' ? user->phone : user->email;
}

void arrayDataTypeFn() {
  User users[] = {
      [0] = {"Alice", 20, .phone="17688887777"},
      [1] = {"Bob", 25, .email="bob@email.com"},
      [2] = {"Charlie", 30, .email = "charlie@email.com"},
      [5] = {"Jack", 20, .email = "jack@email.com"},
  };

  for (size_t i = 0; i < (sizeof(users) / sizeof(User)); i++) {
    User item = users[i];
    printf("User %zu: Name: %s, Age: %d, connection: %s\n", i, item.name, item.age, findAddr(&item));
  }

}

void operatorTypeFn() {
  printf(" 3 > 2 %d\n", 3 > 2);
  printf(" 3 >= 2 %d\n", 3 >= 2);
  printf(" 3 < 2 %d\n", 3 < 2);
  printf(" 3 <= 2 %d\n", 3 <= 2);
  printf(" 3 == 2 %d\n", 3 == 2);
  printf(" 3 != 2 %d\n", 3 != 2);

  // 逻辑运算符：且 或 非
  printf(" 3 && 2 %d\n", 3 && 2);
  printf(" 3 || 2 %d\n", 3 || 2);
  printf(" !3 %d\n", !3);

  // 按位与、按位或、按位取反、移位：左移、右移
  int bit_a = 0b0001;
  int bit_b = 0b0101;
}

void ioOperationFn() {
  // 输入输出运算符
  int a = 0;

  printf("请输入一个整数：");
  scanf("%d\n", &a);
  printf("你输入的整数是: %d\n", a);

  // 输出字符串
  char str[100];
  printf("请输入一个字符串: ");
  scanf("%s", str);
  printf("你输入的字符串是: %s\n", str);
}

void ioOperationFn2() {
  int left;
  int right;
  char operator;

  printf("请输入一个表达式。");
  scanf("%d %c %d", &left, &operator, &right);
  printf("你输入的表达式是: %d %c %d\n", left, operator, right);

  int result;

  switch (operator) {
    case '+':result = left + right;
      break;
    case '-':result = left - right;
      break;
    case '*':result = left * right;
      break;
    case '/':
      if (right != 0) {
        result = left / right;
      } else {
        printf("除数不能为零！\n");
        return;
      }
      break;
    case '%':
      if (right != 0) {
        result = left % right;
      } else {
        printf("除数不能为零！\n");
        return;
      }
      break;
    default:printf("无效的运算符！\n");
      return;
  }
  printf("结果是: %d\n", result);

}

int main() {
//  intDataTypeFn();
//  floatDataTypeFn();
//  charDataTypeFn();
//  constantTypeFn();
  arrayDataTypeFn();
//  operatorTypeFn();
//  ioOperationFn();
//  ioOperationFn2();
};
