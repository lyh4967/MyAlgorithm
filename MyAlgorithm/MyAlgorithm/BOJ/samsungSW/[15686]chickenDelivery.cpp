#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 51
#define MAX_M 14
#define INF 987654321
int n, m;
int map[MAX_N][MAX_N];
bool visited[MAX_M];
int house_len;
int chicken_len;
int answer = INF;
struct Pair {
	int a;
	int b;
	long long cnt;
	Pair() { cnt = 0; }
	Pair(int _a, int _b) :a(_a), b(_b) { cnt = 0; }
};
vector<Pair> houses;
vector<Pair> chickens;

void dfs(int index, int c_cnt) {

	if (index == chicken_len + 1)
		return;
	if (c_cnt == m) {
		/*cout << "log: " << c_cnt << endl;
		for (int i = 0; i < chicken_len; i++)
		cout << visited[i] << " ";
		cout << endl;*/

		int result = 0;
		for (int i = 0; i < house_len; i++) {
			int minDis = INF;
			for (int j = 0; j < chicken_len; j++) {
				if (visited[j] == true) {
					int dis = abs(houses[i].a - chickens[j].a) + abs(houses[i].b - chickens[j].b);
					if (dis < minDis)
						minDis = dis;
				}
			}
			result += minDis;
		}
		if (answer > result)
			answer = result;
		return;
	}

	visited[index] = true;
	dfs(index + 1, c_cnt + 1);
	visited[index] = false;
	dfs(index + 1, c_cnt);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				houses.push_back(Pair(i, j));
			else if (map[i][j] == 2)
				chickens.push_back(Pair(i, j));
		}
	}
	house_len = houses.size();
	chicken_len = chickens.size();
	fill(visited, visited + MAX_M, false);

	dfs(0, 0);
	cout << answer << endl;

	return 0;
}