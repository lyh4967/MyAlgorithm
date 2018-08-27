#include <iostream>
using namespace std;

int priceArr[1001];
int dp[1001];
int** graph;
int N, K;

int dfs(int target){
	if (dp[target] != -1)
		return dp[target];
	int result = 0;
	int max = 0;
	for (int i = 1; i <= N; i++){
		if (graph[i][target] == 1){
			result = dfs(i);
			if (result > max)
				max = result;
		}
	}
	dp[target] = max + priceArr[target];
	return dp[target];

}

int main(){

	int T;
	cin >> T;
	for (int test_num = 0; test_num < T; test_num++){

		cin >> N >> K;

		for (int i = 1; i <= N; i++){
			int tmp;
			cin >> tmp;
			priceArr[i] = tmp;
		}

		graph = new int*[N + 1];
		for (int i = 0; i <= N; i++)
			graph[i] = new int[N + 1];

		for (int i = 0; i < K; i++){
			int W1;
			int W2;
			cin >> W1 >> W2;
			graph[W1][W2] = 1;

		}
		fill(dp, dp + N + 1, -1);

		int target;
		cin >> target;

		cout << dfs(target) << endl;

	}

	return 0;

}