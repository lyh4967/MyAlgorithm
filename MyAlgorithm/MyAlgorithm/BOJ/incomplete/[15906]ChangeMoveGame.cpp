#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define MAXSIZE 500
int N, t, r, c;
char map[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE][2];
struct Node {
	int a; int b; int cnt; int changed;
	Node() {}
	Node(int _a, int _b, int _cnt, int _changed) :a(_a), b(_b), cnt(_cnt), changed(_changed) {
	}
};

bool isRanged(int a, int b) {
	return 0 <= a && a < N && 0 <= b && b < N;
}
int dirArr[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

void searchWarp(bool& search, int& warpA, int& warpB, int a, int b, vector<Node>& warpArr) {
	int tempDis = 987654321;
	search = false;
	for (int i = b + 1; i < N; i++) {//R
		if (i >= N)
			break;
		if (map[a][i] == '#' && abs(i - b) <= tempDis) {
			search = true;
			warpA = a; warpB = i;
			if (abs(i - b) == tempDis) {
				warpArr.push_back(Node(warpA, warpB, 0, 0));
			}
			else {
				warpArr.clear();
				warpArr.push_back(Node(warpA, warpB, 0, 0));
				tempDis = abs(i - b);
			}
		}
	}
	for (int i = a + 1; i < N; i++) {//D
		if (i >= N)
			break;
		if (map[i][b] == '#' && abs(i - a) <= tempDis) {
			search = true;
			warpA = i; warpB = b;
			if (abs(i - a) == tempDis) {
				warpArr.push_back(Node(warpA, warpB, 0, 0));
			}
			else {
				warpArr.clear();
				warpArr.push_back(Node(warpA, warpB, 0, 0));
				tempDis = abs(i - a);

			}
		}
	}
	for (int i = b - 1; i >= 0; i--) {//L
		if (i < 0)
			break;
		if (map[a][i] == '#' && abs(b - i) <= tempDis) {
			search = true;
			warpA = a; warpB = i;
			if (abs(i - b) == tempDis) {
				warpArr.push_back(Node(warpA, warpB, 0, 0));
			}
			else {
				warpArr.clear();
				warpArr.push_back(Node(warpA, warpB, 0, 0));
				tempDis = abs(i - b);

			}
		}
	}
	for (int i = a - 1; i >= 0; i--) {//U
		if (i < 0)
			break;
		if (map[i][b] == '#' && abs(a - i) <= tempDis) {
			search = true;
			warpA = i; warpB = b;
			if (abs(i - a) == tempDis) {
				warpArr.push_back(Node(warpA, warpB, 0, 0));
			}
			else {
				warpArr.clear();
				warpArr.push_back(Node(warpA, warpB, 0, 0));
				tempDis = abs(i - a);

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> t >> r >> c;
	r = r - 1;
	c = c - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			fill(visited[i][j], visited[i][j] + 2, false);
		}
	}

	queue<Node> que;
	que.push(Node(0, 0, 0, 0));
	Node node;
	int answer = 987654321;
	while (!que.empty()) {

		node = que.front(); que.pop();
		int a = node.a; int b = node.b; int cnt = node.cnt; int changed = node.changed;
		if (answer <= cnt) {
			continue;
		}

		if (a == r && b == c) {
			if (answer > cnt) {
				answer = cnt;
			}
			continue;
		}

		if (visited[a][b][changed])
			continue;

		visited[a][b][changed] = true;
		//cout << "log: " << a << "," << b << "," << cnt << "," << changed << endl;
		//4방향 워프 탐색
		int tarA; int tarB; bool warpSearch; vector<Node> warpArr;
		searchWarp(warpSearch, tarA, tarB, a, b, warpArr);

		if (changed == 1) {//변신되어있는상태
			for (int i = 0; i < 4; i++) {//변신풀고 이동
				int nA = a + dirArr[i][0];
				int nB = b + dirArr[i][1];
				if (isRanged(nA, nB) && !visited[nA][nB][changed]) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1; node.changed = 0;
					que.push(node);
				}
			}
			if (warpSearch) {//워프로이동
				for (int i = 0; i < warpArr.size(); i++) {
					node.a = warpArr[i].a; node.b = warpArr[i].b; node.cnt = cnt + 1; node.changed = 1;
					que.push(node);
				}
			}
		}
		else {//변신 안한상태
			for (int i = 0; i < 4; i++) {
				int nA = a + dirArr[i][0];
				int nB = b + dirArr[i][1];
				if (isRanged(nA, nB) && !visited[nA][nB][changed]) {
					node.a = nA; node.b = nB; node.cnt = cnt + 1; node.changed = 0;
					que.push(node);
				}
			}
			if (warpSearch) {
				node.a = a; node.b = b; node.changed = 1; node.cnt = cnt + t;//변~신
				que.push(node);
			}
		}


	}
	cout << answer << endl;


	return 0;
}