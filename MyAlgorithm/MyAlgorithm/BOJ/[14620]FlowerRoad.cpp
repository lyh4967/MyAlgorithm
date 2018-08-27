#include <iostream>
using namespace std;

struct Node {
	int a;
	int b;
	Node() {}
	Node(int _a, int _b) : a(_a), b(_b) {}
};

int n;
int map[10][10];

Node chk[3];
int answer = 987654321;
bool visited[10][10];
bool isRanged(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < n;
}
bool isPromising(int a, int b) {
	bool flag = true;
	if (!(a + 1 < n && a - 1 >= 0 && b + 1 < n && b - 1 >= 0))
		flag = false;
	if (visited[a][b] || visited[a + 1][b] || visited[a - 1][b] || visited[a][b + 1] || visited[a][b - 1])
		flag = false;
	return flag;

}
void print() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

void print2() {
	cout << "============" << endl;
	for (int i = 0; i < 3; i++) {
		cout << chk[i].a << "," << chk[i].b << endl;
	}
	cout << "===============" << endl;
}
void solve() {
	//print2();
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		if (isPromising(chk[i].a, chk[i].b)) {
			visited[chk[i].a][chk[i].b] = true;
			visited[chk[i].a + 1][chk[i].b] = true;
			visited[chk[i].a - 1][chk[i].b] = true;
			visited[chk[i].a][chk[i].b + 1] = true;
			visited[chk[i].a][chk[i].b - 1] = true;
			sum += map[chk[i].a][chk[i].b];
			sum += map[chk[i].a + 1][chk[i].b];
			sum += map[chk[i].a - 1][chk[i].b];
			sum += map[chk[i].a][chk[i].b + 1];
			sum += map[chk[i].a][chk[i].b - 1];
		}
		else {
			for (int j = 0; j < n; j++) {
				fill(visited[j], visited[j] + n, false);
			}
			return;
		}
	}


	if (answer > sum) {
		//print();
		answer = sum;
	}
	for (int j = 0; j < n; j++) {
		fill(visited[j], visited[j] + n, false);
	}

}
void dfs(int a, int b, int cnt) {

	if (cnt == 3) {
		solve();
		return;
	}
	if (a < n - 1 && b < n - 1) {
		if (b == n - 2) {
			chk[cnt] = Node(a, b);
			dfs(a + 1, 1, cnt + 1);
			dfs(a + 1, 1, cnt);
		}
		else {
			chk[cnt] = Node(a, b);
			dfs(a, b + 1, cnt + 1);
			dfs(a, b + 1, cnt);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			visited[i][j] = false;
		}
	}

	dfs(1, 1, 0);
	cout << answer << endl;


	return 0;
}