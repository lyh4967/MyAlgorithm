#include <iostream>
using namespace std;

int** map;
long long minM= 9223372036854775806;
int n, wait;
int flag;


bool boundry(int a, int b) {
	return (0 <= a && a < n) && (0 <= b && b < n);
}

void dfs(int a,int b,int cnt) {
	if (cnt <= minM) {
		if (a == n - 1 && b == n - 1) {
			if (cnt < minM)
				minM = cnt;
			return;
		}
		if (boundry(a + 1, b)) {
			if (map[a + 1][b] == 1) {
				dfs(a + 1, b, cnt + 1);
			}
			else {
				if (map[a + 1][b] == 0) {
					if (cnt%wait == wait - 1) {
						dfs(a + 1, b, cnt + 1);
					}
					else {
						dfs(a, b, cnt + 1);
					}
				}
				else {
					if (cnt == 0) {
						dfs(a + 1, b, cnt + 1);
					}
					else if (cnt == map[a + 1][b] - 1) {
						dfs(a + 1, b, cnt + 1);
					}
					else {
						dfs(a, b, cnt + 1);
					}
				}
			}
		}
		if (boundry(a, b + 1)) {
			if (map[a][b + 1] == 1) {
				dfs(a, b + 1, cnt + 1);
			}
			else {
				if (map[a][b + 1] == 0) {
					if (cnt%wait == wait - 1) {
						dfs(a, b + 1, cnt + 1);
					}
					else {
						dfs(a, b, cnt + 1);
					}
				}
				else {
					if (cnt == 0) {
						dfs(a, b+1, cnt + 1);
					}
					else if (cnt == map[a][b + 1] - 1) {
						dfs(a, b + 1, cnt + 1);
					}
					else {
						dfs(a, b, cnt + 1);
					}
				}
			}
		}
	}
		
}

int main() {

	int testNum;
	cin >> testNum;
	for (int test = 1; test <= testNum; test++) {
		
		cin >> n >> wait;
		map = new int*[n];
		for (int i = 0; i < n; i++)
			map[i] = new int[n];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		minM = 9223372036854775806;

		dfs(0, 0, 0);
		cout <<"#"<<test<<' '<< minM << endl;


	}

	return 0;
}