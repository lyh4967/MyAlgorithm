#include <iostream>
#include <queue>
using namespace std;

int N;
int map[20][20];
bool visited[101];
int dir1[4][2] = { { 1,1 },{ 1,-1 },{ -1,-1 },{ -1,1 } };

int sA, sB;
int answer = -1;
bool isRanged(int a, int b) {
	return 0 <= a && a < N && 0 <= b && b < N;
}
//시계방향으로 1 2 3 4 , 처음은 0

void print() {
	cout << endl;
	for (int i = 1; i <= 10; i++) {
		cout << visited[i] << " ";
	}
	cout << endl;
}
void dfs(int a, int b, int dir, int dirCnt, int cnt) {

	if (dirCnt >= 5) return;

	//cout << "log: " << a << "," << b << endl;
	visited[map[a][b]] = true;
	for (int i = 0; i < 4; i++) {
		int nA = a + dir1[i][0];
		int nB = b + dir1[i][1];
		if (nA == sA && nB == sB && dirCnt >= 3 && cnt >= 4) {
			if (answer < cnt) {
				answer = cnt;
			}
			visited[map[a][b]] = false;
			return;
		}
		if (isRanged(nA, nB) && !visited[map[nA][nB]]) {
			dfs(nA, nB, i, i == dir ? dirCnt : dirCnt + 1, cnt + 1);
		}

	}
	visited[map[a][b]] = false;

}

int main() {

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		answer = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				//checked[i][j] = 0;
			}
		}

		fill(visited, visited + 101, false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sA = i; sB = j;
				dfs(i, j, -1, 0, 1);
			}
		}
		cout << "#" << test << " " << answer << endl;

	}

	return 0;

}