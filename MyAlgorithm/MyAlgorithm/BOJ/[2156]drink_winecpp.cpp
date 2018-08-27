#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10000];
int dp[10000];

int Max(int a, int b, int c){
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}

int main(){

	cin >> n;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = Max(dp[0] + arr[2], arr[1] + arr[2], arr[0] + arr[1]);

	for (int i = 3; i < n; i++){
		int maxNum = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
		maxNum = max(maxNum, dp[i - 1]);
		dp[i] = maxNum;
	}
	cout << dp[n - 1] << endl;



	return 0;
}