// ������׼��������⣬�ṩ printf, scanf �Ⱥ���
#include <stdio.h>

// ������׼�⣬�ṩ atoi, atof �Ⱥ���
#include <stdlib.h>

// �����ַ�������⣬�ṩ strlen, strcpy �Ⱥ���
#include <string.h>

// scanf �������ܣ��ӱ�׼�����ж�ȡ��ʽ�����ݣ����ַ�������������������
void testScanf() {
    // ��ӡ���Ժ����ı���
    printf("���� scanf ���� - �ӱ�׼�����ȡ��ʽ������\n");

    // ����һ���ַ����� buf����ʼ��Ϊȫ 0����СΪ 100
    char buf[100] = {0};

    // ��ʾ�û������ַ�����scanf ֻ��ȡ�ո�ǰ�Ĳ���
    printf("�������ַ��� buf (�ո�ǰ�����ݻᱻ��ȡ): ");

    // ʹ�� scanf ��ȡ�û�������ַ��������� buf
    scanf("%s", buf);

    // ʾ�����: buf = [�û�����ĵ�һ�����ʣ����� "hello"]
    printf("buf = %s\n", buf);

    // ������뻺��������ֹǰһ������Ӱ����һ�ζ�ȡ
    while (getchar() != '\n');

    // ������һ���ַ����� e����ʼ��Ϊȫ 0����СΪ 100
    char e[100] = {0};

    // ��ʾ�û�������һ���ַ���
    printf("��������һ���ַ��� e: ");

    // ʹ�� scanf ��ȡ�û�������ַ��������� e
    scanf("%s", e);

    // ʾ�����: e = [�û�������ַ��������� "world"] (�ӱ�׼�����ȡ)
    printf("e = %s (�ӱ�׼�����ȡ)\n", e);
}

// gets �������ܣ��ӱ�׼�����ж�ȡһ���ַ��������ո񣩣�ֱ���������з�Ϊֹ
void testGets() {
    // ��ӡ���Ժ����ı���;���
    printf("���� gets ���� - ��ȡһ���ַ���(���Ƽ�ʹ��)\n");

    // ����һ���ַ����� buf����СΪ 100��δ��ʼ��
    char buf[100];

    // ��ʾ�û�����һ���ַ���
    printf("������һ���ַ���: ");

    // ʹ�� gets ��ȡһ�����루�����ո񣩣����� buf
    gets(buf);

    // ʾ�����: buf = [�û������һ�У����� "hello world"]
    printf("buf = %s\n", buf);

    // ��ӡʹ�� gets ��ע������
    printf("ע��: gets �ѷ������򲻰�ȫ\n");

    // ��ӡ���зָ�
    printf("\n");
}

// fgets �������ܣ��������ж�ȡһ���ַ������ɺ��ո񣩣��ᱣ�����з� \n
void testFgets() {
    // ��ӡ���Ժ����ı���
    printf("���� fgets ���� - ��ȫ��ȡһ���ַ���\n");

    // ����һ���ַ����� buf����СΪ 10
    char buf[10];

    // ��ʾ�û������ַ������������ 9 ���ַ�
    printf("�������ַ���(���9�ַ�): ");

    // ʹ�� fgets �ӱ�׼�����ȡ��� 9 ���ַ����� 1 λ�� \0�������� buf
    fgets(buf, sizeof(buf), stdin);

    // ʾ�����: buf = '[�û����룬���� "abcdefg\n"]' (�������з�)
    printf("buf = '%s' (�������з�)\n", buf);

    // ��ӡ���зָ�
    printf("\n");
}

// puts �������ܣ����׼�����ӡ�ַ������Զ���ĩβ��ӻ��з�
void testPuts() {
    // ��ӡ���Ժ����ı���
    printf("���� puts ���� - ����ַ������Զ�����\n");

    // ����һ���ַ����� buf����ʼ��Ϊ "hello"
    char buf[] = "hello";

    // ʹ�� printf ��ӡ��ʾ��������
    printf("ʹ��printf: ");

    // ʾ�����: hello
    printf("%s", buf);

    // ��ӡ�ָ����� puts ����ʾ
    printf(" | ʹ��puts: ");

    // ʾ�����: hello, world\n
    puts("hello, world");

    // ʾ�����: good bye\n
    printf("good bye\n");

    // ��ӡ���зָ�
    printf("\n");
}

// fputs �������ܣ���ָ���ļ�������ַ��������Զ���ӻ��з�
void testFputs() {
    // ��ӡ���Ժ����ı���
    printf("���� fputs ���� - ����ַ�����ָ����\n");

    // ����һ���ַ����� buf����ʼ��Ϊ "hello, world"
    char buf[] = "hello, world";

    // ʾ�����: hello, world
    fputs(buf, stdout);

    // ʹ�� printf ��ӡ˵����������
    printf(" (fputs ���Զ�����)\n");

    // ��ӡ���зָ�
    printf("\n");
}

