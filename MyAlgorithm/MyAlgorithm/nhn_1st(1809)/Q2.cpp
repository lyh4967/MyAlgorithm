#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string** map;
int n;
void rotation(int rot, int start, int last) {

	string tmp1;
	string tmp2;
	if (rot > 0) {//½Ã°è
		tmp1 = map[start][last];
		for (int i = last; i > start; i--) {//À§
			map[start][i] = map[start][i - 1];
		}

		tmp2 = map[last][last];
		for (int i = last; i > start; i--) {//¿À
			map[i][last] = map[i - 1][last];
		}
		map[start + 1][last] = tmp1;

		tmp1 = map[last][start];
		for (int i = start; i < last; i++) {//¹Ø
			map[last][i] = map[last][i + 1];
		}
		map[last][last - 1] = tmp2;


		for (int i = start; i < last; i++) {//¹Ø
			map[i][start] = map[i + 1][start];
		}
		map[last - 1][start] = tmp1;
	}
	else {

		tmp1 = map[start][start];
		for (int i = start; i < last; i++) {//À§
			map[start][i] = map[start][i + 1];
		}

		tmp2 = map[last][start];
		for (int i = last; i > start; i--) {//¿Þ
			map[i][start] = map[i - 1][start];
		}
		map[start + 1][start] = tmp1;

		tmp1 = map[last][last];
		for (int i = last; i > start; i--) {//¹Ø
			map[last][i] = map[last][i - 1];
		}
		map[last][start + 1] = tmp2;


		for (int i = start; i < last; i++) {//¿À
			map[i][last] = map[i + 1][last];
		}
		map[last - 1][last] = tmp1;
	}




}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				cout << map[i][j];

			}
			else {
				cout << map[i][j] << " ";

			}
		}
		cout << endl;
	}
}

int main() {

	cin >> n;
	int rotate; cin >> rotate;
	map = new string*[n];
	for (int i = 0; i < n; i++) {
		map[i] = new string[n];
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int rot = rotate;
	for (int i = 0; i < abs(rotate); i++) {
		for (int i = 0; i < n / 2; i++) {
			rotation(rot, i, n - 1 - i);
			rot *= -1;
		}
	}
	print();


	return 0;
}