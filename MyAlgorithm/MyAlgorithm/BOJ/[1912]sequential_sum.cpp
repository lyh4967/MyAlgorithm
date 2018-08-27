#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int* dp = new int[n];
	fill(dp, dp + n, 0);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++){
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}


	int max = dp[0];
	for (int i = 1; i < n; i++){
		if (max < dp[i])
			max = dp[i];
	}
	cout << max << endl;

	return 0;

}