#include <iostream>

using namespace std;

int main() {
	unsigned short num;
	unsigned short num_count;
	unsigned short result;

	cout << "숫자를 작은 수부터 순서대로 입력해주세요.(최댓값: 12345) >> ";
	cin >> num;

	if (num <= 12345) {
		num_count = num % 10; // sd = 5
		result = num_count;

		cout << "바뀐 숫자는 ";
		for (int i = 0; i < num_count; i++) {
			cout << result;
			result--;
		}
		cout << "입니다.\n";
	}
	else cout << "수가 너무 큽니다.\n";
	
	return 0;
}