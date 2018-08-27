#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	int* stairs = new int[N];
	int* dp = new int[N];

	for (int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		stairs[i] = temp;
	}
	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
	for (int i = 3; i < N; i++){
		dp[i] = max(stairs[i] + stairs[i - 1] + dp[i - 3], stairs[i] + dp[i - 2]);
	}
	cout << dp[N - 1] << endl;

}