#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[50][50];
int visited[51][51][65];
int startA, startB;
int minCnt = 987654321;
int dir1[4] = { 0,1,0,-1 };
int	dir2[4] = { 1,0,-1,0 };
struct Pair {
	int a;
	int b;
	int cnt;
	int keys;
	Pair() {}
	Pair(int _a, int _b, int _cnt, int _keys) :a(_a), b(_b), cnt(_cnt), keys(_keys) {}
};

void print() {
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 65; k++) {
				visited[i][j][k] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				startA = i;
				startB = j;
			}
		}
	}
	minCnt = 987654321;

}
bool isRange(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < m;
}
void solve() {

	queue<Pair> que;
	vector<char> keys;
	que.push(Pair(startA, startB, 0, 0));
	Pair node;
	while (!que.empty()) {
		node = que.front(); que.pop();
		int a = node.a; int b = node.b; int cnt = node.cnt; int keys = node.keys;
		if (visited[a][b][keys] == true)
			continue;
		//cout <<"cur: "<< a << "," << b <<","<<cnt<<","<<keys<< endl;

		if (minCnt <= cnt)
			continue;

		visited[a][b][keys] = true;

		for (int di = 0; di < 4; di++) {
			int nextA = a + dir1[di];
			int nextB = b + dir2[di];
			if (isRange(nextA, nextB) && !visited[nextA][nextB][keys] && map[nextA][nextB] != '#') {//진행

				if ('A' <= map[nextA][nextB] && map[nextA][nextB] <= 'F') {//대문자
					int lock = 1 << (map[nextA][nextB] - 'A');
					if (keys == (keys | lock)) {
						node.a = nextA; node.b = nextB; node.cnt = cnt + 1; node.keys = keys;
						que.push(node);
					}
				}
				else if ('a' <= map[nextA][nextB] && map[nextA][nextB] <= 'f') {//소문자
					int key = 1 << (map[nextA][nextB] - 'a');
					int tempkeys = keys | key;
					node.a = nextA; node.b = nextB; node.cnt = cnt + 1; node.keys = tempkeys;
					que.push(node);
				}
				else if (map[nextA][nextB] == '1') {
					if (minCnt > cnt + 1)
						minCnt = cnt + 1;
				}
				else {// . or 1 or 0
					node.a = nextA; node.b = nextB; node.cnt = cnt + 1; node.keys = keys;
					que.push(node);
				}
			}

		}
	}
	if (minCnt != 987654321)
		cout << minCnt << endl;
	else
		cout << -1 << endl;
}
int main() {
	cin >> n >> m;

	init();

	solve();


	return 0;
}