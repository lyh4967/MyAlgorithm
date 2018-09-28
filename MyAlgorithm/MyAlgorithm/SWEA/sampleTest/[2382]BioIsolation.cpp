#include <iostream>
using namespace std;

struct Bio {
	int a;
	int b;
	int dir;
	int num;
	Bio() {}
	Bio(int _a, int _b, int _dir, int _num) :a(_a), b(_b), dir(_dir), num(_num) {}
};

int N, M, K;
int map[100][100][2];
Bio bios[10001];

bool isRanged(int a, int b) {
	return 1 <= a && a <= N - 2 && 1 <= b && b <= N - 2;
}
// 1:N, 2:S, 3:W, 4:E  
int dirArr[5][2] = { { 0,0 },{ -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j][0] << " ";
		}
		cout << endl;
	}

}
void print2() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j][1] << " ";
		}
		cout << endl;
	}

}
int cnt = 0;
void simul() {
	int a, b, dir, num;
	int nA, nB;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j][0] = 0;
			map[i][j][1] = 0;
		}
	}
	for (int i = 1; i <= K; i++) {
		if (bios[i].num != 0) {
			a = bios[i].a; b = bios[i].b; dir = bios[i].dir; num = bios[i].num;
			nA = a + dirArr[dir][0];
			nB = b + dirArr[dir][1];

			if (isRanged(nA, nB)) {
				if (map[nA][nB] != 0) {
					if (map[nA][nB][1] < num) {//나중에오는애가 더커
						bios[i].num += bios[map[nA][nB][0]].num;
						bios[map[nA][nB][0]].num = 0;
						map[nA][nB][0] = i;
						map[nA][nB][1] = num;//최대값갱신

					}
					else {//나중에 오는애가 더 작으면
						bios[map[nA][nB][0]].num += bios[i].num;
						bios[i].num = 0;
					}
				}
				else {//map[nA][nB]==0
					map[nA][nB][0] = i;
					map[nA][nB][1] = bios[i].num;
				}
				bios[i].a = nA; bios[i].b = nB;


			}
			else {//범위 밖
				if (dir == 1)
					bios[i].dir = 2;
				else if (dir == 2)
					bios[i].dir = 1;
				else if (dir == 3)
					bios[i].dir = 4;
				else if (dir == 4)
					bios[i].dir = 3;

				bios[i].num = bios[i].num / 2;
				if (bios[i].num != 0) {
					map[nA][nB][0] = i;
					bios[i].a = nA;
					bios[i].b = nB;
					map[nA][nB][1] = bios[i].num;
				}
			}
		}
	}
}

int main() {
	int T; cin >> T;

	for (int test = 1; test <= T; test++) {

		cin >> N >> M >> K;
		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fill(map[i][j], map[i][j] + 2, 0);
			}
		}
		for (int i = 1; i <= K; i++) {
			int tmpA, tmpB, tmpN, tmpD;
			cin >> tmpA >> tmpB >> tmpN >> tmpD;
			bios[i] = Bio(tmpA, tmpB, tmpD, tmpN);
			map[tmpA][tmpB][0] = i;
			map[tmpA][tmpB][1] = tmpN;
		}
		for (int i = 0; i < M; i++) {
			simul();
		}
		for (int i = 1; i <= K; i++) {
			answer += bios[i].num;
		}
		cout << "#" << test << " " << answer << endl;


	}

	return 0;

}