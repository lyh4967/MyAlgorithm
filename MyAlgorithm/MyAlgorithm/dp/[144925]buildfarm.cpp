#include <iostream>
using namespace std;

#define MAX_M 1000
#define MAX_N 1000

int min_m(int a, int b, int c) {
	int result = a;
	if (result > b)
		result = b;
	if (result > c)
		result = c;
	return result;
}
int main() {

	int m, n;
	cin >> m >> n;
	int dp[2][1001];
	for (int i = 0; i < 2; i++) {
		fill(dp[i], dp[i] + 1001, 0);
	}
	int answer = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int num; cin >> num;
			if (num == 0) {
				dp[1][j] = min_m(dp[1][j - 1], dp[0][j], dp[0][j - 1]) + 1;
				if (dp[1][j] > answer)
					answer = dp[1][j];
			}
			else {
				dp[1][j] = 0;
			}
		}
		for (int j = 1; j <= n; j++)
			dp[0][j] = dp[1][j];

		/*cout <<"log: "<< endl;
		for (int j = 1; j <= n; j++)
		cout << dp[0][j] << " ";
		cout << endl;*/
	}
	cout << answer << endl;
}