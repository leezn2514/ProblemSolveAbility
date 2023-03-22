#include <iostream>
#include <conio.h>

#define ESC 27 // 아스키코드
#define Enter 13
#define Max_Length 5

using namespace std;
void NumToRom(int digit, char rom_multiples_5, char rom_multiples_1);

int main() {
	int num, i = 0;
	char str[Max_Length];
	bool is_integer = false;

	printf ("숫자를 입력해주세요. (1 - 3999) >> ");
	do
	{
		str[i] = _getch();
		printf("%c", str[i]);

	} while (str[i++] != ESC || str[i++] != Enter);

	
		//if (num >= 1 && num <= 3999) {
		//	// 자릿수 추출
		//	int thousands = (num / 1000);
		//	int hundreds = (num % 1000) / 100;
		//	int tens = (num % 100) / 10;
		//	int units = num % 10;

		//	for(int i = 0; i < thousands; i++) cout << 'M'; // 1000
		//	NumToRom(hundreds, 'D', 'C'); // 500, 400, 100
		//	NumToRom(tens, 'L', 'X'); // 50, 40, 10
		//	NumToRom(units, 'V', 'I'); // 5, 4, 1
		//	cout << '\n';
}
		
	


void NumToRom(int digit, char rom_multiples_5, char rom_multiples_1) {
	if (digit >= 5) {
		printf("%d", rom_multiples_5);
		digit = digit - 5;
	}
	for (int i = 0; i < digit; i++) {
		printf("%d", rom_multiples_1);
		if (digit == 4) { printf("%d", rom_multiples_5); break; }
	}
}

void RomToNum() {

}