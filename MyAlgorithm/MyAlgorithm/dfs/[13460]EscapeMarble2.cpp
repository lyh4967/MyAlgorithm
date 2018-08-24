#include <iostream>
#include <cmath>
#define INF 987654321
using namespace std;

char map[10][10];
int n, m;
int answer = INF;
//1: west, 2: north, 3: east, 4: south
void move(int dir, int& a, int& b, bool& goal) {
	if (dir == 1) {
		while (b > 0) {
			if (map[a][b - 1] == 'O') {
				goal = true;
				break;
			}
			if (map[a][b - 1] == '#') {
				break;
			}
			b--;
		}
	}
	else if (dir == 2) {
		while (a > 0) {
			if (map[a - 1][b] == 'O') {
				goal = true;
				break;
			}
			if (map[a - 1][b] == '#') {
				break;
			}
			a--;
		}
	}
	else if (dir == 3) {
		while (b < m - 1) {
			if (map[a][b + 1] == 'O') {
				goal = true;
				break;
			}
			if (map[a][b + 1] == '#') {
				break;
			}
			b++;
		}
	}
	else if (dir == 4) {
		while (a < n - 1) {
			if (map[a + 1][b] == 'O') {
				goal = true;
				break;
			}
			if (map[a + 1][b] == '#') {
				break;
			}
			a++;
		}
	}
}
bool isPromising(int prev, int next) {
	bool flag = true;
	if (prev == next)
		flag = false;
	if (abs(prev - next) == 2)
		flag = false;
	return flag;

}
void dfs(int cnt, int dir, int r_a, int r_b, int b_a, int b_b) {

	//cout << "log: " << cnt << " | " << dir << " | " << r_a << "," << r_b << " | " << b_a << "," << b_b << endl;

	if (cnt > 10) {
		return;
	}
	if (cnt >= answer)
		return;
	bool r_goal = false;
	bool b_goal = false;
	int t_r_a = r_a; int t_r_b = r_b; int t_b_a = b_a; int t_b_b = b_b;
	move(dir, r_a, r_b, r_goal);
	move(dir, b_a, b_b, b_goal);
	if (b_goal)
		return;
	if (r_goal) {
		if (answer > cnt)
			answer = cnt;
		return;
	}

	if (r_a == b_a && r_b == b_b) {
		if (dir == 1)
			t_r_b < t_b_b ? b_b++ : r_b++;
		else if (dir == 2) {
			t_r_a < t_b_a ? b_a++ : r_a++;
		}
		else if (dir == 3) {
			t_r_b < t_b_b ? r_b-- : b_b--;
		}
		else if (dir == 4) {
			t_r_a < t_b_a ? r_a-- : b_a--;
		}
	}

	for (int i = 1; i <= 4; i++) {
		if (isPromising(dir, i)) {
			dfs(cnt + 1, i, r_a, r_b, b_a, b_b);
		}
	}


}

int main() {
	cin >> n >> m;
	int r_a, r_b, b_a, b_b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				r_a = i; r_b = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				b_a = i; b_b = j;
				map[i][j] = '.';
			}
		}
	}
	dfs(0, -10, r_a, r_b, b_a, b_b);
	if (answer == INF)
		cout << -1 << endl;
	else
		cout << answer << endl;



	return 0;
}