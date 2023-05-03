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
	char input_data[5] = { ' ' }; // 동적배열 필요

	// Enter를 입력하기 전까지 문자를 계속 받아옴
	do gets(input_data);
	while (input_data == '\0');

	// '%'가 있는 지 없는 지 검사
	while (*output_type != '%' && *output_type) output_type++;

	// 만약 '%'가 있다면?
	if (*output_type++ == '%')
	{
		switch (*output_type)
		{
		case 'd':
			printf("%%d 입니다");
			break;
		case 'f':
			printf("%%f 입니다");
			break;
		case 'c':
			printf("%%c 입니다");
			break;
		case 's':
			printf("%%s 입니다");
			break;
		case 't':
			printf("%%t 입니다");
			break;
		}
	}
	return -1;
}

char Percent_D() {

	return ' ';
}