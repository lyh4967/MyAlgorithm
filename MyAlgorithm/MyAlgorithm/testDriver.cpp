#include <iostream>
#include <string>
#include <queue>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int n, m, k;
int answer = 0;
int length;
char map[100][100];
int visited[100][100][81];
string str;

bool isRanged(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < m;
}

int dfs(int a, int b, int cnt) {
	if (cnt == length - 1) 
		return 1;

	if (visited[a][b][cnt] != -1)
		return visited[a][b][cnt];

	visited[a][b][cnt] = 0;
	for (int i = 0; i < 4; i++) {
		for (int jump = 1; jump <= k; jump++) {
			int nA = a + dir[i][0] * jump;
			int nB = b + dir[i][1] * jump;

			if (isRanged(nA, nB) && map[nA][nB] == str[cnt + 1]) {
				visited[a][b][cnt] += dfs(nA, nB, cnt + 1);
			}
		}
	}
	return visited[a][b][cnt];
}

void bfs() {
	//while (!que.empty()) {

	//	node = que.front(); que.pop();
	//	int a = node.a; int b = node.b; int cnt = node.cnt;
	//	if (cnt == length - 1) {
	//		answer++;
	//		continue;
	//	}

	//	if (visited[a][b][cnt])
	//		continue;

	//	visited[a][b][cnt] = true;

	//	for (int i = 0; i < 4; i++) {
	//		for(int jump = 1;jump <= k; jump++){
	//			int nA = a + dir[i][0] * jump;
	//			int nB = b + dir[i][1] * jump;
	//			//cout << "log: " << nA << "," << nB << "," << cnt << endl;

	//			if (isRanged(nA, nB) && map[nA][nB] == str[cnt + 1] && !visited[nA][nB][cnt + 1]) {
	//				node.a = nA; node.b = nB; node.cnt = cnt + 1;
	//				que.push(node);
	//			}
	//		}
	//	}
	//}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fill(visited[i][j], visited[i][j] + 81, -1);
			cin >> map[i][j];
		}
	}
	cin >> str;
	length = str.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == str[0]) {
				answer += dfs(i, j, 0);
			}
		}
	}

	cout << answer << "\n";
	return 0;
}