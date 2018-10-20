#include <iostream>
using namespace std;
struct Node {
	int i; int j;
	int rotCnt;
	Node() {}

	Node(int _i, int _j, int _rotCnt) :i(_i), j(_j), rotCnt(_rotCnt) {}
};//dir : 0 회전 x, 1:반시계, 2: 시계
int n;
int qualArr[10][4][4];
char colorArr[10][4][4];
bool visited[10];
Node candi[10];
int re_qualArr[5][5];
char re_colorArr[5][5];
int answer = 0;
void add(int index, int row, int col, int rotCnt) {
	int rowMax = row + 4;
	int colMax = col + 4;
	if (rotCnt == 0) { //무회전
		for (int i = row; i < rowMax; i++) {
			for (int j = col; j < colMax; j++) {
				re_qualArr[i][j] += qualArr[index][i - row][j - col];
				re_qualArr[i][j] = re_qualArr[i][j] > 9 ? 9 : re_qualArr[i][j];
				re_qualArr[i][j] = re_qualArr[i][j] < 0 ? 0 : re_qualArr[i][j];
				re_colorArr[i][j] = colorArr[index][i - row][j - col] == 'W' ? re_colorArr[i][j] : colorArr[index][i - row][j - col];

			}
		}
	}
	else if (rotCnt == 1) {
		for (int i = row; i < rowMax; i++) {
			for (int j = col; j < colMax; j++) {
				int tA = j - col;
				int tB = 3 - (i - row);
				re_qualArr[i][j] += qualArr[index][tA][tB];
				re_qualArr[i][j] = re_qualArr[i][j] > 9 ? 9 : re_qualArr[i][j];
				re_qualArr[i][j] = re_qualArr[i][j] < 0 ? 0 : re_qualArr[i][j];
				re_colorArr[i][j] = colorArr[index][tA][tB] == 'W' ? re_colorArr[i][j] : colorArr[index][tA][tB];

			}
		}
	}
	else if (rotCnt == 2) {
		for (int i = row; i < rowMax; i++) {
			for (int j = col; j < colMax; j++) {
				int tA = 3 - (i - row);
				int tB = 3 - (j - col);
				re_qualArr[i][j] += qualArr[index][tA][tB];
				re_qualArr[i][j] = re_qualArr[i][j] > 9 ? 9 : re_qualArr[i][j];
				re_qualArr[i][j] = re_qualArr[i][j] < 0 ? 0 : re_qualArr[i][j];
				re_colorArr[i][j] = colorArr[index][tA][tB] == 'W' ? re_colorArr[i][j] : colorArr[index][tA][tB];

			}
		}
	}
	else if (rotCnt == 3) {
		for (int i = row; i < rowMax; i++) {
			for (int j = col; j < colMax; j++) {
				int tA = 3 - (j - col);
				int tB = i - row;
				re_qualArr[i][j] += qualArr[index][tA][tB];
				re_qualArr[i][j] = re_qualArr[i][j] > 9 ? 9 : re_qualArr[i][j];
				re_qualArr[i][j] = re_qualArr[i][j] < 0 ? 0 : re_qualArr[i][j];
				re_colorArr[i][j] = colorArr[index][tA][tB] == 'W' ? re_colorArr[i][j] : colorArr[index][tA][tB];

			}
		}
	}
}

void solve() {
	/*cout << "log: " << endl;
	for (int i = 0; i < 10; i++) {
	if (visited[i] == true) {
	cout << i<<": " << candi[i].i << "," << candi[i].j << "," << candi[i].rotCnt << endl;
	}
	}*/
	for (int i = 0; i < n; i++) {
		if (visited[i] == true) {
			add(i, candi[i].i, candi[i].j, candi[i].rotCnt);
		}
	}

}

void bigDFS(int index, int cnt) {
	if (cnt == 3) {
		solve();

		int result = 0;
		int re_R = 0; int re_B = 0; int re_G = 0; int re_Y = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (re_colorArr[i][j] == 'R')
					re_R += re_qualArr[i][j];
				else if (re_colorArr[i][j] == 'B')
					re_B += re_qualArr[i][j];
				else if (re_colorArr[i][j] == 'G')
					re_G += re_qualArr[i][j];
				else if (re_colorArr[i][j] == 'Y')
					re_Y += re_qualArr[i][j];
			}
		}
		result = 7 * re_R + 5 * re_B + 3 * re_G + 2 * re_Y;
		if (answer < result) {
			answer = result;
			cout << "log: " << re_R << "," << re_B << "," << re_G << "," << re_Y << endl;

		}

		for (int i = 0; i < 4; i++) {
			fill(re_qualArr[i], re_qualArr[i] + 4, 0);
		}
		for (int i = 0; i < 4; i++) {
			fill(re_colorArr[i], re_colorArr[i] + 4, 'W');
		}
		return;
	}
	if (index == n)
		return;
	//cout << "index: " << index<<","<<cnt << endl;
	visited[index] = true;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int rotCnt = 0; rotCnt <= 3; rotCnt++) {
				candi[index] = Node(i, j, rotCnt);
				bigDFS(index + 1, cnt + 1);
			}
		}
	}
	visited[index] = false;
	bigDFS(index + 1, cnt);

}

int main() {

	cin >> n;
	fill(visited, visited + 10, false);
	for (int i = 0; i < 4; i++) {
		fill(re_qualArr[i], re_qualArr[i] + 4, 0);
	}
	for (int i = 0; i < 4; i++) {
		fill(re_colorArr[i], re_colorArr[i] + 4, 'W');
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> qualArr[i][j][k];
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> colorArr[i][j][k];
			}
		}
	}
	bigDFS(0, 0);

	/*add(1, 0, 0, 1);
	add(2, 1, 1, 0);
	add(0, 1, 0, 1);
	int result = 0;
	int re_R = 0; int re_B = 0; int re_G = 0; int re_Y = 0;
	for (int i = 0; i < 5; i++) {
	for (int j = 0; j < 5; j++) {
	if (re_colorArr[i][j] == 'R')
	re_R += re_qualArr[i][j];
	else if (re_colorArr[i][j] == 'B')
	re_B += re_qualArr[i][j];
	else if (re_colorArr[i][j] == 'G')
	re_G += re_qualArr[i][j];
	else if (re_colorArr[i][j] == 'Y')
	re_Y += re_qualArr[i][j];
	}
	}*/
	//cout << "log: " << re_R << "," << re_B << "," << re_G << "," << re_Y << endl;
	cout << answer << endl;

	return 0;
}