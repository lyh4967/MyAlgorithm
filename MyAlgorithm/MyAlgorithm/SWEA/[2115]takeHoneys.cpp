#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int n, m, c;
int map[10][10];
int max_m(int a, int b) { return a > b ? a : b; }
int answer = 0;
int result = 0;

struct Node {
	int a; int b;
	Node() {}
	Node(int _a, int _b) :a(_a), b(_b) {}
};
Node honeyTongs[2];

bool compare(int a, int b) {
	return a > b;
}
void print() {
	cout << "print" << endl;
	cout << honeyTongs[0].a << "," << honeyTongs[0].b << " ";
	cout << honeyTongs[1].a << "," << honeyTongs[1].b << endl;
}

int canArr[10];
void getPrice(int a, int b, int index, int sum, int price) {
	if (sum > c) return;
	if (result < price)
		result = price;
	if (index == m)return;
	getPrice(a, b + 1, index + 1, sum + map[a][b], price + map[a][b] * map[a][b]);
	getPrice(a, b + 1, index + 1, sum, price);

}


void dfs(int a, int b, int cnt) {

	if (cnt == 2) {
		int result1, result2;
		result = 0;
		getPrice(honeyTongs[0].a, honeyTongs[0].b, 0, 0, 0);
		result1 = result;
		result = 0;
		getPrice(honeyTongs[1].a, honeyTongs[1].b, 0, 0, 0);
		result2 = result;
		if (answer < result1 + result2) {
			answer = result1 + result2;
		}
		return;
	}

	if (a >= n)
		return;

	if (b + m - 1 < n) {
		Node node(a, b);
		honeyTongs[cnt] = node;
		dfs(a, b + m, cnt + 1);
		dfs(a, b + 1, cnt);
	}
	else {
		dfs(a + 1, 0, cnt);
	}

}

int main() {
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> n >> m >> c;
		answer = 0;
		honeyTongs[0].a = -1; honeyTongs[0].b = -1;
		honeyTongs[1].a = -1; honeyTongs[1].b = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0, 0, 0);

		cout << "#" << test << " " << answer << endl;
	}

	return 0;
}