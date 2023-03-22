#include <iostream>
#include <conio.h>

// 아스키코드
#define ESC 27 
#define Enter 13
#define Max_Length 30

using namespace std;

int RomAsNum(char c);
bool Exception_Handling(char c, int text_length);

int i = 0;
int result = 0;
char str[Max_Length];
bool is_exception = false;

int main() {
	while (true) {
		result = 0;
		i = 0;

		printf("로마 숫자를 입력해주세요. >> ");

		do
		{
			str[i] = _getch();
			
			printf("%c", str[i]);

			result += RomAsNum(str[i]); // 문자 로마 숫자로 변환하기
			if (str[i] == 'V' && str[i - 1] == 'I') result -= 2; // 로마 숫자 예외처리 ex) XI, IV...
			if (str[i] == 'X' && str[i - 1] == 'I') result -= 2;
			if (str[i] == 'L' && str[i - 1] == 'X') result -= 20;

			Exception_Handling(str[i], i);

		} while (str[i++] != Enter);

		if (is_exception) printf("\n로마 숫자가 아닌 다른 문자가 입력되었거나 문자열이 너무 깁니다.\n");
		else printf("\n변환된 로마 숫자 >> %d\n", result);
	}
	return 0;
}

bool Exception_Handling(char c, int text_length) {
	if (c == 73 || c == 86 || c == 88 || c == 76 || c == 67 || c == 68 || c == 77) { }
	else if (c == Enter) {}
	else if (c == ESC) { exit(0); }
	else { is_exception = true; }
	if(text_length >= Max_Length) { is_exception = true; }

	return is_exception;
};

// 로마 숫자 -> 아라비아 숫자
int RomAsNum(char c) {
	switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
	}
}