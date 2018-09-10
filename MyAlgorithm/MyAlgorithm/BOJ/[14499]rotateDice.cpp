#include <iostream>
using namespace std;

int dice[4][3];
int n, m, sA, sB, k;
int map[20][20];
int dir[5][2] = { { 0,0 },{ 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 } };
bool isRanged(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < m;
}

void right() {
	int temp = dice[3][1];
	dice[3][1] = dice[1][2];
	dice[1][2] = dice[1][1];
	dice[1][1] = dice[1][0];
	dice[1][0] = temp;
}

void left() {
	int temp = dice[3][1];
	dice[3][1] = dice[1][0];
	dice[1][0] = dice[1][1];
	dice[1][1] = dice[1][2];
	dice[1][2] = temp;
}

void up() {
	int temp = dice[3][1];
	dice[3][1] = dice[0][1];
	dice[0][1] = dice[1][1];
	dice[1][1] = dice[2][1];
	dice[2][1] = temp;
}

void down() {
	int temp = dice[3][1];
	dice[3][1] = dice[2][1];
	dice[2][1] = dice[1][1];
	dice[1][1] = dice[0][1];
	dice[0][1] = temp;
}

void rotate(int dir) {
	if (dir == 1)
		right();
	else if (dir == 2)
		left();
	else if (dir == 3)
		up();
	else//4
		down();
}
void print() {
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << dice[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> sA >> sB >> k;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			dice[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int a = sA; int b = sB;
	int dirCom;
	for (int i = 0; i < k; i++) {
		cin >> dirCom;

		int nextA = a + dir[dirCom][0];
		int nextB = b + dir[dirCom][1];

		if (isRanged(nextA, nextB)) {
			rotate(dirCom);
			if (map[nextA][nextB] == 0) {
				map[nextA][nextB] = dice[3][1];
			}
			else {
				dice[3][1] = map[nextA][nextB];
				map[nextA][nextB] = 0;
			}
			a = nextA; b = nextB;
			cout << dice[1][1] << "\n";
		}
		//cout << "log: " << dirCom << "," << nextA << "," << nextB << endl;
		//print();
	}


	return 0;
}