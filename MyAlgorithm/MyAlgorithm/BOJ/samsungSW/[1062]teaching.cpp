#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, k;
string strArr[50];
vector<char> candi;
int candiSize = 0;
bool chk[26]; //¾ËÆÄºª Ã¼Å©
char baseAl[5] = { 'a','n','t','i','c' };
int answer = 0;

void print() {
	for (int i = 0; i < 26; i++) {
		cout << chk[i] << " ";
	}
	cout << endl;
}

void dfs(int index, int cnt) {

	if (cnt == k - 5 || cnt == candiSize) {
		int result = 0;
		for (int i = 0; i < n; i++) {
			int length = strArr[i].size();
			bool complete = true;
			for (int j = 0; j < length; j++) {
				if (!chk[strArr[i][j] - 'a'])
					complete = false;
			}
			if (complete)
				result++;
		}
		if (answer < result)
			answer = result;
		return;
	}

	if (index == candiSize)
		return;

	chk[candi[index] - 'a'] = true;
	dfs(index + 1, cnt + 1);
	chk[candi[index] - 'a'] = false;
	dfs(index + 1, cnt);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fill(chk, chk + 26, false);
	cin >> n >> k;
	for (int i = 0; i < 5; i++) {
		chk[baseAl[i] - 'a'] = true;
	}

	bool tempCharArr[26];
	fill(tempCharArr, tempCharArr + 26, false);
	for (int i = 0; i < n; i++) {
		string tempStr; cin >> tempStr;
		for (int j = 4; j < (tempStr.size() - 4); j++) {
			if (!chk[tempStr[j] - 'a']) {
				strArr[i] += tempStr[j];
				tempCharArr[tempStr[j] - 'a'] = true;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (tempCharArr[i] == true)
			candi.push_back(i + 'a');
	}
	candiSize = candi.size();

	if (k >= 5) {
		dfs(0, 0);
	}
	cout << answer << endl;


	return 0;
}
/*
5 10
antadeogtica
antabrotica
antawogtica
antaefzbtica
antabtica

3 10
antawwtica
antabtica
antatica
*/