#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int* dp = new int[n];
	dp[0] = 1;
	int dpMax = 1;
	for (int i = 1; i < n; i++) {
		int	tempMax = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] > tempMax)
					tempMax = dp[j];
			}
		}
		dp[i] = tempMax + 1;
		if (dpMax < dp[i])
			dpMax = dp[i];
	}
	/*
	for (int i = 0; i < n; i++) {
	cout << dp[i] << ' ';
	}
	*/
	cout << dpMax << endl;


	return 0;

}