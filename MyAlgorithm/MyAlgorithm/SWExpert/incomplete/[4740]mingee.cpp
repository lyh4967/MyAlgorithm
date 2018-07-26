#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
int dir1[4] = { 1,0,-1,0 };
int dir2[4] = { 0,1,0,-1 };
struct Pair {
	int a;
	int b;
	Pair() {}
	Pair(int _a, int _b) :a(_a), b(_b) {}
};

char** map;
int n, m, q;

void print() {
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cout << map[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

bool isRange(int a, int b) {
	return (0 <= a && a < n) && (0 <= b && b < m);
}
queue<Pair>search_maxBlock() {
	queue<Pair> que_AB;

	//bfs
	bool** visited = new bool*[n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool[m];
		fill(visited[i], visited[i] + m, false);
	}
	int maxCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '#' && visited[i][j] == false) {

				Pair tempPair(i, j);
				queue<Pair> bfsQ;
				bfsQ.push(tempPair);

				int cnt = 0;
				visited[i][j] = true;
				while (!bfsQ.empty()) {
					Pair temp = bfsQ.front();
					int a = temp.a;
					int b = temp.b;
					visited[a][b] = true;
					cnt++;
					bfsQ.pop();
					for (int k = 0; k < 4; k++) {
						int nextA = a + dir1[k];
						int nextB = b + dir2[k];
						if (isRange(nextA, nextB) && (map[nextA][nextB] == map[a][b]) && (visited[nextA][nextB] == false)) {
							bfsQ.push(Pair(nextA, nextB));
						}
					}
				}
				if (maxCnt < cnt) {
					maxCnt = cnt;
					while (!que_AB.empty())
						que_AB.pop();
				}
				Pair A(i, j);
				if (maxCnt == cnt)
					que_AB.push(A);
			}
		}
	}

	return que_AB;
}

void press_D() {
	queue<Pair> que = search_maxBlock();
	bool** visited = new bool*[n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool[m];
		fill(visited[i], visited[i] + m, false);
	}
	while (!que.empty()) {
		Pair tempPair = que.front();
		que.pop();
		queue<Pair> bfsQ;
		bfsQ.push(tempPair);

		int cnt = 0;
		visited[tempPair.a][tempPair.b] = true;
		while (!bfsQ.empty()) {
			Pair temp = bfsQ.front();
			int a = temp.a;
			int b = temp.b;
			visited[a][b] = true;
			bfsQ.pop();
			for (int k = 0; k < 4; k++) {
				int nextA = a + dir1[k];
				int nextB = b + dir2[k];
				if (isRange(nextA, nextB) && (map[nextA][nextB] == map[a][b]) && (visited[nextA][nextB] == false)) {
					bfsQ.push(Pair(nextA, nextB));
				}
			}
			map[a][b] = '#';
		}
	}
	//내림
	for (int i = 0; i <m; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (j > n - 1)
				j = n - 1;
			if (map[j][i] == '#') {

				for (int k = j; k > 0; k--) {
					char temp = map[k][i];
					map[k][i] = map[k - 1][i];
					map[k - 1][i] = temp;
				}
				map[0][i] = '#';


				bool flag = false;
				for (int k = j; k >= 0; k--) {
					if (map[k][i] != '#')
						flag = true;
				}
				if (map[j][i] == '#')
					j = j + 1;

				if (!flag)
					j = -1;
			}
		}
	}

}

void press_L() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (j < 0)
				j = 0;
			if (map[i][j] == '#') {

				for (int k = j; k < m - 1; k++) {
					char temp = map[i][k];
					map[i][k] = map[i][k + 1];
					map[i][k + 1] = temp;
				}
				map[i][m - 1] = '#';


				bool flag = false;
				for (int k = j; k < m; k++) {
					if (map[i][k] != '#')
						flag = true;
				}
				if (map[i][j] == '#')
					j = j - 1;
				if (!flag)
					j = m + 1;
			}
		}
	}
}

void press_R() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (j > m - 1)
				j = m - 1;
			if (map[i][j] == '#') {
				for (int k = j; k > 0; k--) {
					char temp = map[i][k];
					map[i][k] = map[i][k - 1];
					map[i][k - 1] = temp;
				}
				map[i][0] = '#';


				bool flag = false;
				for (int k = j; k >= 0; k--) {
					if (map[i][k] != '#')
						flag = true;
				}
				if (map[i][j] == '#')
					j = j + 1;
				if (!flag)
					j = -1;

			}
		}
	}
}

void press_U(char* newBlock) {
	//기둥이 있는가?
	for (int i = 0; i < m; i++) {
		if (map[0][i] != '#')
			return;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[j][i] != '#') {
				char temp = map[j][i];
				map[j][i] = map[j - 1][i];
				map[j - 1][i] = temp;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		map[n - 1][i] = newBlock[i];
		if (newBlock[i] == '#') {
			for (int j = n - 1; j > 0; j--) {
				char temp = map[j][i];
				map[j][i] = map[j - 1][i];
				map[j - 1][i] = temp;
			}
			map[0][i] = '#';
		}
	}
}

int main() {

	int testNum;
	cin >> testNum;
	for (int test = 1; test <= testNum; test++) {

		cin >> n >> m >> q;

		map = new char*[n];

		for (int i = 0; i < n; i++) {
			map[i] = new char[m];
			fill(map[i], map[i] + m, '#');
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%1s", &map[i][j]);
			}
		}

		for (int i = 0; i < q; i++) {
			char command;
			cin >> command;
			if (command == 'D')
				press_D();
			else if (command == 'L')
				press_L();
			else if (command == 'R')
				press_R();
			else {//U
				char* newBlock = new char[m];
				cin >> newBlock;
				press_U(newBlock);
			}
			print();
		}
		cout << "#" << test << endl;
		print();
	}


	return 0;
}