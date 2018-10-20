#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//¸ÇÃ³À½ dp: R, CC:L
struct Node {
	int a; int b; char bl;
	Node() {}
	Node(int _a, int _b, char _bl) :a(_a), b(_b), bl(_bl) {}
};
int N, M;
char map[100][100];
bool visited[100][100];
//DP: R: 0, D:1 ~~
//CC: L:0, R:1
vector<Node> candi[4];

char curBlock;
int a, b;
int dirArr[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

bool compare_a(Node nodeA, Node nodeB) {
	return nodeA.a < nodeB.a;
}

bool compare_b(Node nodeA, Node nodeB) {
	return nodeA.b < nodeB.b;
}
bool isRanged(int a, int b) {
	return 0 <= a && a < N && 0 <= b && b < M;
}


void selectCodel(int dp, int cc) {
	//cout << " dp && cc: " << dp << "," << cc << endl;
	/*if (dp == 0) {
	if(cc == 0){
	for (int j = M - 1; j >= 0; j--) {
	for (int i = 0; i < N; i++) {
	if (curBlock == map[i][j] && visited[i][j] == true) {
	a = i; b = j;
	return;
	}
	}
	}
	}
	else if (cc == 1) {
	for (int j = M - 1; j >= 0; j--) {
	for (int i = N - 1; i >= 0; i--) {
	if (curBlock == map[i][j] && visited[i][j] == true) {
	a = i; b = j;
	return;
	}
	}
	}
	}
	}
	else if (dp == 1) {
	if (cc == 0) {
	for (int i = N - 1; i >= 0; i--) {
	for (int j = M - 1; j >= 0; j--) {
	if (curBlock == map[i][j] && visited[i][j] == true) {
	a = i; b = j;
	return;
	}
	}
	}
	}
	else if (cc == 1) {
	for (int i = N - 1; i >= 0; i--) {
	for (int j = 0; j < M; j++) {
	if (curBlock == map[i][j] && visited[i][j] == true) {
	a = i; b = j;
	return;
	}
	}
	}
	}
	}
	else if (dp == 2) {
	if (cc == 0) {
	for (int j = 0; j < M; j++) {
	for (int i = N - 1; i >= 0; i--) {
	if (curBlock == map[i][j] && visited[i][j] == true) {
	a = i; b = j;
	return;
	}
	}
	}
	}
	else if (cc == 1) {
	for (int j = 0; j < M; j++) {
	for (int i = 0; i < N; i++) {
	if (curBlock == map[i][j] && visited[i][j] == true) {
	a = i; b = j;
	return;
	}
	}
	}
	}
	}
	else if (dp == 3) {
	if (cc == 0) {
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
	if (curBlock == map[i][j] && visited[i][j] == true) {
	a = i; b = j;
	return;
	}
	}
	}
	}
	else if (cc == 1) {
	for (int i = 0; i < N; i++) {
	for (int j = M - 1; j >= 0; j--) {
	if (curBlock == map[i][j] && visited[i][j] == true) {
	a = i; b = j;
	return;
	}
	}
	}
	}
	}*/

	int length = candi[dp].size();

	if (dp == 0) {
		if (cc == 0) {
			a = candi[dp][0].a;
			b = candi[dp][0].b;
		}
		else if (cc == 1) {
			a = candi[dp][length - 1].a;
			b = candi[dp][length - 1].b;
		}
	}
	else if (dp == 1) {
		/*cout << endl;
		cout << "functiorn: " << dp << "," << cc << endl;
		cout << "length: " << length << endl;*/
		if (cc == 0) {
			a = candi[dp][length - 1].a;
			b = candi[dp][length - 1].b;
		}
		else if (cc == 1) {
			a = candi[dp][0].a;
			b = candi[dp][0].b;
		}
	}
	else if (dp == 2) {
		if (cc == 0) {
			a = candi[dp][length - 1].a;
			b = candi[dp][length - 1].b;
		}
		else if (cc == 1) {
			a = candi[dp][0].a;
			b = candi[dp][0].b;
		}
	}
	else if (dp == 3) {
		if (cc == 0) {
			a = candi[dp][0].a;
			b = candi[dp][0].b;
		}
		else if (cc == 1) {
			a = candi[dp][length - 1].a;
			b = candi[dp][length - 1].b;
		}
	}


}
void print() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 1) {
				cout << "¡á";
			}
			else
				cout << "¡à";
		}
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int DP, CC;
	for (int i = 0; i < N; i++)
		fill(visited[i], visited[i] + M, false);
	queue<Node> que;
	vector<char> answer;

	DP = 0; CC = 0;
	curBlock = map[0][0];
	a = 0; b = 0;
	que.push(Node(a, b, curBlock));
	answer.push_back(curBlock);

	Node node;

	while (!que.empty()) {
		node = que.front(); que.pop();
		int ta = node.a; int tb = node.b; int tbl = node.bl;

		if (visited[ta][tb])
			continue;

		visited[ta][tb] = true;
		for (int i = 0; i < 4; i++) {
			int nA = ta + dirArr[i][0];
			int nB = tb + dirArr[i][1];

			if (isRanged(nA, nB) && !visited[nA][nB] && map[nA][nB] == tbl) {
				node.a = nA; node.b = nB; node.bl = tbl;
				que.push(node);
			}
		}

	}
	bool Tflag = false;
	for (int j = M - 1; j >= 0; j--) {//R
		for (int i = 0; i < N; i++) {
			if (visited[i][j]) {
				Tflag = true;
				candi[0].push_back(Node(i, j, curBlock));
			}
		}
		if (Tflag)
			break;
	}

	Tflag = false;
	for (int i = N - 1; i >= 0; i--) {//D
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) {
				Tflag = true;
				candi[1].push_back(Node(i, j, curBlock));
			}
		}
		if (Tflag)
			break;
	}

	Tflag = false;
	for (int j = 0; j < M; j++) {//L
		for (int i = 0; i < N; i++) {
			if (visited[i][j]) {
				Tflag = true;
				candi[2].push_back(Node(i, j, curBlock));
			}
		}
		if (Tflag)
			break;
	}
	Tflag = false;
	for (int i = 0; i < N; i++) {//U
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) {
				Tflag = true;
				candi[3].push_back(Node(i, j, curBlock));
			}
		}
		if (Tflag)
			break;
	}

	sort(candi[0].begin(), candi[0].end(), compare_a);
	sort(candi[1].begin(), candi[1].end(), compare_b);
	sort(candi[2].begin(), candi[2].end(), compare_a);
	sort(candi[3].begin(), candi[3].end(), compare_b);

	int cnt = 0;
	bool flag = false;

	while (true) {
		if (cnt == 8)
			break;

		cnt++;
		selectCodel(DP, CC);

		int nA = a + dirArr[DP][0];
		int nB = b + dirArr[DP][1];
		/*cout << endl;
		cout << "log: " << a << "," << b << "," << curBlock << endl;
		cout << "DP,CC: " << DP << "," << CC << endl;
		cout << "candi: " << endl;
		for (int i = 0; i < 4; i++) {
		cout << i << ": ";
		for (int j = 0; j < candi[i].size(); j++) {
		cout << candi[i][j].a << "," << candi[i][j].b<<" ";
		}
		cout << endl;
		}
		print();*/

		if (isRanged(nA, nB) && map[nA][nB] != 'X') {
			curBlock = map[nA][nB];
			answer.push_back(curBlock);
			a = nA; b = nB;
			cnt = 0;

			for (int i = 0; i < N; i++)
				fill(visited[i], visited[i] + M, false);
			node.a = a; node.b = b; node.bl = curBlock;
			que.push(node);

			for (int tmp = 0; tmp < 4; tmp++)
				candi[tmp].clear();
			while (!que.empty()) {//bfs
				node = que.front(); que.pop();
				int ta = node.a; int tb = node.b; int tbl = node.bl;
				if (visited[ta][tb])
					continue;
				visited[ta][tb] = true;

				for (int i = 0; i < 4; i++) {
					int tnA = ta + dirArr[i][0];
					int tnB = tb + dirArr[i][1];
					if (isRanged(tnA, tnB) && !visited[tnA][tnB] && map[tnA][tnB] == tbl) {
						node.a = tnA; node.b = tnB; node.bl = tbl;
						que.push(node);
					}
				}
			}

			Tflag = false;
			for (int j = M - 1; j >= 0; j--) {//R
				for (int i = 0; i < N; i++) {
					if (visited[i][j]) {
						Tflag = true;
						candi[0].push_back(Node(i, j, curBlock));
					}
				}
				if (Tflag)
					break;
			}

			Tflag = false;
			for (int i = N - 1; i >= 0; i--) {//D
				for (int j = 0; j < M; j++) {
					if (visited[i][j]) {
						Tflag = true;
						candi[1].push_back(Node(i, j, curBlock));
					}
				}
				if (Tflag)
					break;
			}

			Tflag = false;
			for (int j = 0; j < M; j++) {//L
				for (int i = 0; i < N; i++) {
					if (visited[i][j]) {
						Tflag = true;
						candi[2].push_back(Node(i, j, curBlock));
					}
				}
				if (Tflag)
					break;
			}

			Tflag = false;
			for (int i = 0; i < N; i++) {//U
				for (int j = 0; j < M; j++) {
					if (visited[i][j]) {
						Tflag = true;
						candi[3].push_back(Node(i, j, curBlock));
					}
				}
				if (Tflag)
					break;
			}

			sort(candi[0].begin(), candi[0].end(), compare_a);
			sort(candi[1].begin(), candi[1].end(), compare_b);
			sort(candi[2].begin(), candi[2].end(), compare_a);
			sort(candi[3].begin(), candi[3].end(), compare_b);
		}
		else {
			if (flag == true) {
				flag = false;
				DP++;
				DP %= 4;
			}
			else {
				flag = true;
				CC++;
				CC %= 2;
			}
		}
	}

	int length = answer.size();
	for (int i = 0; i < length; i++) {
		cout << answer[i];
	}
	cout << endl;
	return 0;

}