#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_N 20
long long map[MAX_N][MAX_N];
int n;
long long tempMap[MAX_N][MAX_N];
int chk[5] = { 0,0,0,0,0 };
long long answer = 0;
void print1() {
	cout << endl;
	for (int i = 1; i <= 4; i++) {
		cout << chk[i] << " ";
	}
	cout << endl;
}
void print2() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void left() {
	for (int i = 0; i < n; i++) {
		int index_zero = 0;
		int index_num = 0;
		while (index_num < n) {
			if (map[i][index_num] != 0) {
				while (index_zero < index_num) {
					if (map[i][index_zero] == 0) {
						map[i][index_zero] = map[i][index_num];
						map[i][index_num] = 0;
						break;
					}
					else
						index_zero++;
				}
			}
			index_num++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] != 0 && map[i][j] == map[i][j + 1]) {
				map[i][j] *= 2;
				map[i][j + 1] = 0;
				j++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int index_zero = 0;
		int index_num = 0;
		while (index_num < n) {
			if (map[i][index_num] != 0) {
				while (index_zero < index_num) {
					if (map[i][index_zero] == 0) {
						map[i][index_zero] = map[i][index_num];
						map[i][index_num] = 0;
						break;
					}
					else
						index_zero++;
				}
			}
			index_num++;
		}
	}
}
void up() {
	for (int j = 0; j < n; j++) {
		int index_zero = 0;
		int index_num = 0;
		while (index_num < n) {
			if (map[index_num][j] != 0) {
				while (index_zero < index_num) {
					if (map[index_zero][j] == 0) {
						map[index_zero][j] = map[index_num][j];
						map[index_num][j] = 0;
						break;
					}
					else
						index_zero++;
				}
			}
			index_num++;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] != 0 && map[i][j] == map[i + 1][j]) {
				map[i][j] *= 2;
				map[i + 1][j] = 0;
				i++;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		int index_zero = 0;
		int index_num = 0;
		while (index_num < n) {
			if (map[index_num][j] != 0) {
				while (index_zero < index_num) {
					if (map[index_zero][j] == 0) {
						map[index_zero][j] = map[index_num][j];
						map[index_num][j] = 0;
						break;
					}
					else
						index_zero++;
				}
			}
			index_num++;
		}
	}
}
void right() {
	for (int i = 0; i < n; i++) {
		int index_zero = n - 1;
		int index_num = n - 1;
		while (index_num >= 0) {
			if (map[i][index_num] != 0) {
				while (index_zero > index_num) {
					if (map[i][index_zero] == 0) {
						map[i][index_zero] = map[i][index_num];
						map[i][index_num] = 0;
						break;
					}
					else
						index_zero--;
				}
			}
			index_num--;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (map[i][j] != 0 && map[i][j] == map[i][j - 1]) {
				map[i][j] *= 2;
				map[i][j - 1] = 0;
				j--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int index_zero = n - 1;
		int index_num = n - 1;
		while (index_num >= 0) {
			if (map[i][index_num] != 0) {
				while (index_zero > index_num) {
					if (map[i][index_zero] == 0) {
						map[i][index_zero] = map[i][index_num];
						map[i][index_num] = 0;
						break;
					}
					else
						index_zero--;
				}
			}
			index_num--;
		}
	}
}
void down() {
	for (int j = 0; j < n; j++) {
		int index_zero = n - 1;
		int index_num = n - 1;
		while (index_num >= 0) {
			if (map[index_num][j] != 0) {
				while (index_zero > index_num) {
					if (map[index_zero][j] == 0) {
						map[index_zero][j] = map[index_num][j];
						map[index_num][j] = 0;
						break;
					}
					else
						index_zero--;
				}
			}
			index_num--;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (map[i][j] != 0 && map[i][j] == map[i - 1][j]) {
				map[i][j] *= 2;
				map[i - 1][j] = 0;
				i--;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		int index_zero = n - 1;
		int index_num = n - 1;
		while (index_num >= 0) {
			if (map[index_num][j] != 0) {
				while (index_zero > index_num) {
					if (map[index_zero][j] == 0) {
						map[index_zero][j] = map[index_num][j];
						map[index_num][j] = 0;
						break;
					}
					else
						index_zero--;
				}
			}
			index_num--;
		}
	}
}

void solve() {
	for (int i = 1; i <= 4; i++) {//움직임
		int cnt = chk[i];
		while (cnt > 0) {
			if (i == 1)
				left();
			else if (i == 2)
				up();
			else if (i == 3)
				right();
			else if (i == 4)
				down();
			cnt--;
		}
	}
	for (int i = 0; i < n; i++) {//최댓값 갱신
		for (int j = 0; j < n; j++) {
			if (answer < map[i][j]) {
				//print1();
				//print2();
				answer = map[i][j];

			}
		}
	}

	for (int i = 0; i < n; i++) //원상복구
		for (int j = 0; j < n; j++)
			map[i][j] = tempMap[i][j];
}

void dfs(int index, int cnt) {

	if (cnt == 5) {
		//print1();
		solve();
		return;
	}
	if (index == 5)
		return;
	chk[index]++;
	dfs(index, cnt + 1);
	chk[index]--;
	dfs(index + 1, cnt);


}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			tempMap[i][j] = map[i][j];
		}
	}
	dfs(1, 0);

	cout << answer << endl;

	return 0;
}
/*
##[12100]2048

5
2 2 8 8 2
4 4 0 0 4
0 4 8 4 2
0 0 0 2 0
2 0 4 0 2

6
2 0 4 4 2 16
8 32 32 0 8 8
64 16 8 0 2 2
0 0 4 2 8 0
2 0 4 0 0 0
32 32 16 0 2 4

5
2 2 2 2 2
2 2 2 2 2
2 0 0 0 2
2 2 0 0 2
0 0 2 2 2

4
0 0 0 0
0 0 2 0
0 0 0 0
0 0 0 0

20
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024
1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024 1024

*/