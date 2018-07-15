#include <iostream>
using namespace std;
int main() {

	int N;
	cin >> N;

	bool room[101][101];

	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == '.')
				room[i][j] = true;
			else
				room[i][j] = false;
		}
	}

	int widthCnt = 0;
	int heightCnt = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) { //가로
		cnt = 0;
		for (int j = 0; j < N; j++) {
			if (room[i][j] == true)
				cnt++;
			else
				cnt = 0;
			if (cnt == 2) {
				widthCnt++;
			}
		}
	}

	for (int j = 0; j < N; j++) { //세로
		cnt = 0;
		for (int i = 0; i < N; i++) {
			if (room[i][j] == true)
				cnt++;
			else
				cnt = 0;
			if (cnt == 2) {
				heightCnt++;
			}
		}
	}
	cout << widthCnt << ' ' << heightCnt << endl;
	return 0;
}