#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n;
int cnt = 0;
bool isPromising(int cols[], int i) {

	for (int j = 0; j < i; j++) {
		if ((cols[j] == cols[i]) || abs(cols[j] - cols[i]) == abs(j - i))
			return false;
	}
	return true;
}

void dfs(int cols[], int i) {

	for (int j = 0; j < n; j++) {
		cols[i] = j;
		if (isPromising(cols, i)) {
			if (i == n - 1) {
				cnt++;
			}
			else {
				dfs(cols, i + 1);
			}
		}
	}

}

int main() {

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {

		cin >> n;
		cnt = 0;
		int* cols = new int[n];
		dfs(cols, 0);
		cout << "#" << test << " " << cnt << endl;

	}
	return 0;
}