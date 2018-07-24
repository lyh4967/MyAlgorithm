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
int n;

void dfs(int** cells, int posi) {

	if (posi == 3) {
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << cells[i][j];
		}
		cout << endl;
	}
	cout << endl;
	int a = cores[posi].a;
	int b = cores[posi].b;


	dfs(cells, posi + 1);
	//3½Ã
	for (int i = b + 1; i < n; i++) {
		cells[a][i] = 2;
	}
	dfs(cells, posi + 1);


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
				if (!(i == 0 || i == n - 1 || j == 0 || j == n - 1)) {
					Pair temp(i, j);
					cores.push_back(temp);
				}
			}
		}
		coreNum = cores.size();
		dfs(cells, 0);


	}

	return 0;
}