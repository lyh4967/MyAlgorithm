#include <iostream>
using namespace std;

int main() {

	int testNum;
	cin >> testNum;
	for (int test = 1; test <= testNum; test++) {

		int n;
		cin >> n;
		int arr[401];
		fill(arr, arr + 401, 0);
		for (int i = 0; i < n; i++) {
			int from, to;
			cin >> from >> to;
			if (from > to) {
				int temp = from;
				from = to;
				to = temp;
			}
			for (int j = from; j <= to; j++) {
				arr[j] += 1;
			}
			if (from % 2 == 0) {
				arr[from - 1] += 1;
			}
			if (to % 2 == 1) {
				arr[to + 1] += 1;
			}
		}
		int max = 0;
		for (int i = 1; i <= 400; i++) {
			if (max < arr[i])
				max = arr[i];
		}
		cout << "#" << test << ' ' << max << endl;

	}

	return 0;

}