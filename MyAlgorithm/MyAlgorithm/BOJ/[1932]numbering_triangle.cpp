#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 501;

int main(){


	int n;
	cin >> n;
	int **tri;
	tri = new int*[n];
	for (int i = 0; i < n; i++)
		tri[i] = new int[n];

	int **dp;
	dp = new int*[n];
	for (int i = 0; i < n; i++)
		dp[i] = new int[n];

	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			int tmp;
			cin >> tmp;
			tri[i][j] = tmp;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			if (i == 0 && j == 0){
				dp[i][j] = tri[i][j];//base
			}
			else if (i == j){
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];//´ë°¢¼±
			}
			else if (j == 0){
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			}
			else{
				dp[i][j] = tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
	int max = dp[n - 1][0];
	for (int i = 1; i < n; i++){
		if (max < dp[n - 1][i])
			max = dp[n - 1][i];
	}

	cout << max << endl;


}