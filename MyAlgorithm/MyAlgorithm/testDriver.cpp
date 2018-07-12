#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	int** dp = new int* [s2.size()+1];
	for (int i = 0; i <= s2.size(); i++)
		dp[i] = new int[s1.size()+1];


	for (int i = 0; i <= s2.size(); i++) {
		for (int j = 0; j <= s1.size(); j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s2[i-1] == s1[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	/*
	for (int i = 0; i <= s2.size(); i++) {
		for (int j = 0; j <= s1.size(); j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	cout << dp[s2.size()][s1.size()] << endl;
	return 0;

}