#include <iostream>
#include <algorithm>
using namespace std;

int Min(int a, int b, int c){
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}

int main(){

	int X;
	cin >> X;
	int *dp = new int[X + 1];
	int cnt = 0;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= X; i++){
		if (i % 3 == 0 && i % 2 == 0){
			dp[i] = Min(dp[i / 3] + 1, dp[i / 2] + 1, dp[i - 1] + 1);
		}
		else if (i % 3 == 0){
			dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
		}
		else if (i % 2 == 0){
			dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
		}
		else{
			dp[i] = dp[i - 1] + 1;
		}
	}
	cout << dp[X] << endl;
	return 0;
}