#include <iostream>
using namespace std;



int main() {

	int T;
	cin >> T;
	long long com[30][30];
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j)
				com[i][j] = 1;
			else if (j == 0)
				com[i][j] = 1;
			else {
				com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
			}
		}
	}
	for (int test = 1; test <= T; test++) {
		int n, m;//0<n<=m<30
		cin >> n >> m;
		cout << com[m][n] << endl;
	}

	return 0;
}