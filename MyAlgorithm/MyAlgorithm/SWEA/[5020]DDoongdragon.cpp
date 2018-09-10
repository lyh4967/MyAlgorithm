#include <iostream>
using namespace std;

int n, m;
int Xs, Ys, Xe, Ye;
int** map;
long long** visited;
int dir1[4] = { 0,1,0,-1 };
int dir2[4] = { 1,0,-1,0 };

int abs_m(int a) {
	return a < 0 ? -a : a;
}

bool isRanged(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < m;
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

long long dfs(int a, int b) {

	if (a == Xe && b == Ye) {
		return 1;
	}
	if (visited[a][b] != -1)
		return visited[a][b];
	//cout << "log: " << a << "," << b << endl;

	visited[a][b] = 0;
	for (int i = 0; i < 4; i++) {
		int nextA = a + dir1[i];
		int nextB = b + dir2[i];

		if (isRanged(nextA, nextB) && abs_m(map[a][b])<abs_m(map[nextA][nextB])) {
			if (map[a][b] < 0) {//현재가 음식
				if (map[nextA][nextB] > 0) {
					visited[a][b] += dfs(nextA, nextB);
				}
			}
			else {//현재가 음료
				visited[a][b] += dfs(nextA, nextB);
			}
		}
	}
	return visited[a][b];
}

int main() {

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> n >> m;
		cin >> Xs >> Ys >> Xe >> Ye;
		map = new int*[n];
		visited = new long long*[n];
		for (int i = 0; i < n; i++) {
			map[i] = new int[m];
			visited[i] = new long long[m];
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				visited[i][j] = -1;
			}
		}

		long long answer = dfs(Xs, Ys);
		//print();

		if (answer == 0)
			cout << "#" << test << " " << "Sorry, princess XD" << endl;
		else
			cout << "#" << test << " " << answer << endl;
		for (int i = 0; i < n; i++) {
			delete[] map[i];
			delete[] visited[i];
		}
	}

	return 0;
}