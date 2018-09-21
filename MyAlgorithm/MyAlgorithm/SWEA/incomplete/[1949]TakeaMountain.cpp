#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Node {
	int a; int b; int cnt; int flag;
	int chkA; int chkB; int key;
	Node() {
		chkA = -1; chkB = -1; key = 0;
		cnt = 1; flag = 0;

	}
	Node(int _a, int _b) :a(_a), b(_b) {}
};
int N, K;
int map[8][8];
vector<Node> top;
bool visited[8][8][6];
int answer = 0;
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
bool isRanged(int a, int b) {
	return 0 <= a && a < N && 0 <= b && b < N;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;

	for (int test = 1; test <= T; test++) {
		cin >> N >> K;
		answer = 0;
		int tmp_max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (tmp_max < map[i][j]) {
					tmp_max = map[i][j];
					top.clear();
					top.push_back(Node(i, j));
				}
				else if (tmp_max == map[i][j])
					top.push_back(Node(i, j));
			}
		}


		int size = top.size();

		queue<Node> que;
		for (int tm = 0; tm < size; tm++) {//봉우리 큐에 넣는다
			Node node;
			node.a = top[tm].a; node.b = top[tm].b;
			que.push(node);
			for (int fi = 0; fi < N; fi++) {
				for (int fi2 = 0; fi2 < N; fi2++) {
					fill(visited[fi][fi2], visited[fi][fi2] + 6, false);
				}
			}
			while (!que.empty()) {
				node = que.front(); que.pop();
				int a = node.a; int b = node.b; int cnt = node.cnt; int flag = node.flag;
				int chkA = node.chkA; int chkB = node.chkB; int key = node.key;

				bool solve = false;

				if (visited[a][b][key] == true)
					continue;
				if (flag == 1) {
					visited[a][b][key] = true;
				}
				else {
					visited[a][b][0] = true;
				}

				/*cout << "log: " << a << "," << b << "," << cnt << "," << flag << endl;
				cout << "chk: " << chkA << "," << chkB << "," << key << endl;
				cout << endl;*/
				for (int i = 0; i < 4; i++) {
					int nA = a + dir[i][0];
					int nB = b + dir[i][1];
					int tempKey = 0;
					if (flag == 1)
						tempKey = key;
					else
						tempKey = 0;
					if (isRanged(nA, nB) && !visited[nA][nB][tempKey]) {

						if (nA == chkA && nB == chkB) {// next가 깎은 곳
							if (map[nA][nB] - key < map[a][b]) {
								node.a = nA; node.b = nB; node.cnt = cnt + 1; node.flag = flag;
								node.chkA = chkA; node.chkB = chkB; node.key = key;
								que.push(node);
								solve = true;
							}
						}
						else if (a == chkA && b == chkB) {//지금이 깎은 곳
							if (map[nA][nB] < map[a][b] - key) {
								node.a = nA; node.b = nB; node.cnt = cnt + 1; node.flag = 2;
								node.chkA = chkA; node.chkB = chkB; node.key = key;
								que.push(node);
								solve = true;
							}
						}
						else {
							if (map[nA][nB] < map[a][b]) {//더 낮은곳
								node.a = nA; node.b = nB; node.cnt = cnt + 1; node.flag = flag;
								node.chkA = chkA; node.chkB = chkB; node.key = key;
								que.push(node);
								solve = true;
							}
							else {//높거나같은곳
								if (flag == 0 && ((map[nA][nB] - K) < map[a][b])) {
									node.a = nA; node.b = nB; node.cnt = cnt + 1; node.flag = 1;
									node.chkA = nA; node.chkB = nB; node.key = map[nA][nB] - map[a][b] + 1;
									que.push(node);
									solve = true;
								}
							}
						}
					}
				}

				if (solve == false) {
					if (answer < cnt) {
						answer = cnt;
					}
				}
			}
			//cout << "================================" << endl;
		}
		cout << "#" << test << " " << answer << endl;
	}

	return 0;
}