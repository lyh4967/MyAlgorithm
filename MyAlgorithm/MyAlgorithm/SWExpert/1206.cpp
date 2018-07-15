#include <iostream>
using namespace std;

int dir[4] = { -2,-1,1,2 };

int main() {

	for (int test = 1; test <= 10; test++) {
		int n;
		cin >> n;
		int result = 0;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 2; i <= n - 3; i++) {
			int min = 255;
			bool flag = true;
			for (int j = 0; j < 4; j++) {

				if (arr[i] - arr[i + dir[j]] <= 0) {
					flag = false;
					break;
				}
				else {
					if (arr[i] - arr[i + dir[j]] < min) {
						min = arr[i] - arr[i + dir[j]];
					}
				}
			}
			if (flag) {
				result += min;
			}
		}

		cout << "#" << test << ' ' << result << endl;

	}

	return 0;
}