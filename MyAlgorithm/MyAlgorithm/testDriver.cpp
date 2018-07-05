#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int n;
		cin >> n;
		int dp[101];
		dp[4] = 2;
		for (int i = 5; i <= n; i++) {
			int cnt = 0;
			for (int j = 1; j <= i; j++) {
				if (i % j == 0) {
					cnt++;
				}
			}
			if (cnt % 2 == 0) {
				dp[i] = dp[i - 1];
			}else{
				dp[i] = dp[i - 1] + 1;
			}
		}
		cout << dp[n] << endl;

	}

	return 0;
}