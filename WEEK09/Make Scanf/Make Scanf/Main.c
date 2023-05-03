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
	// '%'가 있는 지 없는 지 검사
	while (*text != '%' && *text) text++;

	// 만약 '%'가 있다면?
	if (*text++ == '%')
	{
		if (*text == 'd') { printf("%%d 입니다"); }
		if (*text == 'f') printf("%%f 입니다.");
		if (*text == 'c') { printf("%%c 입니다."); }
		if (*text == 's') printf("%%s 입니다.");
		if (*text == 't') printf("%%t 입니다.");
	}

	return -1;
}