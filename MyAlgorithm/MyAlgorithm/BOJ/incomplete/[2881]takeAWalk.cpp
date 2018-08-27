#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Pair {
public:
	int x;
	int y;
	Pair() {}
	Pair(int x_, int y_) :x(x_), y(y_) {}

};

bool compare(Pair a, Pair b) {
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

int main() {
	int n;
	cin >> n;
	Pair* arr = new Pair[n];
	int* arrX = new int[n];
	int x;
	int y;
	for (int i = 0; i < n; i++) {

		cin >> x >> y;
		Pair tree(x, y);
		arr[i] = tree;
	}

	sort(arr, arr + n, compare);

	/*cout << endl;
	for (int i = 0; i < n; i++) {
	cout << arr[i].x << ' ' << arr[i].y << endl;
	}*/

	int p;
	cin >> p;
	for (int i = 0; i < p; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int cnt = 0;
		Pair temp1(x1, y1);
		int startIndex = lower_bound(arr, arr + n, temp1, compare) - arr;
		Pair temp2(x2, y2);
		int endIndex = (upper_bound(arr, arr + n, temp2, compare) - arr) - 1;

		/*cout << "start: " << startIndex << endl;
		cout << "end: " << endIndex << endl;*/

		for (int j = startIndex; j <= endIndex; j++) {
			x = arr[j].x;
			y = arr[j].y;
			if (x == x1 || x == x2 || y == y1 || y == y2) {
				if (
					((y == y1) && (x1 <= x && x < x2)) ||
					((x == x2) && (y1 <= y && y < y2)) ||
					((y == y2) && (x1 < x && x <= x2)) ||
					((x == x1) && (y1 < y && y <= y2))
					) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}