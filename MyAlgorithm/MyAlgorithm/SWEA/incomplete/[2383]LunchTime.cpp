#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
	int a; int b; int dis; int target;
	Node() {}
	Node(int _a, int _b, int _dis) :a(_a), b(_b), dis(_dis) {}
};

int N;
int map[10][10];
int k_0;
int k_1;
int peCnt;
int s0_a, s0_b;
int s1_a, s1_b;
vector<Node> stairs[2];
Node people[10];
int visited[10];

bool compare(Node a, Node b) {
	return a.dis < b.dis;
}

void solve() {

	for (int i = 0; i < peCnt; i++) {
		if (visited[i] == 0)
			stairs[0].push_back(Node(people[i].a, people[i].b, abs(people[i].a - s0_a) + abs(people[i].b - s0_b)));
		else
			stairs[1].push_back(Node(people[i].a, people[i].b, abs(people[i].a - s1_a) + abs(people[i].b - s1_b)));
	}

	int length0 = stairs[0].size();
	int length1 = stairs[1].size();

	sort(stairs[0].begin(), stairs[0].end(), compare);
	sort(stairs[1].begin(), stairs[1].end(), compare);



	stairs[0].clear(); stairs[1].clear();


}
void dfs(int index) {
	if (index == peCnt) {
		solve();
		return;
	}

	visited[index] = 0;
	dfs(index + 1);
	visited[index] = 1;
	dfs(index + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;

	for (int test = 1; test <= T; test++) {
		cin >> N;
		k_1 = 0;
		k_0 = 0;
		peCnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					people[i] = Node(i, j, 0);
					peCnt++;
				}
				if (2 <= map[i][j] && map[i][j] <= 10) {
					if (k_0 == 0) {
						k_0 = map[i][j];
						s0_a = i; s0_b = j;
					}
					else {
						k_1 = map[i][j];
						s1_a = i; s1_b = j;
					}

				}
			}
		}








	}

	return 0;
}