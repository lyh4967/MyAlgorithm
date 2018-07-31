#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {

	for (int test = 1; test <= 10; test++) {

		int n; cin >> n;
		int arr[100];
		for (int i = 0; i < 100; i++)
			cin >> arr[i];
		sort(arr, arr + 100, greater<int>());

		for (int i = 0; i < n; i++) {
			arr[0]--;
			arr[99]++;
			sort(arr, arr + 100, greater<int>());
		}
		cout << "#" << test << " " << arr[0] - arr[99] << endl;

	}

	return 0;
}