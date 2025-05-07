// 包含标准输入输出库，提供 printf, scanf 等函数
#include <stdio.h>

// 包含标准库，提供 atoi, atof 等函数
#include <stdlib.h>

// 包含字符串处理库，提供 strlen, strcpy 等函数
#include <string.h>

// scanf 函数功能：从标准输入中读取格式化数据，如字符串、整数、浮点数等
void testScanf() {
    // 打印测试函数的标题
    printf("测试 scanf 方法 - 从标准输入读取格式化数据\n");

    // 定义一个字符数组 buf，初始化为全 0，大小为 100
    char buf[100] = {0};

    // 提示用户输入字符串，scanf 只读取空格前的部分
    printf("请输入字符串 buf (空格前的内容会被读取): ");

    // 使用 scanf 读取用户输入的字符串，存入 buf
    scanf("%s", buf);

    // 示例输出: buf = [用户输入的第一个单词，例如 "hello"]
    printf("buf = %s\n", buf);

    // 清空输入缓冲区，防止前一次输入影响下一次读取
    while (getchar() != '\n');

    // 定义另一个字符数组 e，初始化为全 0，大小为 100
    char e[100] = {0};

    // 提示用户输入另一个字符串
    printf("请输入另一个字符串 e: ");

    // 使用 scanf 读取用户输入的字符串，存入 e
    scanf("%s", e);

    // 示例输出: e = [用户输入的字符串，例如 "world"] (从标准输入读取)
    printf("e = %s (从标准输入读取)\n", e);
}

// gets 函数功能：从标准输入中读取一行字符（包括空格），直到遇到换行符为止
void testGets() {
    // 打印测试函数的标题和警告
    printf("测试 gets 方法 - 读取一行字符串(不推荐使用)\n");

    // 定义一个字符数组 buf，大小为 100，未初始化
    char buf[100];

    // 提示用户输入一行字符串
    printf("请输入一行字符串: ");

    // 使用 gets 读取一行输入（包括空格），存入 buf
    gets(buf);

    // 示例输出: buf = [用户输入的一行，例如 "hello world"]
    printf("buf = %s\n", buf);

    // 打印使用 gets 的注意事项
    printf("注意: gets 已废弃，因不安全\n");

    // 打印空行分隔
    printf("\n");
}

// fgets 函数功能：从输入中读取一行字符串（可含空格），会保留换行符 \n
void testFgets() {
    // 打印测试函数的标题
    printf("测试 fgets 方法 - 安全读取一行字符串\n");

    // 定义一个字符数组 buf，大小为 10
    char buf[10];

    // 提示用户输入字符串，限制最多 9 个字符
    printf("请输入字符串(最多9字符): ");

    // 使用 fgets 从标准输入读取最多 9 个字符（留 1 位给 \0），存入 buf
    fgets(buf, sizeof(buf), stdin);

    // 示例输出: buf = '[用户输入，例如 "abcdefg\n"]' (包含换行符)
    printf("buf = '%s' (包含换行符)\n", buf);

    // 打印空行分隔
    printf("\n");
}

// puts 函数功能：向标准输出打印字符串并自动在末尾添加换行符
void testPuts() {
    // 打印测试函数的标题
    printf("测试 puts 方法 - 输出字符串并自动换行\n");

    // 定义一个字符数组 buf，初始化为 "hello"
    char buf[] = "hello";

    // 使用 printf 打印提示，不换行
    printf("使用printf: ");

    // 示例输出: hello
    printf("%s", buf);

    // 打印分隔符和 puts 的提示
    printf(" | 使用puts: ");

    // 示例输出: hello, world\n
    puts("hello, world");

    // 示例输出: good bye\n
    printf("good bye\n");

    // 打印空行分隔
    printf("\n");
}

// fputs 函数功能：向指定文件流输出字符串，不自动添加换行符
void testFputs() {
    // 打印测试函数的标题
    printf("测试 fputs 方法 - 输出字符串到指定流\n");

    // 定义一个字符数组 buf，初始化为 "hello, world"
    char buf[] = "hello, world";

    // 示例输出: hello, world
    fputs(buf, stdout);

    // 使用 printf 打印说明，并换行
    printf(" (fputs 不自动换行)\n");

    // 打印空行分隔
    printf("\n");
}

