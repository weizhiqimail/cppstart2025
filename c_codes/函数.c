#include <stdio.h>
#include <stdarg.h>

void handleVarargs(int arg_count, ...) {
  // 定义 va_list，用于获取变长参数
  va_list args;

  // 开始遍历
  va_start(args, arg_count);

  for (int i = 0; i < arg_count; i++) {
    // 依据参数索引获取参数
    int arg = va_arg(args, int);
    printf("Argument %d: %d\n", i + 1, arg);
  }

  // 结束遍历
  va_end(args);

}

unsigned int fibonacci(unsigned int v) {
  if (v == 0) {
    return 0;
  } else if (v == 1) {
    return 1;
  } else {
    return fibonacci(v - 1) + fibonacci(v - 2);
  }
}

unsigned int factorial(unsigned int v) {
  if (v == 0) {
    return 1;
  }
  return v * factorial(v - 1);
}

unsigned int towerOfHanoi(int n, char from, char to, char aux) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", from, to);
    return 1;
  }
  unsigned int moves = towerOfHanoi(n - 1, from, aux, to);
  printf("Move disk %d from %c to %c\n", n, from, to);
  moves += towerOfHanoi(n - 1, aux, to, from);
  return moves + 1;
}

int main() {
//  handleVarargs(3, 1, 2, 3);
//  unsigned int fib10 = fibonacci(10);
//  printf("Fibonacci(10) = %d\n", fib10);
//
//  unsigned int fib30 = fibonacci(30);
//  printf("Fibonacci(30) = %d\n", fib30);
//
//  unsigned int fac10 = factorial(10);
//  printf("factorial(10) = %d\n", fac10);
//
//  unsigned int fac30 = factorial(30);
//  printf("factorial(30) = %d\n", fac30);

  towerOfHanoi(3, 'A', 'B', 'C');

  return 0;
}




