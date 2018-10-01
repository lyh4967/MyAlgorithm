#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int a; int b;
	Node() {}
	Node(int _a, int _b) :a(_a), b(_b) {}
};

int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int n;
char map[50][50];
int alphArr[26];
bool isRanged(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < n;
}
int main() {
	cout << (int)'A' << endl;
	cin >> n;
	queue<Node> que;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if ('A' <= map[i][j] && map[i][j] <= 'Z') {
				que.push(Node(i, j));
			}
		}
	}

	while (!que.empty()) {

		Node node = que.front(); que.pop();
		int a = node.a; int b = node.b;

		for (int i = 0; i < 4; i++) {

			int nA = a + dir[i][0];
			int nB = b + dir[i][1];

			if (isRanged(nA, nB)) {
				if (map[nA][nB] == 0) {
					fill(alphArr, alphArr + 26, 0);
					for (int tD = 0; tD < 4; tD++) {
						int tNA = nA + dir[tD][0];
						int tNB = nB + dir[tD][1];

						if (isRanged(tNA, tNB)) {
							if ('A' <= map[tNA][tNB] && map[tNA][tNB] <= 'Z') {
								alphArr[map[tNA][tNB]]++;//주변국가 카운트
							}
						}
					}
					int result = 0;
					int index = 0;
					for (int i = 0; i < 26; i++) {
						if (alphArr[i] > result) {
							result = alphArr[i];
							index = i;
						}
					}
					map[nA][nB] = alphArr[index] + 'A';

				}
				else if (1 <= map[nA][nB] && map[nA][nB] <= 15) {//장애물

				}
			}
		}

	}


}