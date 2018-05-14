#include <iostream>
#include <vector>
using namespace std;

int graph[501][501];
int M, N;
int direction[4][2] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
int dp[501][501] = { -1 };
int cnt = 0;
bool Boundry(int i, int j){
	return ((0 <= i&&i < M) && (0 <= j&&j < N));
}
int dfs(int a, int b){

	if (dp[a][b] != 0)
		return dp[a][b];
	for (int i = 0; i < 4; i++){
		int dx = a + direction[i][0];
		int dy = b + direction[i][1];
		if (Boundry(dx, dy) && (graph[dx][dy] < graph[a][b])){//범위체크
			dp[a][b] += dfs(dx, dy);
		}
	}
	return dp[a][b];
}

int main(){
	cin >> M >> N;
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			int tmp;
			cin >> tmp;
			graph[i][j] = tmp;
		}
	}
	dp[M - 1][N - 1] = 1;
	/*
	for (int i = 0; i < M; i++){
	for (int j = 0; j < N; j++){
	cout<<dp[i][j]<<' ';
	}
	cout << endl;
	}*/
	cout << dfs(0, 0) << endl;
}