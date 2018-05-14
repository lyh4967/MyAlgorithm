#include <iostream>
using namespace std;

int main() {

	int bill;

	cin >> bill;
	int change = 1000 - bill;

	int cnt = 0;
	while (change >= 5) {
		if (change / 500 != 0) {
			cnt += change / 500;
			change = change % 500;
		}
		else if (change / 100 != 0) {
			cnt += change / 100;
			change = change % 100;
		}
		else if (change / 50 != 0) {
			cnt += change / 50;
			change = change % 50;
		}
		else if (change / 10 != 0) {
			cnt += change / 10;
			change = change % 10;
		}
		else if (change / 5 != 0) {
			cnt += change / 5;
			change = change % 5;
		}
	}
	cnt += change;
	cout << cnt << endl;
	return 0;

}