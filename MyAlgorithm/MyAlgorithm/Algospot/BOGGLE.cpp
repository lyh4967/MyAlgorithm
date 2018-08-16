#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dir[8][2] = { { 0,-1 },{ -1,-1 },{ -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 } };
char map[5][5];
int cache[5][5][10];
int n;
string str;
int length;
bool result;

struct Node {
	int a;
	int b;
	//int index;
	Node(int _a, int _b) :a(_a), b(_b) {}
};
vector<Node>* vec;
bool isRanged(int a, int b) {
	return 0 <= a && a < 5 && 0 <= b && b < 5;
}

int dfs(int a, int b, int index) {
	//cout << "log: " << a << "," << b << "," << index << endl;

	if (cache[a][b][index] != -1)
		return cache[a][b][index];
	if (str[index] != map[a][b])
		return 0;
	if (index == length - 1) {
		return 1;
	}
	cache[a][b][index] = 0;
	for (int i = 0; i < 8; i++) {
		int nextA = a + dir[i][0];
		int nextB = b + dir[i][1];
		if (isRanged(nextA, nextB) && (map[nextA][nextB] == str[index + 1])) {
			cache[a][b][index] |= dfs(nextA, nextB, index + 1);
		}
	}
	return cache[a][b][index];
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				cin >> map[i][j];

		cin >> n;
		for (int ite = 0; ite < n; ite++) {
			cin >> str;
			length = str.size();


			int answer;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						for (int l = 0; l < 5; l++) {
							fill(cache[k][l], cache[k][l] + 10, -1);
						}
					}
					answer = dfs(i, j, 0);
					if (answer == 1)
						break;
				}
				if (answer == 1)
					break;
			}
			if (answer == 1) {
				cout << str << " YES" << endl;
			}
			else {
				cout << str << " NO" << endl;
			}
		}
	}
	return 0;
}