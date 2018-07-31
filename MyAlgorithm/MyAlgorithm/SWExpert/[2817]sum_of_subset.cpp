#include <iostream>
using namespace std;

int cnt = 0;
int n, k;
int arr[20];
bool promising(int index, int sum) {

	if (sum > k)
		return false;
	if (index == n - 1 && sum != k)
		return false;
	int total = sum;
	for (int i = index + 1; i < n; i++) {
		total += arr[i];
	}
	if (total < k)
		return false;
	return true;

}
void dfs(int index, int sum) {

	//cout << index << "," << sum << endl;
	if (promising(index, sum)) {
		if (sum == k) {
			cnt++;
			return;
		}
		dfs(index + 1, sum + arr[index + 1]);
		dfs(index + 1, sum);
	}
}


int main() {

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {

		cin >> n >> k;
		cnt = 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		dfs(-1, 0);
		cout << "#" << test << " " << cnt << endl;
	}

	return 0;
}