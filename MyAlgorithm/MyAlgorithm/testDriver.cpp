#include <iostream>
#include <queue>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int min_m(int a, int b) {
	return a > b ? b : a;
}
int max_m(int a, int b) {
	return a > b ? a : b;
}
struct Node {
	int a; int b; int cnt;
};

char map[100][100];
bool visited[100][100];
int w, h;
int sA, sB, eA, eB;
int answer = 987654321;
int length;

bool check(int a, int b) {
	int tmpA = eA;
	int tmpB = eB;
	bool flag = false;//벽이있는지검사
	if (a == eA) {//같은 행
		if (b > eB) {
			swap(b, tmpB);
		}
		for (int i = b + 1; i < tmpB; i++)
			if (map[a][i] == '*')
				flag = true;
	}
	else {//같은 열
		if (a > eA) {
			swap(a, tmpA);
		}
		for (int i = a + 1; i < tmpA; i++)
			if (map[i][b] == '*')
				flag = true;
	}
	return flag;
}

bool isRanged(int a, int b) {
	return 0 <= a && a < h && 0 <= b && b < w;
}
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> w >> h;
	bool tmpFlag = false;
	Node node;
	queue<Node> que;
	length = max_m(w, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (tmpFlag == false) {
					sA = i; sB = j;
					node.a = sA; node.b = sB; node.cnt = 0;
					tmpFlag = true;
					que.push(node);
				}
				else {
					eA = i; eB = j;
				}
			}
			visited[i][j] = false;
		}
	}

	while (!que.empty()) {
		node = que.front(); que.pop();
		int a = node.a; int b = node.b; int cnt = node.cnt;
		if (cnt > answer)
			continue;

		if (a==eA || b==eB) {
			
			//cout << "end: " << eA << "," << eB << endl;
			if (!check(a,b)) {
				answer = min_m(answer, cnt);
				continue;
			}
		}
		
		if (visited[a][b])
			continue;
		//cout << "log: " << a << "," << b << endl;

		visited[a][b] = true;
		for (int i = 0; i < 4; i++) {
			for (int jump = 1; jump < length; jump++) {
				int nA = a + dir[i][0] * jump;
				int nB = b + dir[i][1] * jump;
				if (isRanged(nA, nB) && map[nA][nB] == '.') {
					if (!visited[nA][nB]) {
						node.a = nA; node.b = nB; node.cnt = cnt + 1;
						que.push(node);
					}7
				}
				else {
					break;
				}
			}
		}
	}

	cout << answer << "\n";
	return 0;
}