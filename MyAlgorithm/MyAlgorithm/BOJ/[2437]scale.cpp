#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;

	int *arr = new int[N];
	int *arrSum = new int[N];
	int min = 1;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	if (arr[0] != 1) {
		min = 1;
	}
	else {
		arrSum[0] = arr[0];
		for (int i = 1; i < N; i++) {
			arrSum[i] = arrSum[i - 1] + arr[i];
			min = arrSum[i] + 1;
			if (i == N - 1) {
				break;
			}
			if (min < arr[i + 1])
				break;
		}
	}
	cout << min << endl;

	return 0;

}