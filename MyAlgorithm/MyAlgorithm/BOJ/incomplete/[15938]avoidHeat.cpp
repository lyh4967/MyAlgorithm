#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Pair {
	int a;
	int b;
	Pair() {}
	Pair(int _a, int _b) :a(_a), b(_b) {}
};
class pred {
public:
	bool operator()(Pair a, Pair b) const {
		if (a.a == b.a)
			return a.b < b.b;
		else
			return a.a < b.a;
	}
};

struct Node {
	int a;
	int b;
	int cnt;
	map<Pair, bool, pred>* visited;
	Node() {}
	Node(int _a, int _b, int _cnt, map<Pair, bool, pred>* _visited) :a(_a), b(_b), cnt(_cnt), visited(_visited) {}
};

int Xh, Yh;
int Xs, Ys;
int T;
int n;
long long result = 0;
map<Pair, bool, pred> obs;
map<Pair, int, pred> dp;

bool isRange(int a, int b) {
	return -100000 <= a && a <= 100000 && -100000 <= b && b <= 100000;
}

int dir1[4] = { 0,1,0,-1 };
int dir2[4] = { 1,0,-1,0 };


int dfs(int a, int b, int cnt) {

	Pair tempPair(a, b);
	if (dp.find(tempPair) != dp.end()) {
		if (abs(Xh - a) + abs(Yh - b) <= T - cnt)
			return dp[tempPair];
		return 0;
	}

	if (a == Xh && b == Yh) {
		return 1;
	}
	if (cnt >= T)
		return 0;

	dp.insert(make_pair(tempPair, 0));
	/*cout << "log: ";
	for (auto it = dp.begin(); it != dp.end(); it++) {
	cout << "(" << it->first.a << "," << it->first.b << "," << it->second << ")";
	}
	cout << endl;*/
	for (int i = 0; i < 4; i++) {
		int nextA = a + dir1[i];
		int nextB = b + dir2[i];

		tempPair.a = nextA; tempPair.b = nextB;
		if (isRange(nextA, nextB) && (obs.find(tempPair) == obs.end())) {
			dp[Pair(a, b)] += dfs(nextA, nextB, cnt + 1);
		}
	}
	return dp[Pair(a, b)];
}

void bfs() {
	map<Pair, bool, pred>* visitedObj = new map<Pair, bool, pred>;
	queue<Node> que;
	que.push(Node(Xs, Ys, 0, visitedObj));
	Pair tempPair;

	while (!que.empty()) {

		Node node = que.front(); que.pop();
		int a, b, cnt; map<Pair, bool, pred>* visited;
		a = node.a; b = node.b; cnt = node.cnt; visited = node.visited;

		if (a == Xh && b == Yh) {
			result++;
		}

		if (cnt >= T)
			continue;

		tempPair.a = a; tempPair.b = b;
		if (visited->find(tempPair) != visited->end())
			continue;
		visited->insert(make_pair(Pair(a, b), true));

		for (int i = 0; i < 4; i++) {
			int nextA = a + dir1[i];
			int nextB = b + dir2[i];
			tempPair.a = nextA; tempPair.b = nextB;
			if (isRange(nextA, nextB) && (visited->find(tempPair) == visited->end() && (obs.find(tempPair) == obs.end()))) {
				node.a = a; node.b = b; node.cnt = cnt + 1;
				map<Pair, bool, pred>* tmpVisi = new map<Pair, bool, pred>;
				for (auto it = visited->begin(); it != visited->end(); it++) {
					tmpVisi->insert(make_pair(it->first, it->second));
				}
				node.visited = tmpVisi;
				que.push(node);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> Xs >> Ys;
	cin >> T;
	cin >> Xh >> Yh;
	cin >> n;
	int distance = abs(Xs - Xh) + abs(Xh - Yh);
	if (T - distance >= 0) {
		for (int i = 0; i < n; i++) {
			int Xo, Yo;
			cin >> Xo >> Yo;
			obs.insert(make_pair(Pair(Xo, Yo), true));//Àå¾Ö¹°
		}

		cout << dfs(Xs, Ys, 0) % (1000000000 + 7) << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}