// strlen 函数功能：计算字符串长度（不包括空终止符 \0）
void testStrlen() {
    // 打印测试函数的标题
    printf("测试 strlen 方法 - 计算字符串长度\n");

    // 定义一个字符数组 buf，初始化为 "hello, world"
    char buf[] = "hello, world";

    // 示例输出: buf = "hello, world"
    printf("buf = \"%s\"\n", buf);

    // 示例输出: strlen = 12 (不含\0)
    printf("strlen = %lu (不含\\0)\n", strlen(buf));

    // 示例输出: sizeof = 13 (含\0)
    printf("sizeof = %lu (含\\0)\n", sizeof(buf));

    // 定义一个字符数组 buf2，初始化为 "\0hello"
    char buf2[] = "\0hello";

    // 示例输出: buf2 = "\0hello"
    printf("buf2 = \"\\0hello\"\n");

    // 示例输出: strlen = 0
    printf("strlen = %lu\n", strlen(buf2));

    // 示例输出: sizeof = 7
    printf("sizeof = %lu\n", sizeof(buf2));

    // 打印空行分隔
    printf("\n");
}

// strcpy/strncpy 函数功能：复制字符串
void testStrcpy() {
    // 打印测试函数的标题
    printf("测试 strcpy/strncpy 方法 - 复制字符串\n");

    // 定义源字符数组 src，初始化为 "hello\0, world"
    char src[100] = "hello\0, world";

    // 定义目标字符数组 dst，大小为 100，未初始化
    char dst[100];

    // 使用 strncpy 复制 src 前 12 个字符到 dst
    strncpy(dst, src, 12);

    // 修改 dst 的首字符为 'H'
    dst[0] = 'H';

    // 示例输出: src = hello
    printf("src = %s\n", src);

    // 示例输出: dst = Hello (修改后)
    printf("dst = %s (修改后)\n", dst);

    // 示例输出: strlen(dst) = 5
    printf("strlen(dst) = %lu\n", strlen(dst));

    // 打印空行分隔
    printf("\n");
}

// strcmp/strncmp 函数功能：比较两个字符串内容（逐字符 ASCII 比较）
void testStrcmp() {
    // 打印测试函数的标题
    printf("测试 strcmp/strncmp 方法 - 比较字符串\n");

    // 定义字符数组 a，初始化为 "hello, world"
    char a[100] = "hello, world";

    // 定义字符数组 b，初始化为 "hello, World"
    char b[100] = "hello, World";

    // 示例输出: a = hello, world
    printf("a = %s\n", a);

    // 示例输出: b = hello, World
    printf("b = %s\n", b);

    // 示例输出: strcmp = 32 (区分大小写)
    printf("strcmp = %d (区分大小写)\n", strcmp(a, b));

    // 示例输出: strncmp = 0 (比较前5个字符)
    printf("strncmp = %d (比较前5个字符)\n", strncmp(a, b, 5));

    // 打印空行分隔
    printf("\n");
}

// strcat/strncat 函数功能：将源字符串追加到目标字符串尾部
void testStrcat() {
    // 打印测试函数的标题
    printf("测试 strcat/strncat 方法 - 拼接字符串\n");

    // 定义源字符数组 src，初始化为 "hello"
    char src[100] = "hello";

    // 定义目标字符数组 dst，初始化为 "how are you?"
    char dst[100] = "how are you?";

    // 示例输出: Before: dst = how are you?, src = hello
    printf("Before: dst = %s, src = %s\n", dst, src);

    // 使用 strncat 将 src 的前 2 个字符追加到 dst
    strncat(dst, src, 2);

    // 示例输出: After strncat(dst, src, 2): dst = how are you?he
    printf("After strncat(dst, src, 2): dst = %s\n", dst);

    // 打印空行分隔
    printf("\n");
}

// sprintf 函数功能：格式化输出到字符串
void testSprintf() {
    // 打印测试函数的标题
    printf("测试 sprintf 方法 - 格式化输出到字符串\n");

    // 定义整数变量 a，赋值为 100
    int a = 100;

    // 定义字符变量 ch，赋值为 'a'
    char ch = 'a';

    // 定义字符数组 buf，初始化为 "hello"
    char buf[] = "hello";

    // 定义目标字符数组 dst，大小为 100，未初始化
    char dst[100];

    // 使用 sprintf 将格式化字符串写入 dst
    sprintf(dst, "a = %d, ch = %c, buf = %s", a, ch, buf);

    // 示例输出: dst = a = 100, ch = a, buf = hello
    printf("dst = %s\n", dst);

    // 打印空行分隔
    printf("\n");
}

// sscanf 函数功能：从字符串中读取格式化数据，可用来提取数字、字符串等
void testSscanf() {
    // 打印测试函数的标题
    printf("测试 sscanf 方法 - 从字符串读取格式化数据\n");

    // 定义字符数组 str，初始化为 "a = 1, b = 2, c = 3"
    char str[] = "a = 1, b = 2, c = 3";

    // 定义三个整数变量 a, b, c，用于存储解析结果
    int a, b, c;

    // 使用 sscanf 从 str 中解析出三个整数
    sscanf(str, "a = %d, b = %d, c = %d", &a, &b, &c);

    // 示例输出: str = a = 1, b = 2, c = 3
    printf("str = %s\n", str);

    // 示例输出: a = 1, b = 2, c = 3
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    // 打印空行分隔
    printf("\n");
}

