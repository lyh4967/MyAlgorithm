#include<iostream>
#include <algorithm>
#include <queue>
using namespace std;

int M, N;//M:가로, N:세로
int cnt = 0;

int direction[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

bool BoundTest(int i, int j){
	return (0 <= i && i < N) && (0 <= j && j < M);
}

void bfs(int** graph, int** check){
	queue <pair<int, int>> q;
	for (int i = 0; i < N; i++){//처음 익어있던 과일들을 큐에 넣어준다.
		for (int j = 0; j < M; j++){
			if (graph[i][j] == 1){
				q.push(make_pair(i, j));
				check[i][j]++;
			}
		}
	}
	while (!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){//큐에 있는요소들을 차례로 꺼내며 익는데까지 걸리는날짜를 차례차례checkArr에 입력한다.
			int nextX = tmp.first + direction[i][0];
			int nextY = tmp.second + direction[i][1];
			if (BoundTest(nextX, nextY) && (graph[nextX][nextY] == 0) && (check[nextX][nextY] == -1)){
				graph[nextX][nextY] = 1;
				q.push(make_pair(nextX, nextY));
				check[nextX][nextY] = check[tmp.first][tmp.second] + 1;
			}
		}
	}
}

int main(){

	cin >> M >> N;//M:가로, N:세로
	int** graphArr = new int*[N];
	int** checkArr = new int*[N];
	for (int i = 0; i < N; i++)
		graphArr[i] = new int[M];

	for (int i = 0; i < N; i++)
		checkArr[i] = new int[M];

	for (int i = 0; i < N; i++)//그래프 생성
	for (int j = 0; j < M; j++)
		cin >> graphArr[i][j];
	for (int i = 0; i < N; i++)//방문록 생성
	for (int j = 0; j < M; j++)
		checkArr[i][j] = -1;

	bfs(graphArr, checkArr);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (graphArr[i][j] == 0){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	int maxDays = -1;
	for (int i = 0; i < N; i++){//checkArr에 있는 요소들중 가장 큰값을 출력한다.
		for (int j = 0; j < M; j++){
			if (checkArr[i][j] >maxDays){
				maxDays = checkArr[i][j];
			}
		}
	}
	cout << maxDays << endl;

	return 0;
}