// strlen �������ܣ������ַ������ȣ�����������ֹ�� \0��
void testStrlen() {
    // ��ӡ���Ժ����ı���
    printf("���� strlen ���� - �����ַ�������\n");

    // ����һ���ַ����� buf����ʼ��Ϊ "hello, world"
    char buf[] = "hello, world";

    // ʾ�����: buf = "hello, world"
    printf("buf = \"%s\"\n", buf);

    // ʾ�����: strlen = 12 (����\0)
    printf("strlen = %lu (����\\0)\n", strlen(buf));

    // ʾ�����: sizeof = 13 (��\0)
    printf("sizeof = %lu (��\\0)\n", sizeof(buf));

    // ����һ���ַ����� buf2����ʼ��Ϊ "\0hello"
    char buf2[] = "\0hello";

    // ʾ�����: buf2 = "\0hello"
    printf("buf2 = \"\\0hello\"\n");

    // ʾ�����: strlen = 0
    printf("strlen = %lu\n", strlen(buf2));

    // ʾ�����: sizeof = 7
    printf("sizeof = %lu\n", sizeof(buf2));

    // ��ӡ���зָ�
    printf("\n");
}

// strcpy/strncpy �������ܣ������ַ���
void testStrcpy() {
    // ��ӡ���Ժ����ı���
    printf("���� strcpy/strncpy ���� - �����ַ���\n");

    // ����Դ�ַ����� src����ʼ��Ϊ "hello\0, world"
    char src[100] = "hello\0, world";

    // ����Ŀ���ַ����� dst����СΪ 100��δ��ʼ��
    char dst[100];

    // ʹ�� strncpy ���� src ǰ 12 ���ַ��� dst
    strncpy(dst, src, 12);

    // �޸� dst �����ַ�Ϊ 'H'
    dst[0] = 'H';

    // ʾ�����: src = hello
    printf("src = %s\n", src);

    // ʾ�����: dst = Hello (�޸ĺ�)
    printf("dst = %s (�޸ĺ�)\n", dst);

    // ʾ�����: strlen(dst) = 5
    printf("strlen(dst) = %lu\n", strlen(dst));

    // ��ӡ���зָ�
    printf("\n");
}

// strcmp/strncmp �������ܣ��Ƚ������ַ������ݣ����ַ� ASCII �Ƚϣ�
void testStrcmp() {
    // ��ӡ���Ժ����ı���
    printf("���� strcmp/strncmp ���� - �Ƚ��ַ���\n");

    // �����ַ����� a����ʼ��Ϊ "hello, world"
    char a[100] = "hello, world";

    // �����ַ����� b����ʼ��Ϊ "hello, World"
    char b[100] = "hello, World";

    // ʾ�����: a = hello, world
    printf("a = %s\n", a);

    // ʾ�����: b = hello, World
    printf("b = %s\n", b);

    // ʾ�����: strcmp = 32 (���ִ�Сд)
    printf("strcmp = %d (���ִ�Сд)\n", strcmp(a, b));

    // ʾ�����: strncmp = 0 (�Ƚ�ǰ5���ַ�)
    printf("strncmp = %d (�Ƚ�ǰ5���ַ�)\n", strncmp(a, b, 5));

    // ��ӡ���зָ�
    printf("\n");
}

// strcat/strncat �������ܣ���Դ�ַ���׷�ӵ�Ŀ���ַ���β��
void testStrcat() {
    // ��ӡ���Ժ����ı���
    printf("���� strcat/strncat ���� - ƴ���ַ���\n");

    // ����Դ�ַ����� src����ʼ��Ϊ "hello"
    char src[100] = "hello";

    // ����Ŀ���ַ����� dst����ʼ��Ϊ "how are you?"
    char dst[100] = "how are you?";

    // ʾ�����: Before: dst = how are you?, src = hello
    printf("Before: dst = %s, src = %s\n", dst, src);

    // ʹ�� strncat �� src ��ǰ 2 ���ַ�׷�ӵ� dst
    strncat(dst, src, 2);

    // ʾ�����: After strncat(dst, src, 2): dst = how are you?he
    printf("After strncat(dst, src, 2): dst = %s\n", dst);

    // ��ӡ���зָ�
    printf("\n");
}

// sprintf �������ܣ���ʽ��������ַ���
void testSprintf() {
    // ��ӡ���Ժ����ı���
    printf("���� sprintf ���� - ��ʽ��������ַ���\n");

    // ������������ a����ֵΪ 100
    int a = 100;

    // �����ַ����� ch����ֵΪ 'a'
    char ch = 'a';

    // �����ַ����� buf����ʼ��Ϊ "hello"
    char buf[] = "hello";

    // ����Ŀ���ַ����� dst����СΪ 100��δ��ʼ��
    char dst[100];

    // ʹ�� sprintf ����ʽ���ַ���д�� dst
    sprintf(dst, "a = %d, ch = %c, buf = %s", a, ch, buf);

    // ʾ�����: dst = a = 100, ch = a, buf = hello
    printf("dst = %s\n", dst);

    // ��ӡ���зָ�
    printf("\n");
}

