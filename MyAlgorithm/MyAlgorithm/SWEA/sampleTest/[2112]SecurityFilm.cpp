#include <iostream>
using namespace std;

int D, W, K;
int map[13][20];
int candi[13];
int maxCnt;
int answer = 987654321;
void checkK() {


}

void solve() {
	int tempMap[13][20];
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			tempMap[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < D; i++) {
		if (candi[i] != -1) {
			fill(tempMap[i], tempMap[i] + W, candi[i]);
		}
	}

	//check
	for (int i = 0; i < W; i++) {
		int cnt = 1;
		bool flag = false;
		for (int j = 1; j < D; j++) {
			if (tempMap[j][i] == tempMap[j - 1][i]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			if (cnt == K)
				break;
		}
		if (cnt < K) {
			return;
		}
	}
	if (answer > maxCnt) {
		answer = maxCnt;
	}


}

void dfs(int index, int cnt) {

	if (cnt >= answer)
		return;

	if (cnt == maxCnt) {
		solve();
		return;
	}

	if (index >= D)
		return;

	candi[index] = 0;
	dfs(index + 1, cnt + 1);
	candi[index] = 1;
	dfs(index + 1, cnt + 1);
	candi[index] = -1;
	dfs(index + 1, cnt);

}

int main() {



	int T; cin >> T;
	for (int test = 1; test <= T; test++) {

		cin >> D >> W >> K;
		answer = 987654321;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		fill(candi, candi + D, -1);
		for (int i = 0; i <= D; i++) { //D¹øÅõ¾à
			maxCnt = i;
			dfs(0, 0);
		}

		cout << "#" << test << " " << answer << endl;


	}


	return 0;
}