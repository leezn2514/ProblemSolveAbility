#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h> 
#include <malloc.h>

int main() {
	char a;

	MyScanf("%d", &a);

	return 0;
}

int MyScanf(const char* output_type, void* ap_data) {
	//char* input_data = (char*)malloc(32);
	char input_data[5] = { ' ' }; // �����迭 �ʿ�

	// Enter�� �Է��ϱ� ������ ���ڸ� ��� �޾ƿ�
	do gets(input_data);
	while (input_data == '\0');

	// '%'�� �ִ� �� ���� �� �˻�
	while (*output_type != '%' && *output_type) output_type++;

	// ���� '%'�� �ִٸ�?
	if (*output_type++ == '%')
	{
		switch (*output_type)
		{
		case 'd':
			printf("%%d �Դϴ�");
			break;
		case 'f':
			printf("%%f �Դϴ�");
			break;
		case 'c':
			printf("%%c �Դϴ�");
			break;
		case 's':
			printf("%%s �Դϴ�");
			break;
		case 't':
			printf("%%t �Դϴ�");
			break;
		}
	}
	return -1;
}

char Percent_D() {

	return ' ';
}