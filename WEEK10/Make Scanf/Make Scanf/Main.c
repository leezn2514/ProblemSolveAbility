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

	printf("내 이름은 %s이고 이번학기 점수는 %d점이고 성적은 %c를 받았습니다", s, d, c);

	return 0;
}

int MyScanf(const char* output_type, void* ap_data) {
	char* buffer = (char*)malloc(32);

	// Enter를 입력하기 전까지 문자를 계속 받아옴
	do gets(buffer);
	while (buffer == '\0');

	// '%'가 있는 지 없는 지 검사
	while (*output_type != '%' && *output_type) output_type++;

	// 만약 '%'가 있다면?
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
			printf("%%t 입니다");
			break;
		}
	}

	free(buffer);
	return -1;
}