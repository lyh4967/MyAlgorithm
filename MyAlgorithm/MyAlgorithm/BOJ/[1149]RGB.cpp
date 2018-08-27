#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[1001][3];

int main(){

	cin >> N;
	for (int i = 0; i < N; i++){
		int r, g, b;
		cin >> r >> g >> b;
		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
	}
	int dp[1001][3];

	for (int i = 0; i < N; i++){
		for (int j = 0; j < 3; j++){
			if (i == 0){
				dp[i][j] = arr[i][j];
			}
			else{
				if (j == 0){
					dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][j];
				}
				else if (j == 1){
					dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][j];
				}
				else{
					dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][j];
				}
			}
		}
	}
	int min = dp[N - 1][0];
	for (int i = 0; i < 3; i++){
		if (min>dp[N - 1][i])
			min = dp[N - 1][i];
	}
	cout << min << endl;
	return 0;

}