#include <iostream>

using namespace std;

int main() {
	unsigned short num;
	unsigned short num_count;
	unsigned short result;

	cout << "���ڸ� ���� ������ ������� �Է����ּ���.(�ִ�: 12345) >> ";
	cin >> num;

	if (num <= 12345) {
		num_count = num % 10; // sd = 5
		result = num_count;

		cout << "�ٲ� ���ڴ� ";
		for (int i = 0; i < num_count; i++) {
			cout << result;
			result--;
		}
		cout << "�Դϴ�.\n";
	}
	else cout << "���� �ʹ� Ů�ϴ�.\n";
	
	return 0;
}