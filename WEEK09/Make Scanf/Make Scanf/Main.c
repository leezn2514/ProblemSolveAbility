#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h> 
#include <malloc.h>

#define ENTER 13

int main() {
	char* i_data = (char*)malloc(32);
	gets(i_data);

	//printf("%c", i_data[1]);
	my_Scanf("%c", &i_data);
	printf("%c", i_data);

	free(i_data);

	return 0;
}

int my_Scanf(char* text, void* ap_data) {
	// '%'�� �ִ� �� ���� �� �˻�
	while (*text != '%' && *text) text++;

	// ���� '%'�� �ִٸ�?
	if (*text++ == '%')
	{
		if (*text == 'd') { printf("%%d �Դϴ�"); }
		if (*text == 'f') printf("%%f �Դϴ�.");
		if (*text == 'c') { printf("%%c �Դϴ�."); }
		if (*text == 's') printf("%%s �Դϴ�.");
		if (*text == 't') printf("%%t �Դϴ�.");
	}

	return -1;
}