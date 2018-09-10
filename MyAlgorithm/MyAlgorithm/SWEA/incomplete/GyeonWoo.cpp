#include <iostream>
using namespace std;

int** map;
//bool** visited;
long long minM = 9223372036854775806;

int n, wait;

bool boundry(int a, int b) {
	return (0 <= a && a < n) && (0 <= b && b < n);
}

bool isCross(int a, int b) {
	bool flag = false;
	if (map[a][b] == 0) {
		if (boundry(a + 1, b) && boundry(a, b + 1) && map[a + 1][b] == 0 && map[a][b + 1] == 0)//down&&right
			flag = true;
		if (boundry(a, b + 1) && boundry(a - 1, b) && map[a][b + 1] == 0 && map[a - 1][b] == 0)//right&&up
			flag = true;
		if (boundry(a - 1, b) && boundry(a, b - 1) && map[a - 1][b] == 0 && map[a][b - 1] == 0)//up&&left
			flag = true;
		if (boundry(a, b - 1) && boundry(a + 1, b) && map[a][b - 1] == 0 && map[a + 1][b] == 0)//left && down
			flag = true;
	}
	return flag;
}



void dfs(int a, int b, int cnt) {
	if (isCross(a, b))
		return;
	if (cnt > minM)
		return;
	if (a == n - 1 && b == n - 1) {
		if (cnt < minM) {
			minM = cnt;
		}
	}
	else {
		//visited[a][b] = true;
		int changeCnt = 0;
		if (boundry(a, b + 1)) {//right
			if (map[a][b + 1] == 1) {//1일때
				dfs(a, b + 1, cnt + 1);
			}
			else if (map[a][b + 1] == 0) {//0일때
				changeCnt = wait - (cnt % wait);
				dfs(a, b + 1, cnt + changeCnt);
			}
			else if (map[a][b + 1] > 1) {//임시 오작교
				changeCnt = map[a][b + 1] - (cnt % map[a][b + 1]);
				dfs(a, b + 1, cnt + changeCnt);
			}
		}

		if (boundry(a + 1, b)) {//down
			if (map[a + 1][b] == 1) {//1일때
				dfs(a + 1, b, cnt + 1);
			}
			else if (map[a + 1][b] == 0) {//0일때
				changeCnt = wait - (cnt % wait);
				dfs(a + 1, b, cnt + changeCnt);
			}
			else if (map[a + 1][b] > 1) {//임시 오작교
				changeCnt = map[a + 1][b] - (cnt % map[a + 1][b]);
				dfs(a + 1, b, cnt + changeCnt);
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
		//visited = new bool*[n];
		for (int i = 0; i < n; i++) {
			map[i] = new int[n];
			//  visited[i] = new bool[n];
			//  fill(visited[i], visited[i] + n, false);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		minM = 9223372036854775806;

		dfs(0, 0, 0);
		cout << "#" << test << ' ' << minM << endl;
	}

	return 0;
}