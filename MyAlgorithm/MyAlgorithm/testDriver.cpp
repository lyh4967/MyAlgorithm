#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int min_m(int a, int b) {
	return a > b ? b : a;
}
struct Node {
	int a;
	int b;
	int cnt;
	int dir;
};
int N;
int map[100][100];
int visited[100][100];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool isRanged(int a, int b) {
	return 0 <= a && a < N && 0 <= b && b < N;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

void print2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
int dfs(int a, int b) {

	if (a == N - 1 && b == N - 1) {
		return 0;
	}
	if (visited[a][b] != -1) {
		return visited[a][b];
	}

	visited[a][b] = 0;
	for (int i = 0; i < 4; i++) {
		int nA = a + dir[i][0];
		int nB = b + dir[i][1];

		if (isRanged(nA, nB)) {
			visited[a][b] += dfs(nA, nB);
			visited[a][b] += map[a][b];
		}
	}
	return visited[a][b];

}

int main() {

	int T; cin >> T;

	for (int test = 1; test <= T; test++) {

		cin >> N;
		int answer = 987654321;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d",&map[i][j]);
				visited[i][j] = -1;
			}
		}
		print2();
		/*queue<Node> que;
		Node node;
		node.a = 0; node.b = 0; node.cnt = 0; node.dir = 0;

		que.push(node);
		while (!que.empty()) {
			node = que.front(); que.pop();
			int a = node.a; int b = node.b; int cnt = node.cnt; int nDir = node.dir;
			if (a == N - 1 && b == N - 1) {
				if (answer > cnt) {
					answer = cnt;
				}
				continue;
			}
			if (visited[a][b][nDir] == 1)
				continue;
			visited[a][b][nDir] = 1;

			for (int i = 0; i < 4; i++) {
				int nA = a + dir[i][0];
				int nB = b + dir[i][1];
				if (isRanged(nA, nB) && !visited[nA][nB][nDir]) {
					node.a = nA; node.b = nB; node.cnt = cnt + map[nA][nB]; node.dir = i;
					que.push(node);
				}
			}

		}*/
		dfs(0, 0);
		print();

		answer = min_m(visited[0][1], visited[1][0]);
		cout <<"#"<<test<<" "<< answer << endl;

	}

	return 0;
}