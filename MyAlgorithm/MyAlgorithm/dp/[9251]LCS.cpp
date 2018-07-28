#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	int length1 = s1.size();
	int length2 = s2.size();
	int** dp = new int*[length1 + 1];
	for (int i = 0; i <= length1; i++) {
		dp[i] = new int[length2 + 1];
		fill(dp[i], dp[i] + length2 + 1, 0);
	}

	for (int i = 1; i <= length1; i++) {
		for (int j = 1; j <= length2; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}/*
	 for (int i = 1; i <= length1; i++) {
	 for (int j = 1; j <= length2; j++) {
	 cout << dp[i][j] << ' ';
	 }
	 cout << endl;
	 }*/
	cout << dp[length1][length2] << endl;

	return 0;
}