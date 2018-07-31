#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int dir1[6] = { 1,-1,1,-1 };
int dir2[6] = { 1,-1,0,0 };

struct Pair {
	int a; int b; int cnt;
	Pair() {}
	Pair(int _a, int _b, int _cnt) :a(_a), b(_b), cnt(_cnt) {}
};

bool isRange(int a, int b) {
	return 1 <= a && a < 142 && 1 <= b && b <= a;
}

int main() {
	int arr[142];

	arr[1] = 1;
	for (int i = 2; i <= 141; i++) {
		arr[i] = arr[i - 1] + i - 1;
	}

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		int a, b;
		int startA, startB;
		int endA, endB;
		cin >> a >> b;

		bool visited[142][142];
		for (int i = 1; i < 142; i++)
			for (int j = 1; j <= i; j++)
				visited[i][j] = false;


		for (int i = 1; i <= 141; i++) {
			if (a == 1 || b == 1) {
				if (a == 1) {
					startA = 1; startB = 1;
				}
				if (b == 1) {
					endA = 1; endB = 1;
				}
			}
			else {
				if (arr[i] <= a && a <= arr[i] + i - 1) {
					startA = i;
					startB = a - arr[i] + 1;
				}
				if (arr[i] <= b && b <= arr[i] + i - 1) {
					endA = i;
					endB = b - arr[i] + 1;
				}
			}
		}
		queue<Pair> que;
		Pair node(startA, startB, 0);
		que.push(node);
		int minCnt = 987654321;

		while (!que.empty()) {
			node = que.front(); que.pop();
			int tempA = node.a; int tempB = node.b; int tempCnt = node.cnt;


			if (visited[tempA][tempB])
				continue;
			visited[tempA][tempB] = true;
			if (tempCnt >= minCnt)
				continue;

			if ((arr[tempA] <= b) && (b <= (arr[tempA] + tempA - 1))) {
				tempCnt += abs(arr[tempA] + tempB - 1 - b);
				if (tempCnt < minCnt)
					minCnt = tempCnt;
			}
			else {
				for (int i = 0; i < 4; i++) {
					int nextA = tempA + dir1[i];
					int nextB = tempB + dir2[i];
					if (isRange(nextA, nextB) && !visited[nextA][nextB]) {
						node.a = nextA; node.b = nextB; node.cnt = tempCnt + 1;
						que.push(node);
					}
				}
			}
		}
		cout << "#" << test << " " << minCnt << endl;
	}
	return 0;
}s