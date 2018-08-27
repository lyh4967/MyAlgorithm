#include <iostream>
using namespace std;

int N;
bool CheckBound(int a, int b) {
	return (0 <= a && a < N) && (0 <= b && b < N);
}

int main() {


	cin >> N;
	int arr[100][100];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	long long dp[100][100];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0)
				continue;
			int nextA = i + arr[i][j];
			int nextB = j + arr[i][j];
			if (CheckBound(nextA, j)) {
				dp[nextA][j] += dp[i][j];
			}
			if (CheckBound(i, nextB)) {
				dp[i][nextB] += dp[i][j];
			}
		}
	}

	cout << dp[N - 1][N - 1] << endl;

	return 0;
}