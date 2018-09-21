#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int a, b, cnt;
	Node() {
	}
};
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int answer = 0;
int N, M, R, C, L;
int map[50][50];
bool visited[50][50];
bool isRanged(int a, int b) {
	return 0 <= a && a < N && 0 <= b && b < M;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {

		cin >> N >> M >> R >> C >> L;
		answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				visited[i][j] = false;
			}
		}



		queue<Node> que;
		Node tmp;
		tmp.a = R; tmp.b = C; tmp.cnt = 1;
		que.push(tmp);

		while (!que.empty()) {
			Node node = que.front(); que.pop();
			int a = node.a; int b = node.b; int cnt = node.cnt;
			if (cnt == L + 1) {
				break;
			}

			if (visited[a][b] == true)
				continue;
			visited[a][b] = true;
			//cout << "log: " << a << "," << b << "," << cnt << endl;

			//answer++;

			int nA, nB;
			bool flag = false;
			if (map[a][b] == 1) {
				nA = a;
				nB = b + 1;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 3 || map[nA][nB] == 6 || map[nA][nB] == 7)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}

				nA = a + 1;
				nB = b;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 2 || map[nA][nB] == 4 || map[nA][nB] == 7)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}

				nA = a;
				nB = b - 1;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 3 || map[nA][nB] == 4 || map[nA][nB] == 5)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}

				nA = a - 1;
				nB = b;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 2 || map[nA][nB] == 5 || map[nA][nB] == 6)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}
			}
			else if (map[a][b] == 2) {
				nA = a - 1;
				nB = b;
				flag = false;
				if (map[nA][nB] == 2 || map[nA][nB] == 1 || map[nA][nB] == 5 || map[nA][nB] == 6)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}

				nA = a + 1;
				nB = b;
				flag = false;
				if (map[nA][nB] == 2 || map[nA][nB] == 1 || map[nA][nB] == 4 || map[nA][nB] == 7)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}
			}
			else if (map[a][b] == 3) {
				nA = a;
				nB = b + 1;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 3 || map[nA][nB] == 6 || map[nA][nB] == 7)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}

				nA = a;
				nB = b - 1;
				flag = false;
				if (map[nA][nB] == 3 || map[nA][nB] == 1 || map[nA][nB] == 4 || map[nA][nB] == 5)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}
			}
			else if (map[a][b] == 4) {
				nA = a - 1;
				nB = b;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 2 || map[nA][nB] == 5 || map[nA][nB] == 6)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}
				nA = a;
				nB = b + 1;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 3 || map[nA][nB] == 6 || map[nA][nB] == 7)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}
			}
			else if (map[a][b] == 5) {
				nA = a + 1;
				nB = b;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 2 || map[nA][nB] == 4 || map[nA][nB] == 7)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}

				nA = a;
				nB = b + 1;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 3 || map[nA][nB] == 6 || map[nA][nB] == 7)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}
			}
			else if (map[a][b] == 6) {
				nA = a + 1;
				nB = b;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 2 || map[nA][nB] == 4 || map[nA][nB] == 7)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}

				nA = a;
				nB = b - 1;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 3 || map[nA][nB] == 4 || map[nA][nB] == 5)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}
			}
			else if (map[a][b] == 7) {
				nA = a - 1;
				nB = b;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 2 || map[nA][nB] == 5 || map[nA][nB] == 6)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}

				nA = a;
				nB = b - 1;
				flag = false;
				if (map[nA][nB] == 1 || map[nA][nB] == 3 || map[nA][nB] == 4 || map[nA][nB] == 5)
					flag = true;
				if (isRanged(nA, nB) && !visited[nA][nB] && flag) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1;
					que.push(node);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j])
					answer++;
			}
		}
		cout << "#" << test << " " << answer << endl;
	}

	return 0;
}