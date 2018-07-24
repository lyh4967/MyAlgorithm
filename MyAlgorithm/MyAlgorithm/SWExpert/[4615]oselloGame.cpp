#include <iostream>
using namespace std;

int n, m;
int** board;

bool isBoundry(int y, int x) {
	return ((1 <= x && x <= n) && (1 <= y && y <= n)) && (board[y][x] != 0);
}

int main() {

	int testNum;
	cin >> testNum;
	for (int test = 1; test <= testNum; test++) {

		cin >> n >> m;
		board = new int*[n + 1];
		for (int i = 1; i <= n; i++)
			board[i] = new int[n + 1];

		for (int i = 1; i <= n; i++)
			fill(board[i], board[i] + n + 1, 0);

		for (int i = n / 2; i <= n / 2 + 1; i++) {
			board[i][i] = 2;
			board[n - i + 1][i] = 1;
		}

		for (int i = 0; i < m; i++) {
			int x, y, stone;
			cin >> x >> y >> stone;
			board[y][x] = stone;

			//3시
			int tempX = x + 1;
			int tempY = y;
			while (isBoundry(tempY, tempX)) {
				if (board[tempY][tempX] == stone) {
					while (!(tempX == x && tempY == y)) {
						board[tempY][tempX] = stone;
						tempX--;
						tempY;
					}
					break;
				}
				else {
					tempX++;
					tempY;
				}
			}

			//5시
			tempX = x + 1;
			tempY = y + 1;
			while (isBoundry(tempY, tempX)) {
				if (board[tempY][tempX] == stone) {
					while (!(tempX == x && tempY == y)) {
						board[tempY][tempX] = stone;
						tempX--;
						tempY--;
					}
					break;
				}
				else {
					tempX++;
					tempY++;
				}
			}

			//6시
			tempX = x;
			tempY = y + 1;
			while (isBoundry(tempY, tempX)) {
				if (board[tempY][tempX] == stone) {
					while (!(tempX == x && tempY == y)) {
						board[tempY][tempX] = stone;
						tempX;
						tempY--;
					}
					break;
				}
				else {
					tempX;
					tempY++;
				}
			}

			//8시
			tempX = x - 1;
			tempY = y + 1;
			while (isBoundry(tempY, tempX)) {
				if (board[tempY][tempX] == stone) {
					while (!(tempX == x && tempY == y)) {
						board[tempY][tempX] = stone;
						tempX++;
						tempY--;
					}
					break;
				}
				else {
					tempX--;
					tempY++;
				}
			}

			//9시
			tempX = x - 1;
			tempY = y;
			while (isBoundry(tempY, tempX)) {
				if (board[tempY][tempX] == stone) {
					while (!(tempX == x && tempY == y)) {
						board[tempY][tempX] = stone;
						tempX++;
						tempY;
					}
					break;
				}
				else {
					tempX--;
					tempY;
				}
			}

			//11시
			tempX = x - 1;
			tempY = y - 1;
			while (isBoundry(tempY, tempX)) {
				if (board[tempY][tempX] == stone) {
					while (!(tempX == x && tempY == y)) {
						board[tempY][tempX] = stone;
						tempX++;
						tempY++;
					}
					break;
				}
				else {
					tempX--;
					tempY--;
				}
			}

			//12시
			tempX = x;
			tempY = y - 1;
			while (isBoundry(tempY, tempX)) {
				if (board[tempY][tempX] == stone) {
					while (!(tempX == x && tempY == y)) {
						board[tempY][tempX] = stone;
						tempX;
						tempY++;
					}
					break;
				}
				else {
					tempX;
					tempY--;
				}
			}

			//2시
			tempX = x + 1;
			tempY = y - 1;
			while (isBoundry(tempY, tempX)) {
				if (board[tempY][tempX] == stone) {
					while (!(tempX == x && tempY == y)) {
						board[tempY][tempX] = stone;
						tempX--;
						tempY++;
					}
					break;
				}
				else {
					tempX++;
					tempY--;
				}
			}
		}

		/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
		cout << board[i][j] << ' ';
		}
		cout << endl;
		}*/
		int stone_B_cnt = 0;
		int stone_W_cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] == 1) {
					stone_B_cnt++;
				}
				else if (board[i][j] == 2) {

					stone_W_cnt++;
				}
			}
		}


		cout << '#' << test << ' ' << stone_B_cnt << ' ' << stone_W_cnt << endl;
	}

	return 0;
}