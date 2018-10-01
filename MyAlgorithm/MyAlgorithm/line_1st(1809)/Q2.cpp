#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <string>

using namespace std;

int a, b, dir;//현재좌표, 방향

			  //R:0 L:1 B:2 F:3
int n;
bool*** visited;
string** map;
int dirArr[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
bool answer = false;
int answerA;
int answerB;
void move() {
	int nodeDir;
	if (map[a][b][0] == 'R')
		nodeDir = 0;
	else if (map[a][b][0] == 'L')
		nodeDir = 1;
	else if (map[a][b][0] == 'B')
		nodeDir = 2;
	else if (map[a][b][0] == 'F')
		nodeDir = 3;
	int weighted = map[a][b][1] - '0';

	int nA, nB, nDir;

	if (dir == 3) {//직전 방향 F
		nDir = nodeDir;
	}
	else if (dir == 0) {//R
		if (nodeDir == 3) {
			nDir = 0;
		}
		else if (nodeDir == 0) {
			nDir = 2;
		}
		else if (nodeDir == 1) {
			nDir = 3;
		}
		else if (nodeDir == 2) {
			nDir = 1;
		}
	}
	else if (dir == 1) {//L
		if (nodeDir == 3) {
			nDir = 1;
		}
		else if (nodeDir == 0) {
			nDir = 3;
		}
		else if (nodeDir == 1) {
			nDir = 2;
		}
		else if (nodeDir == 2) {
			nDir = 0;
		}
	}
	else if (dir == 2) {
		if (nodeDir == 3) {
			nDir = 2;
		}
		else if (nodeDir == 0) {
			nDir = 1;
		}
		else if (nodeDir == 1) {
			nDir = 0;
		}
		else if (nodeDir == 2) {
			nDir = 3;
		}
	}
	//cout << "log 1: " << a << "," << b << "," << nDir << endl;

	if (visited[a][b][nDir] == true) {
		answer = true;
		return;
	}
	visited[a][b][nDir] = true;
	nA = a + dirArr[nDir][0] * weighted;
	nB = b + dirArr[nDir][1] * weighted;
	//cout << "log 2: " << nA << "," << nB << "," << nDir << endl;

	a = nA;
	b = nB;
	dir = nDir;

}

int main() {
	cin >> n;
	map = new string*[n];
	visited = new bool**[n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool*[n];
		for (int j = 0; j < n; j++) {
			visited[i][j] = new bool[4];
			fill(visited[i][j], visited[i][j] + 4, false);
		}
	}
	for (int x = 0; x < n; ++x) {
		map[x] = new string[n];
		for (int y = 0; y < n; ++y) {
			string node;
			cin >> node;
			map[x][y] = node;
			// @todo Write your code here.
		}
	}
	a = 0; b = 0; dir = 2;
	while (!answer) {
		move();
	}
	cout << b << " " << a << endl;
	return 0;
}
