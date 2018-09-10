#include <iostream>
using namespace std;
bool chk[201][201];
int result[3];
int n, m;
int answer = 0;

void print() {
	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}
void dfs(int cnt, int index) {

	if (cnt == 3) {
		//print();
		if (chk[result[0]][result[1]] || chk[result[0]][result[2]] || chk[result[1]][result[2]])
			return;
		else
			answer++;
		return;
	}
	if (index > n)
		return;

	result[cnt] = index;
	dfs(cnt + 1, index + 1);
	dfs(cnt, index + 1);
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int tempA; int tempB;
		cin >> tempA >> tempB;
		chk[tempA][tempB] = true;
		chk[tempB][tempA] = true;
	}
	dfs(0, 1);
	cout << answer << endl;

	return 0;

}