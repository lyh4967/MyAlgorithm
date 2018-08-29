#include <iostream>
#include <string>
using namespace std;

int n, m;
char board[30][30];
bool chk[30][30];
int answer = 0;
void down() {
	for (int j = 0; j < n; j++) {
		int index_zero = m - 1;
		int index_num = m - 1;
		while (index_num >= 0) {
			if (board[index_num][j] != 0) {
				while (index_zero > index_num) {
					if (board[index_zero][j] == 0) {
						board[index_zero][j] = board[index_num][j];
						board[index_num][j] = 0;
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
bool Bom() {
	bool flag = false;
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] != 0 && board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
				chk[i][j] = true; chk[i + 1][j] = true; chk[i][j + 1] = true; chk[i + 1][j + 1] = true;
				flag = true;
			}
		}
	}
	return flag;
}

void update() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j]) {
				board[i][j] = 0;
				answer++;
				chk[i][j] = false;
			}
		}
	}
	down();
}


void print() {
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	bool flag = true;
	while (flag) {
		flag = false;
		if (Bom()) {
			flag = true;
			update();
		}
	}
	cout << answer << endl;
	return 0;
}