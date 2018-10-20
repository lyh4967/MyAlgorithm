#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int a, b, num;
	Node() {}
	Node(int _a, int _b, int _num) :a(_a), b(_b), num(_num) {}
};

int N, W, H;
int map[15][12];
int visited[4];
int copyMap[15][12];
int answer = 987654321;
bool isRanged(int a, int b) {
	return 0 <= a && a < H && 0 <= b && b < W;
}

void print1() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << copyMap[i][j] << " ";
		}
		cout << endl;
	}
}

void down() {

	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			if (copyMap[i][j] == 0) {
				int s_index = i;
				int e_index = i;
				for (int k = s_index; k >= 0; k--) {
					if (copyMap[k][j] != 0) {
						e_index = k;
						break;
					}
				}
				if (e_index != s_index) {
					int temp = copyMap[s_index][j];
					copyMap[s_index][j] = copyMap[e_index][j];
					copyMap[e_index][j] = temp;
				}
				else
					break;
			}
		}
	}

}

void solve() {
	queue<Node> que;
	for (int big = 0; big < N; big++) {

		for (int i = 0; i < H; i++) {//구슬 투하
			if (copyMap[i][visited[big]] != 0) {
				que.push(Node(i, visited[big], copyMap[i][visited[big]]));
				copyMap[i][visited[big]] = 0;
				break;
			}
		}
		while (!que.empty()) {
			Node node = que.front(); que.pop();
			int a = node.a; int b = node.b;
			int num = node.num;

			for (int i = a + 1; i < a + num; i++) {
				if (isRanged(i, b)) {
					if (copyMap[i][b] != 0) {
						que.push(Node(i, b, copyMap[i][b]));
						copyMap[i][b] = 0;
					}
				}
				else
					break;
			}
			for (int i = a - 1; i > a - num; i--) {
				if (isRanged(i, b)) {
					if (copyMap[i][b] != 0) {
						que.push(Node(i, b, copyMap[i][b]));
						copyMap[i][b] = 0;
					}
				}
				else
					break;
			}
			for (int i = b + 1; i < b + num; i++) {
				if (isRanged(a, i)) {
					if (copyMap[a][i] != 0) {
						que.push(Node(a, i, copyMap[a][i]));
						copyMap[a][i] = 0;
					}
				}
				else
					break;
			}
			for (int i = b - 1; i > b - num; i--) {
				if (isRanged(a, i)) {
					if (copyMap[a][i] != 0) {
						que.push(Node(a, i, copyMap[a][i]));
						copyMap[a][i] = 0;
					}
				}
				else
					break;
			}

		}//한싸이클
		down();

		/*cout << endl;
		print1();*/

	}//big

}
void dfs(int index) {
	if (answer == 0)
		return;
	if (index == N) {
		/*for (int i = 0; i < N; i++) {
		cout <<"visited: "<< visited[i] << " ";
		}
		cout << endl;*/
		solve();
		int result = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (copyMap[i][j] != 0)
					result++;
			}
		}
		if (answer > result) {
			answer = result;
		}

		//복구
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				copyMap[i][j] = map[i][j];
			}
		}
		return;
	}

	for (int i = 0; i < W; i++) {
		visited[index] = i;
		dfs(index + 1);
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;

	for (int test = 1; test <= T; test++) {

		cin >> N >> W >> H;
		answer = 987654321;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				copyMap[i][j] = map[i][j];
			}
		}
		dfs(0);

		cout << "#" << test << " " << answer << endl;
	}//test
}