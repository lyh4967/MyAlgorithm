#include <iostream>
using namespace std;

int min_m(int a, int b) {
	return a < b ? a : b;
}
int max_m(int a, int b) {
	return a > b ? a : b;
}



int main() {

	int arr[1001];

	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 2;
	arr[3] = 3;
	bool flag = true;
	while (flag) {
		int index; cin >> index;
		if (index == 0)
			break;
		for (int i = 4; i <= 1000; i++) {
			if (i % 2 == 0) {//Â¦¼ö
				arr[i] = min_m(i, arr[i / 2] + 2);
			}
			else {//Â¦¼ö
				bool flag = false;
				arr[i] = i;
				for (int j = i / 2; j >= 2; j--) {
					if (i%j == 0) {
						arr[i] = min_m(arr[i], arr[j] + i / j);
						flag = true;
						break;
					}
				}
				if (flag == false)
					arr[i] = min_m(arr[i], arr[i / 2 + 1] + 3);
			}
		}
		cout << arr[index] << endl;
	}

	return 0;
}