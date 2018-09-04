#include <iostream>
using namespace std;

int k;
int tobni[4][8];
bool chk[4];
void watch() {

}
bool isRanged(int a) {
	return 0 <= a && a < 4;
}
void rotate(int num, int dir) {
	//	cout << "log: "<<num<<","<<dir << endl;

	if (dir == 1) {//시계
		int temp = tobni[num][7];
		for (int i = 7; i >= 1; i--)
			tobni[num][i] = tobni[num][i - 1];
		tobni[num][0] = temp;
	}
	else {//반
		int temp = tobni[num][0];
		for (int i = 1; i <= 7; i++)
			tobni[num][i - 1] = tobni[num][i];
		tobni[num][7] = temp;
	}

}
void check(int num, int dir) {
	chk[num] = true;//본인

	int next = num + 1;
	while (true) {
		if (isRanged(next) && tobni[next][6] != tobni[next - 1][2]) {
			chk[next] = true;
			next++;
		}
		else
			break;
	}

	next = num - 1;
	while (true) {

		if (isRanged(next) && tobni[next][2] != tobni[next + 1][6]) {
			chk[next] = true;
			next--;
		}
		else
			break;
	}


	rotate(num, dir);
	next = num + 1;
	int nextDir = dir * -1;
	while (true) {

		if (isRanged(next) && chk[next] == true) {
			rotate(next, nextDir);
			next++;
			nextDir *= -1;
		}
		else {
			break;
		}
	}
	next = num - 1;
	nextDir = dir * -1;
	while (true) {
		if (isRanged(next) && chk[next] == true) {
			rotate(next, nextDir);
			next--;
			nextDir *= -1;
		}
		else {
			break;
		}
	}

}

int main() {

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> tobni[i][j];
			}
		}
		for (int i = 0; i < k; i++) {
			int num, dir;
			cin >> num >> dir;

			fill(chk, chk + 4, false);
			check(num - 1, dir);


		}
		int answer = 0;
		int gurantee = 1;
		for (int i = 0; i < 4; i++) {
			if (tobni[i][0] == 1) {
				answer += gurantee;
			}
			gurantee *= 2;
		}
		cout << "#" << test << " " << answer << "\n";
	}

	return 0;
}