// strchr/strstr 函数功能：查找字符或子字符串在字符串中的位置
void testStrchrStrstr() {
    // 打印测试函数的标题
    printf("测试 strchr/strstr 方法 - 查找字符或子字符串\n");

    // 定义字符数组 alpha，初始化为 "hello, world"
    char alpha[] = "hello, world";

    // 使用 strchr 查找字符 'w' 在 alpha 中的位置，返回指针
    char *s = strchr(alpha, 'w');

    // 使用 strstr 查找子字符串 "world" 在 alpha 中的位置，返回指针
    char *t = strstr(alpha, "world");

    // 示例输出: alpha = hello, world
    printf("alpha = %s\n", alpha);

    // 示例输出: strchr(alpha, 'w') = world
    printf("strchr(alpha, 'w') = %s\n", s);

    // 示例输出: strstr(alpha, "world") = world
    printf("strstr(alpha, \"world\") = %s\n", t);

    // 打印空行分隔
    printf("\n");
}

// strtok 函数功能：分割字符串
void testStrtok() {
    // 打印测试函数的标题
    printf("测试 strtok 方法 - 分割字符串\n");

    // 定义字符数组 alpha，初始化为 "one,two,three"
    char alpha[100] = "one,two,three";

    // 示例输出: 原始字符串: one,two,three
    printf("原始字符串: %s\n", alpha);

    // 使用 strtok 分割字符串，第一次调用传入 alpha 和分隔符 ","
    char *p = strtok(alpha, ",");

    // 循环打印每个分割出的 token
    while (p != NULL) {
        // 示例输出: token = one（第一次）, two（第二次）, three（第三次）
        printf("token = %s\n", p);

        // 继续分割，传入 NULL 以继续处理上次的字符串
        p = strtok(NULL, ",");
    }

    // 示例输出: 分割后原字符串变为: one
    printf("分割后原字符串变为: %s\n", alpha);

    // 打印空行分隔
    printf("\n");
}

// atoi/atof/atol 函数功能：将字符串转换为对应类型的数值（int、float、long）
void testAtoi() {
    // 打印测试函数的标题
    printf("测试 atoi/atof/atol 方法 - 字符串转数值\n");

    // 定义字符数组 str1，初始化为 "   +10"
    char str1[] = "   +10";

    // 定义字符数组 str2，初始化为 "0.123"
    char str2[] = "0.123";

    // 使用 atoi 将 str1 转换为整数
    int num1 = atoi(str1);

    // 使用 atof 将 str2 转换为浮点数
    double num2 = atof(str2);

    // 示例输出: str1 = "   +10"
    printf("str1 = \"%s\"\n", str1);

    // 示例输出: atoi(str1) = 10
    printf("atoi(str1) = %d\n", num1);

    // 示例输出: str2 = "0.123"
    printf("str2 = \"%s\"\n", str2);

    // 示例输出: atof(str2) = 0.123000
    printf("atof(str2) = %lf\n", num2);

    // 打印空行分隔
    printf("\n");
}

// 定义主函数，程序的入口
int main() {
    // 调用 testScanf 函数，测试 scanf
    // testScanf();

    // 调用 testGets 函数，测试 gets（注释掉，因不安全）
    // testGets();  // 注释掉，因为 gets 已废弃

    // 调用 testFgets 函数，测试 fgets
    // testFgets();

    // 调用 testPuts 函数，测试 puts
    testPuts();

    // 调用 testFputs 函数，测试 fputs
    testFputs();

    // 调用 testStrlen 函数，测试 strlen
    testStrlen();

    // 调用 testStrcpy 函数，测试 strcpy/strncpy
    testStrcpy();

    // 调用 testStrcmp 函数，测试 strcmp/strncmp
    testStrcmp();

    // 调用 testStrcat 函数，测试 strcat/strncat
    testStrcat();

    // 调用 testSprintf 函数，测试 sprintf
    testSprintf();

    // 调用 testSscanf 函数，测试 sscanf
    testSscanf();

    // 调用 testStrchrStrstr 函数，测试 strchr/strstr
    testStrchrStrstr();

    // 调用 testStrtok 函数，测试 strtok
    testStrtok();

    // 调用 testAtoi 函数，测试 atoi/atof/atol
    testAtoi();

    // 返回 0，表示程序正常结束
    return 0;
}