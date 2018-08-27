#include <iostream> 
using namespace std;

int main() {

	int n;
	cin >> n;
	int arr[1000];
	int dp[1000];
	fill(dp, dp + 1000, 1);
	for (int mu = 0; mu < n; mu++) {
		cin >> arr[mu];
		int tempMax = 0;
		for (int i = mu; i >= 0; i--) {
			if (arr[mu] > arr[i]) {
				if (dp[i] > tempMax) {
					tempMax = dp[i];
				}
			}
		}
		dp[mu] = tempMax + 1;
	}
	int maxNum = 0;/*
				   for (int i = 0; i < n; i++)
				   cout << dp[i] << ' ';
				   cout << endl;*/
	for (int i = 0; i < n; i++) {
		if (maxNum < dp[i])
			maxNum = dp[i];
	}
	cout << maxNum << endl;




	return 0;
}