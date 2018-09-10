#include <iostream>
using namespace std;

#define INF 987654321
#define ROWSIZE 5
#define COLSIZE 9
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int min_m(int a, int b) { return a > b ? b : a; }

int answer1 = INF;
int answer2 = INF;

void print(char map[ROWSIZE][COLSIZE]) {
	cout << endl;
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

}
bool isRanged(int a, int b) {
	return 0 <= a && a < ROWSIZE && 0 <= b && b < COLSIZE;
}
void dfs(char map[ROWSIZE][COLSIZE], int cnt, int pinNum) {
	bool flag = false;
	//print(map);
	for (int i = 0; i < ROWSIZE; i++) {
		for (int j = 0; j < COLSIZE; j++) {
			if (map[i][j] == 'o') {//o라면양방향 검사
				for (int k = 0; k < 4; k++) {
					int nA = i + dir[k][0];
					int nB = j + dir[k][1];

					if (isRanged(nA + dir[k][0], nB + dir[k][1]) && map[nA][nB] == 'o' && map[nA + dir[k][0]][nB + dir[k][1]] == '.') {
						map[i][j] = '.';
						map[nA][nB] = '.';
						map[nA + dir[k][0]][nB + dir[k][1]] = 'o';
						flag = true;
						dfs(map, cnt + 1, pinNum - 1);
						map[i][j] = 'o';
						map[nA][nB] = 'o';
						map[nA + dir[k][0]][nB + dir[k][1]] = '.';
					}
				}


			}
		}
	}
	if (flag == false) {
		int result = 0;
		for (int i = 0; i < ROWSIZE; i++) {
			for (int j = 0; j < COLSIZE; j++) {
				if (map[i][j] == 'o')
					result++;
			}
		}
		if (answer1 == result) {
			answer2 = min_m(answer2, cnt);
		}
		else if (answer1>result) {
			answer1 = min_m(result, answer1);
			answer2 = cnt;
		}
	}
}

int main() {

	int T; cin >> T;

	for (int test = 1; test <= T; test++) {
		answer1 = INF;
		answer2 = INF;
		char map[5][9];
		int pinCnt = 0;
		for (int i = 0; i < ROWSIZE; i++) {
			for (int j = 0; j < COLSIZE; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'o')
					pinCnt++;
			}
		}

		dfs(map, 0, pinCnt);
		cout << answer1 << " " << answer2 << endl;

	}

	return 0;
}