#include <iostream>
using namespace std;

// N, E, S, W : 0, 1, 2, 3
struct Node {
	int y; int x;
	Node(int _y, int _x) :y(_y), x(_x) {}
	Node() {}
};
int robots[101];
int map[101][101];
Node robotLoc[101];
int A, B, n, m;
int dir[4][2] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };//N E S W
bool isRanged(int y, int x) {
	return 1 <= y && y <= B && 1 <= x && x <= A;
}

//void swap(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}

void print() {
	cout << endl;
	for (int i = 1; i <= B; i++) {
		for (int j = 1; j <= A; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void print2() {
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << robots[i] << " ";
	}
	cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> A >> B >> n >> m;
	for (int i = 1; i <= B; i++) {
		for (int j = 1; j <= A; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {//초기화
		int sX, sY; cin >> sX >> sY;
		char tempDir; cin >> tempDir;
		if (tempDir == 'N')
			robots[i] = 0;
		else if (tempDir == 'E')
			robots[i] = 1;
		else if (tempDir == 'S')
			robots[i] = 2;
		else //'W'
			robots[i] = 3;
		robotLoc[i] = Node(sY, sX);
		map[sY][sX] = i;

	}
	bool flag = false;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		char command; cin >> command;
		int cnt; cin >> cnt;
		if (command == 'R') {//시계
			for (int j = 0; j < cnt; j++)
				robots[num] = (robots[num] + 1) % 4;
		}
		else if (command == 'L') {//반시계
			for (int j = 0; j < cnt; j++) {
				robots[num] = robots[num] - 1;
				if (robots[num] < 0)
					robots[num] = 3;
			}
		}
		else {//F
			int robotD = robots[num];
			for (int j = 0; j < cnt; j++) {
				int y = robotLoc[num].y; int x = robotLoc[num].x;
				int nY = y + dir[robotD][0];
				int nX = x + dir[robotD][1];
				if (isRanged(nY, nX)) {
					if (map[nY][nX] != 0) {
						cout << "Robot " << num << " crashes into robot " << map[nY][nX] << "\n";
						return 0;
					}
					else {//진행
						map[nY][nX] = num;
						map[y][x] = 0;
						robotLoc[num].y = nY; robotLoc[num].x = nX;
					}
				}
				else {
					cout << "Robot " << num << " crashes into the wall\n";
					return 0;
				}
			}
		}
	}
	cout << "OK\n";
	return 0;
}