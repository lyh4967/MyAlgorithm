#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {

		int n;
		cin >> n;
		int** stickers = new int*[2];

		//스티커배열 생성
		for (int i = 0; i < 2; i++) {
			stickers[i] = new int[n];
		}

		//스티커 입력
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> stickers[i][j];
			}
		}

		//dp
		int* dp = new int[n];
		int selecRow;// domain: 0 or 1
		dp[0] = max(stickers[0][0], stickers[1][0]);
		if (stickers[0][0] + stickers[1][1] < stickers[1][0] + stickers[0][1]) {
			dp[1] = stickers[1][0] + stickers[0][1];
			selecRow = 0;
		}
		else {
			dp[1] = stickers[0][0] + stickers[1][1];
			selecRow = 1;
		}




		for (int i = 2; i < n; i++) {
			if (selecRow == 0) {
				if (dp[i - 2] + stickers[0][i] < dp[i - 1] + stickers[1][i]) {
					dp[i] = dp[i - 1] + stickers[1][i];
					selecRow = 1;
				}
				else if (dp[i - 2] + stickers[0][i] == dp[i - 1] + stickers[1][i]) {
					if (stickers[0][i] < stickers[1][i]) {
						dp[i] = dp[i - 1] + stickers[1][i];
						selecRow = 1;
					}
					else {
						dp[i] = dp[i - 1] + stickers[0][i];
						selecRow = 0;
					}
				}
				else {
					dp[i] = dp[i - 2] + stickers[0][i];
					selecRow = 0;
				}
			}
			else {
				if (dp[i - 2] + stickers[1][i] < dp[i - 1] + stickers[0][i]) {
					dp[i] = dp[i - 1] + stickers[0][i];
					selecRow = 0;
				}
				else if (dp[i - 2] + stickers[1][i] == dp[i - 1] + stickers[0][i]) {
					if (stickers[0][i] < stickers[1][i]) {
						dp[i] = dp[i - 1] + stickers[1][i];
						selecRow = 1;
					}
					else {
						dp[i] = dp[i - 1] + stickers[0][i];
						selecRow = 0;
					}
				}
				else {
					dp[i] = dp[i - 2] + stickers[1][i];
					selecRow = 1;
				}
			}
		}
		for (int i = 0; i < n; i++)
			cout << dp[i] << ' ';
		cout << endl;
		//cout << dp[n-1] << endl;
	}

	return 0;
}