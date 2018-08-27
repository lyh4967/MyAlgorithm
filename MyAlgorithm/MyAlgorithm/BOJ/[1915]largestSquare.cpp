#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int min_t(int a, int b, int c) {
	int result = a;
	if (result > b)
		result = b;
	if (result > c)
		result = c;
	return result;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int dp[3][1001];
	int answer = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 1; j <= m; j++) {
			int num = str[j - 1] - '0';
			if (num == 1) {
				dp[1][j] = min_t(dp[0][j - 1], dp[0][j], dp[1][j - 1]) + 1;
				if (dp[1][j] > answer)
					answer = dp[1][j];
			}
			else
				dp[1][j] = 0;
		}

		for (int j = 1; j <= m; j++) {
			dp[0][j] = dp[1][j];
		}

	}
	cout << answer * answer << endl;

	return 0;
}