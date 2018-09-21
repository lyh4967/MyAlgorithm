#include <iostream>
using namespace std;

int map[20][20];
int answer = 0;
int n, x;

int max_m(int a, int b) {
	return a > b ? a : b;
}
bool isRanged(int a) {
	return 0 <= a && a < n;
}
int main() {

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		//가로건설
		for (int i = 0; i < n; i++) {
			int max_h = 0;
			int index = 0;
			for (int j = 0; j < n; j++) {
				if (max_h < map[i][j]) {
					max_h = map[i][j];
					index = j;
				}
			}

			bool rightFlag = true;
			bool leftFlag = true;
			int copyIndex = index + 1;
			while (copyIndex < n && rightFlag == true) { //오른쪽
				if (map[i][copyIndex - 1] >= map[i][copyIndex]) {//앞에게 작거나같음
					if (map[i][copyIndex - 1] > map[i][copyIndex]) {
						for (int j = copyIndex; j < x + copyIndex - 1; j++) {//활주로 체크
							cout << "log: right:" << copyIndex << "," << i << "," << j << endl;
							cout << "answer: " << answer << endl;

							if (!isRanged(j + 1) || map[i][j] != map[i][j + 1]) {//범위 밖이거나 높이가 다름
								rightFlag = false;
								break;
							}
							copyIndex = j + 1;
						}

					}
					else {//같다면
						copyIndex++;
					}
				}
				else {
					rightFlag = false;
					break;
				}
			}
			cout << "flag: " << rightFlag << endl;
			if (rightFlag == false)
				continue;
			copyIndex = index - 1;
			while (copyIndex >= 0 && leftFlag == true) { //왼쪽

				if (map[i][copyIndex] <= map[i][copyIndex + 1]) {//앞에게 작거나같음
					if (map[i][copyIndex] < map[i][copyIndex + 1]) {
						for (int j = copyIndex; j > copyIndex - x; j--) {//활주로 체크
							cout << "log: left:" << copyIndex << "," << i << "," << j << endl;
							cout << "answer: " << answer << endl;
							if (!isRanged(j - 1) || map[i][j] != map[i][j - 1]) {//범위 밖이거나 높이가 다름
								leftFlag = false;
								break;
							}
							copyIndex = j - 1;
						}
					}
					else {//같다면
						copyIndex--;
					}
				}
				else {
					leftFlag = false;
					break;
				}
			}
			if (rightFlag == true && leftFlag == true)
				answer++;
		}

		//세로건설
		for (int i = 0; i < n; i++) {
			int max_h = 0;
			int index = 0;
			for (int j = 0; j < n; j++) {
				if (max_h < map[j][i]) {
					max_h = map[j][i];
					index = j;
				}
			}
			bool upFlag = true;
			bool downFlag = true;
			int copyIndex = index + 1;
			while (copyIndex < n && downFlag == true) { //아래

				if (map[copyIndex - 1][i] >= map[copyIndex][i]) {//앞에게 작거나같음
					if (map[copyIndex - 1][i] > map[copyIndex][i]) {
						for (int j = copyIndex; j < x + copyIndex - 1; j++) {//활주로 체크
							if (!isRanged(j + 1) || map[j][i] != map[j + 1][i]) {//범위 밖이거나 높이가 다름
								downFlag = false;
								break;
							}
							copyIndex = j + 1;
						}
					}
					else {//같다면
						copyIndex++;
					}
				}
				else {
					downFlag = false;
					break;
				}
			}
			if (downFlag == false)
				continue;
			copyIndex = index - 1;
			while (copyIndex >= 0 && upFlag == true) { //윗쪽
				if (map[copyIndex][i] <= map[copyIndex + 1][i]) {//앞에게 작거나같음
					if (map[copyIndex][i] < map[copyIndex + 1][i]) {
						for (int j = copyIndex; j > copyIndex - x; j--) {//활주로 체크
							if (!isRanged(j - 1) || map[j][i] != map[j - 1][i]) {//범위 밖이거나 높이가 다름
								upFlag = false;
								break;
							}
							copyIndex = j - 1;
						}
					}
					else {//같다면
						copyIndex--;
					}
				}
				else {
					upFlag = false;
					break;
				}
			}
			if (downFlag == true && upFlag == true)
				answer++;
		}
		cout << "#" << test << " " << answer << "\n";
	}

	return 0;
}