// sscanf �������ܣ����ַ����ж�ȡ��ʽ�����ݣ���������ȡ���֡��ַ�����
void testSscanf() {
    // ��ӡ���Ժ����ı���
    printf("���� sscanf ���� - ���ַ�����ȡ��ʽ������\n");

    // �����ַ����� str����ʼ��Ϊ "a = 1, b = 2, c = 3"
    char str[] = "a = 1, b = 2, c = 3";

    // ���������������� a, b, c�����ڴ洢�������
    int a, b, c;

    // ʹ�� sscanf �� str �н�������������
    sscanf(str, "a = %d, b = %d, c = %d", &a, &b, &c);

    // ʾ�����: str = a = 1, b = 2, c = 3
    printf("str = %s\n", str);

    // ʾ�����: a = 1, b = 2, c = 3
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    // ��ӡ���зָ�
    printf("\n");
}

// strchr/strstr �������ܣ������ַ������ַ������ַ����е�λ��
void testStrchrStrstr() {
    // ��ӡ���Ժ����ı���
    printf("���� strchr/strstr ���� - �����ַ������ַ���\n");

    // �����ַ����� alpha����ʼ��Ϊ "hello, world"
    char alpha[] = "hello, world";

    // ʹ�� strchr �����ַ� 'w' �� alpha �е�λ�ã�����ָ��
    char *s = strchr(alpha, 'w');

    // ʹ�� strstr �������ַ��� "world" �� alpha �е�λ�ã�����ָ��
    char *t = strstr(alpha, "world");

    // ʾ�����: alpha = hello, world
    printf("alpha = %s\n", alpha);

    // ʾ�����: strchr(alpha, 'w') = world
    printf("strchr(alpha, 'w') = %s\n", s);

    // ʾ�����: strstr(alpha, "world") = world
    printf("strstr(alpha, \"world\") = %s\n", t);

    // ��ӡ���зָ�
    printf("\n");
}

// strtok �������ܣ��ָ��ַ���
void testStrtok() {
    // ��ӡ���Ժ����ı���
    printf("���� strtok ���� - �ָ��ַ���\n");

    // �����ַ����� alpha����ʼ��Ϊ "one,two,three"
    char alpha[100] = "one,two,three";

    // ʾ�����: ԭʼ�ַ���: one,two,three
    printf("ԭʼ�ַ���: %s\n", alpha);

    // ʹ�� strtok �ָ��ַ�������һ�ε��ô��� alpha �ͷָ��� ","
    char *p = strtok(alpha, ",");

    // ѭ����ӡÿ���ָ���� token
    while (p != NULL) {
        // ʾ�����: token = one����һ�Σ�, two���ڶ��Σ�, three�������Σ�
        printf("token = %s\n", p);

        // �����ָ���� NULL �Լ��������ϴε��ַ���
        p = strtok(NULL, ",");
    }

    // ʾ�����: �ָ��ԭ�ַ�����Ϊ: one
    printf("�ָ��ԭ�ַ�����Ϊ: %s\n", alpha);

    // ��ӡ���зָ�
    printf("\n");
}

// atoi/atof/atol �������ܣ����ַ���ת��Ϊ��Ӧ���͵���ֵ��int��float��long��
void testAtoi() {
    // ��ӡ���Ժ����ı���
    printf("���� atoi/atof/atol ���� - �ַ���ת��ֵ\n");

    // �����ַ����� str1����ʼ��Ϊ "   +10"
    char str1[] = "   +10";

    // �����ַ����� str2����ʼ��Ϊ "0.123"
    char str2[] = "0.123";

    // ʹ�� atoi �� str1 ת��Ϊ����
    int num1 = atoi(str1);

    // ʹ�� atof �� str2 ת��Ϊ������
    double num2 = atof(str2);

    // ʾ�����: str1 = "   +10"
    printf("str1 = \"%s\"\n", str1);

    // ʾ�����: atoi(str1) = 10
    printf("atoi(str1) = %d\n", num1);

    // ʾ�����: str2 = "0.123"
    printf("str2 = \"%s\"\n", str2);

    // ʾ�����: atof(str2) = 0.123000
    printf("atof(str2) = %lf\n", num2);

    // ��ӡ���зָ�
    printf("\n");
}

// ��������������������
int main() {
    // ���� testScanf ���������� scanf
    // testScanf();

    // ���� testGets ���������� gets��ע�͵����򲻰�ȫ��
    // testGets();  // ע�͵�����Ϊ gets �ѷ���

    // ���� testFgets ���������� fgets
    // testFgets();

    // ���� testPuts ���������� puts
    testPuts();

    // ���� testFputs ���������� fputs
    testFputs();

    // ���� testStrlen ���������� strlen
    testStrlen();

    // ���� testStrcpy ���������� strcpy/strncpy
    testStrcpy();

    // ���� testStrcmp ���������� strcmp/strncmp
    testStrcmp();

    // ���� testStrcat ���������� strcat/strncat
    testStrcat();

    // ���� testSprintf ���������� sprintf
    testSprintf();

    // ���� testSscanf ���������� sscanf
    testSscanf();

    // ���� testStrchrStrstr ���������� strchr/strstr
    testStrchrStrstr();

    // ���� testStrtok ���������� strtok
    testStrtok();

    // ���� testAtoi ���������� atoi/atof/atol
    testAtoi();

    // ���� 0����ʾ������������
    return 0;
}