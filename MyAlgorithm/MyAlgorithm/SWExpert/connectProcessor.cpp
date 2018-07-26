#include <iostream>
#include <vector>
using namespace std;

struct Pair {
	int a;
	int b;
	Pair(int _a, int _b) :a(_a), b(_b) {}
};

vector<Pair> cores;
int coreNum;
int maxCoreNum;
int minLineNum;
int n;

void dfs(int** cells, int posi, int coreCnt) {

	if (posi == coreNum) {
		int lineNum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cells[i][j] == 2) {
					lineNum++;
				}
			}
		}
		if (coreCnt > maxCoreNum) {
			maxCoreNum = coreCnt;
			minLineNum = lineNum;
		}
		else if (coreCnt == maxCoreNum)
			if (minLineNum > lineNum) minLineNum = lineNum;
		return;
	}

	int a = cores[posi].a;
	int b = cores[posi].b;
	bool collision = false;

	//3시
	for (int i = b + 1; i < n; i++) {
		if (cells[a][i] != 0) {
			collision = true;
			break;
		}
	}
	if (collision == false) {
		for (int i = b + 1; i < n; i++) {
			cells[a][i] = 2;
		}
		dfs(cells, posi + 1, coreCnt + 1);
		for (int i = b + 1; i < n; i++) {
			cells[a][i] = 0;
		}
	}

	//6시
	collision = false;
	for (int i = a + 1; i < n; i++) {
		if (cells[i][b] != 0) {
			collision = true;
			break;
		}
	}
	if (collision == false) {
		for (int i = a + 1; i < n; i++) {
			cells[i][b] = 2;
		}
		dfs(cells, posi + 1, coreCnt + 1);
		for (int i = a + 1; i < n; i++) {
			cells[i][b] = 0;
		}
	}

	//9시
	collision = false;
	for (int i = b - 1; i >= 0; i--) {
		if (cells[a][i] != 0) {
			collision = true;
			break;
		}
	}
	if (collision == false) {
		for (int i = b - 1; i >= 0; i--) {
			cells[a][i] = 2;
		}
		dfs(cells, posi + 1, coreCnt + 1);
		for (int i = b - 1; i >= 0; i--) {
			cells[a][i] = 0;
		}
	}

	//12시
	collision = false;
	for (int i = a - 1; i >= 0; i--) {
		if (cells[i][b] != 0) {
			collision = true;
			break;
		}
	}
	if (collision == false) {
		for (int i = a - 1; i >= 0; i--) {
			cells[i][b] = 2;
		}
		dfs(cells, posi + 1, coreCnt + 1);
		for (int i = a - 1; i >= 0; i--) {
			cells[i][b] = 0;
		}
	}

	//그냥넘김
	dfs(cells, posi + 1, coreCnt);
}
int main() {

	int testNum;
	cin >> testNum;

	for (int test = 1; test <= testNum; test++) {
		cin >> n;
		int** cells = new int*[n];
		for (int i = 0; i < n; i++)
			cells[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cells[i][j];
				if (cells[i][j] == 1) {
					if (!(i == 0 || i == n - 1 || j == 0 || j == n - 1)) {
						Pair temp(i, j);
						cores.push_back(temp);
					}
				}
			}
		}
		coreNum = cores.size();
		maxCoreNum = 0;
		minLineNum = 987654321;
		dfs(cells, 0, 0);
		cout << "#" << test << ' ' << minLineNum << endl;
		cores.clear();

	}

	return 0;
}