#include <iostream>
using namespace std;

int n;
long long arr[1000000];
long long dp[1000000];
//void dfs(int index, int num, int money) {
//
//	if (index == n - 1) {
//		if (maxMoney < money)
//			maxMoney = money;
//		return;
//	}
//	
//	dfs(index + 1, num + 1, money - arr[index+1]);
//	dfs(index + 1, num, money);
//	if(num>0)
//		dfs(index + 1, 0, money + num * arr[index+1]);
//	
//}

void print() {
	for (int i = 0; i < n; i++) {
		cout << dp[i] << ' ';
	}
	cout << endl;
}
int main() {

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int index = 0;
		dp[0] = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] < arr[i]) {
				long long add = 0;
				if (arr[i] > arr[index]) {
					for (int j = i - 1; j >= 0; j--) {
						if (arr[i] > arr[j])
							add += arr[i] - arr[j];
					}
					dp[i] = add;
				}
				else {
					for (int j = index + 1; j < i; j++) {
						if (arr[i] > arr[j])
							add += arr[i] - arr[j];
					}
					dp[i] = dp[index] + add;
				}
				if (arr[i] > arr[i + 1] && i != n-1)
					index = i;
			}else{
				dp[i] = dp[i - 1];
			}
		}
		//print();

		cout << "#"<<test<<" "<< dp[n-1] << endl;
	}

	return 0;
}