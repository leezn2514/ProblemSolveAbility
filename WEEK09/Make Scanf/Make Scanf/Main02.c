#include <stdio.h>
#include <string.h>

/*
 * %d %f %c %s \t
 * 5���� Ű���� �����ϱ�
 * ���ڿ��� �����̶� ��ġ���� ���� ��� return -1�� ���� ����ص� ��
 */

int vr_scanf(const char* str, void* a, void* b, void* c, void* d)
{
    char input_str[1024];  // �ӽ� ���ڿ�
    char* token;         // ���ڿ� �Ľ��� ���� ������
    int index = 0;       // ������ ������ �����ϱ� ���� �ε���

    gets(input_str);

    return 0;   //return -1;
}

int main()
{
    int a;
    char b;
    float c;
    char d[1024];

    printf("Enter values: ");

    int result = vr_scanf("%d|%c %f,%s", &a, &b, &c, d);

    if (result == 0)
        printf("Values entered: %d %c %f %s\n", a, b, c, d);
    else
        printf("Error\n");

    return 0;
}