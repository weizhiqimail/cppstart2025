#include <stdio.h>

// 主函数，接收命令行参数
// argc: 参数总数（包括程序名）
// argv: 指针数组，存储每个参数的字符串
int main(int argc, char *argv[]) {
    // 打印参数总数
    printf("Total number of arguments: %d\n", argc);
    
    // 遍历 argv 数组，逐个打印每个参数
    printf("Command line arguments:\n");
    for (int i = 0; i < argc; i++) {
        // argv[i] 是第 i 个参数的字符串
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    
    // 添加分隔线，提升可读性
    printf("------------------------\n");
    
    return 0;
}