#include <iostream>
#include <conio.h>

// �ƽ�Ű�ڵ�
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

		printf("�θ� ���ڸ� �Է����ּ���. >> ");

		do
		{
			str[i] = _getch();
			
			printf("%c", str[i]);

			result += RomAsNum(str[i]); // ���� �θ� ���ڷ� ��ȯ�ϱ�
			if (str[i] == 'V' && str[i - 1] == 'I') result -= 2; // �θ� ���� ����ó�� ex) XI, IV...
			if (str[i] == 'X' && str[i - 1] == 'I') result -= 2;
			if (str[i] == 'L' && str[i - 1] == 'X') result -= 20;

			Exception_Handling(str[i], i);

		} while (str[i++] != Enter);

		if (is_exception) printf("\n�θ� ���ڰ� �ƴ� �ٸ� ���ڰ� �ԷµǾ��ų� ���ڿ��� �ʹ� ��ϴ�.\n");
		else printf("\n��ȯ�� �θ� ���� >> %d\n", result);
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

// �θ� ���� -> �ƶ��� ����
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