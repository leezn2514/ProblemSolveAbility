#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h> 
#include <malloc.h>

int main() {
	int d = 0;
	char c = ' ';
	char s[10] = " ";
	float f = 0;

	MyScanf("%s", &s);
	MyScanf("%d", &d);
	MyScanf("%c", &c);

	printf("�� �̸��� %s�̰� �̹��б� ������ %d���̰� ������ %c�� �޾ҽ��ϴ�", s, d, c);

	return 0;
}

int MyScanf(const char* output_type, void* ap_data) {
	char* buffer = (char*)malloc(32);

	// Enter�� �Է��ϱ� ������ ���ڸ� ��� �޾ƿ�
	do gets(buffer);
	while (buffer == '\0');

	// '%'�� �ִ� �� ���� �� �˻�
	while (*output_type != '%' && *output_type) output_type++;

	// ���� '%'�� �ִٸ�?
	if (*output_type++ == '%' && buffer != NULL)
	{
		switch (*output_type)
		{
		case 'd':
			 *(int *)ap_data = atoi(buffer);
			break;
		case 'f':
			//*(float*)ap_data = atof(buffer);
			break;
		case 'c':
			*(char *)ap_data = buffer[0];
			break;
		case 's':
			strcpy(ap_data, buffer);
			break;
		case 't':
			printf("%%t �Դϴ�");
			break;
		}
	}

	free(buffer);
	return -1;
}