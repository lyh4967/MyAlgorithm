#include <iostream>
#include<cmath>
using namespace std;

struct Atom {
	int x; int y; int dir; int ener;
	Atom() {}
	Atom(int _x, int _y, int _dir, int _ener) :x(_x), y(_y), dir(_dir), ener(_ener) {}
};


int N;
Atom atomArr[1000];
int map[2001][2001];
int answer = 0;
bool isRanged(int a, int b) {
	return 0 <= a && a <= 2000 && 0 <= b && b <= 2000;
}

void move() {

	for (int i = 0; i < N; i++) {
		int x = atomArr[i].x; int y = atomArr[i].y; int dir = atomArr[i].dir;
		int nx, ny;
		if (dir == -1)
			continue;
		if (dir == 0) {
			nx = x; ny = y - 1;
		}
		else if (dir == 1) {
			nx = x; ny = y + 1;
		}
		else if (dir == 2) {
			nx = x - 1; ny = y;
		}
		else if (dir == 3) {
			nx = x + 1; ny = y;
		}

		if (isRanged(ny, nx) && map[ny][nx] != -1) {
			int nDir = atomArr[map[ny][nx]].dir;
			if ((dir == 0 && nDir == 1) || (dir == 2 || nDir == 3)) {//0.5초 충돌
				atomArr[map[ny][nx]].dir = -1;
				atomArr[i].dir = -1;
				map[ny][nx] = -1;
				answer += atomArr[map[ny][nx]].ener;
				answer += atomArr[i].ener;
			}
			else {//1초충돌
				if (isRanged(ny - 1, nx) && map[ny - 1][nx] != -1 && atomArr[map[ny - 1][nx]].dir == 1) {
					answer += atomArr[map[nx][ny - 1]].ener;
					map[ny - 1][nx] = -1;
					atomArr[map[ny - 1][nx]].dir = -1;
				}
				else if (isRanged(ny + 1, nx) && map[ny + 1][nx] != -1 && atomArr[map[ny + 1][nx]].dir == 0) {
					answer += atomArr[map[nx][ny + 1]].ener;
					map[ny + 1][nx] = -1;
					atomArr[map[ny + 1][nx]].dir = -1;
				}
				else if (isRanged(ny, nx + 1) && map[ny][nx + 1] != -1 && atomArr[map[ny][nx + 1]].dir == 2) {
					answer += atomArr[map[nx + 1][ny]].ener;
					map[ny][nx + 1] = -1;
					atomArr[map[ny][nx + 1]].dir = -1;
				}
				else if (isRanged(ny, nx - 1) && map[ny][nx - 1] != -1 && atomArr[map[ny][nx - 1]].dir == 3) {
					answer += atomArr[map[ny][nx - 1]].ener;
					map[ny][nx - 1] = -1;
					atomArr[map[ny][nx - 1]].dir = -1;
				}
			}
		}
		else {//아무것도 없다면
			if (isRanged(ny, nx)) {
				atomArr[i].x = nx; atomArr[i].y = ny;
				map[y][x] = -1; map[ny][nx] = i;
			}
			else {
				atomArr[i].dir = -1;
				map[y][x] = -1;
			}

		}

	}
}

int main() {
	int T; cin >> T;

	for (int test = 1; test <= T; test++) {

		cin >> N;
		answer = 0;
		for (int i = 0; i < 2001; i++) {
			fill(map[i], map[i] + 2001, -1);
		}
		for (int i = 0; i < N; i++) {
			int tX, tY, tD, tE;
			cin >> tX >> tY >> tD >> tE;
			map[tY + 1000][tX + 1000] = i;
			atomArr[i] = Atom(tX + 1000, tY + 1000, tD, tE);

		}
		int i = 0;
		while (i <= 2000) {

			move();
			i++;
		}
		cout << "#" << test << " " << answer << endl;

	}


	return 0;
}