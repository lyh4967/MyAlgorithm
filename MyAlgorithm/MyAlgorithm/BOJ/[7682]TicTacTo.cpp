#include <iostream>
#include <string>
using namespace std;
char map[3][3];
struct Node {
	int a; int b;
};
Node node1;
Node node2;
int chkBingo() {
	int cnt = 0;
	if (map[0][0] != '.' && map[0][0] == map[0][1] && map[0][1] == map[0][2]) {
		if (node1.a == -1 && node1.b == -1) {
			node1.a = 0; node1.b = 0;
		}
		else {
			node2.a = 0; node2.b = 0;
		}
		cnt++;
	}
	if (map[1][0] != '.' && map[1][0] == map[1][1] && map[1][1] == map[1][2]) {
		if (node1.a == -1 && node1.b == -1) {
			node1.a = 1; node1.b = 0;
		}
		else {
			node2.a = 1; node2.b = 0;
		}
		cnt++;
	}
	if (map[2][0] != '.' && map[2][0] == map[2][1] && map[2][1] == map[2][2]) {
		if (node1.a == -1 && node1.b == -1) {
			node1.a = 2; node1.b = 0;
		}
		else {
			node2.a = 2; node2.b = 0;
		}
		cnt++;
	}


	if (map[0][0] != '.' && map[0][0] == map[1][0] && map[1][0] == map[2][0]) {
		if (node1.a == -1 && node1.b == -1) {
			node1.a = 0; node1.b = 0;
		}
		else {
			node2.a = 0; node2.b = 0;
		}
		cnt++;
	}
	if (map[0][1] != '.' && map[0][1] == map[1][1] && map[1][1] == map[2][1]) {
		if (node1.a == -1 && node1.b == -1) {
			node1.a = 0; node1.b = 1;
		}
		else {
			node2.a = 0; node2.b = 1;
		}
		cnt++;
	}
	if (map[0][2] != '.' && map[0][2] == map[1][2] && map[1][2] == map[2][2]) {
		if (node1.a == -1 && node1.b == -1) {
			node1.a = 0; node1.b = 2;
		}
		else {
			node2.a = 0; node2.b = 2;
		}
		cnt++;
	}


	if (map[0][0] != '.' && map[0][0] == map[1][1] && map[1][1] == map[2][2]) {
		if (node1.a == -1 && node1.b == -1) {
			node1.a = 0; node1.b = 0;
		}
		else {
			node2.a = 0; node2.b = 0;
		}
		cnt++;
	}
	if (map[0][2] != '.' && map[0][2] == map[1][1] && map[1][1] == map[2][0]) {
		if (node1.a == -1 && node1.b == -1) {
			node1.a = 0; node1.b = 2;
		}
		else {
			node2.a = 0; node2.b = 2;
		}
		cnt++;
	}
	return cnt;
}
void print() {
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	bool gameFlag = true;
	string command;
	int x_cnt;
	int o_cnt;
	while (gameFlag) {
		cin >> command;
		node1.a = -1;
		node1.b = -1;
		node2.a = -1;
		node2.b = -1;
		x_cnt = 0; o_cnt = 0;
		if (command != "end") {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					map[i][j] = command[3 * i + j];//초기화
					if (map[i][j] == 'X')
						x_cnt++;
					else if (map[i][j] == 'O')
						o_cnt++;
				}
			}
			if (!(0 <= (x_cnt - o_cnt) && (x_cnt - o_cnt) <= 1)) {
				cout << "invalid\n";
				continue;
			}
			int binCnt = chkBingo();
			if (binCnt == 1 || binCnt == 2) {
				if (binCnt == 2) {
					if (!((map[node1.a][node1.b] == 'X' && map[node2.a][node2.b] == 'X'))) {//2개다 'X'
						cout << "invalid\n";
						continue;
					}
					if (x_cnt == 5 && o_cnt == 4) {
						cout << "valid\n";
						continue;
					}
					else {
						cout << "invalid\n";
						continue;
					}
				}
				else {//binCnt==1
					if (map[node1.a][node1.b] == 'O') {
						if (x_cnt == o_cnt) {
							cout << "valid\n";
							continue;
						}
						else {
							cout << "invalid\n";
							continue;
						}
					}
					else if (map[node1.a][node1.b] == 'X') {
						if (x_cnt - o_cnt == 1) {
							cout << "valid\n";
							continue;
						}
						else {
							cout << "invalid\n";
							continue;
						}
					}
				}
			}
			else if (binCnt >= 3) {
				cout << "invalid\n";
			}


			if (x_cnt + o_cnt == 9) {
				cout << "valid\n";
				continue;
			}
			cout << "invalid\n";
		}
		else
			gameFlag = false;
	}
	return 0;
}