#include <iostream>
#include <conio.h>

using namespace std;

void NumToRom(int digit, char rom_multiples_5, char rom_multiples_1);

int main() {
	int num = 0;

	while (true)
	{
		int c = _getch();
		if (c == 27) return 0;

		cout << "숫자를 입력해주세요. (1 - 3999) >> ";
		cin >> num;

		if (num >= 1 && num <= 3999) {
			// 자릿수 추출
			int four = (num / 1000);
			int three = (num % 1000) / 100;
			int two = (num % 100) / 10;
			int one = num % 10;

			for(int i = 0; i < four; i++) cout << 'M'; // 1000
			NumToRom(three, 'D', 'C'); // 500, 400, 100
			NumToRom(two, 'L', 'X'); // 50, 40, 10
			NumToRom(one, 'V', 'I'); // 5, 4, 1
			cout << '\n';
		}
		else {
			cout << "수가 너무 크거나 작습니다.\n";
		}
	}
}

void NumToRom(int digit, char rom_multiples_5, char rom_multiples_1) {
	if (digit >= 5) {
		cout << rom_multiples_5;
		digit = digit - 5;
	}

	for (int i = 0; i < digit; i++) {
		cout << rom_multiples_1;
		if (digit == 4) { cout << rom_multiples_5; break; }
	}

	
}