#include <iostream>
using namespace std;
#define MINF -987654321
int max_m(int a, int b, int c) {
	int result = a;
	if (result < b)
		result = b;
	if (result < c)
		result = c;
	return result;
}

int main() {

	int n, m;
	cin >> n >> m;
	int** dp = new int*[3];
	for (int i = 0; i < 3; i++)
		dp[i] = new int[1001];
	int arr[1001];
	for (int i = 0; i <= n; i++)
		fill(dp, dp + m + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int num; cin >> num;
			arr[j] = num;
			if (i == 1) {
				dp[2][j] = dp[2][j - 1] + arr[j];
			}
			else {
				int tempMax = 0;

				for (int k = j + 1; k <= m; k++) {
					int tempSum = dp[1][k];
					for (int p = k; p > j; p--) {
						tempSum += arr[p];
					}
					if (tempMax < tempSum)
						tempMax = tempSum;
				}
				dp[2][j] = max_m(dp[i][j - 1], dp[i - 1][j], tempMax);
			}
		}
		for (int j = 1; j <= m; j++)
			dp[1][j] = dp[2][j];
	}
	cout << dp[1][m] << endl;

	return 0;
}