#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<int> people;
	vector<int> tshirts;
	int answer = 0;
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		people.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		tshirts.push_back(tmp);
	}

	int pSize = people.size();
	int tSize = tshirts.size();

	sort(people.begin(), people.end());
	sort(tshirts.begin(), tshirts.end());
	int p_index = 0;
	int t_index = 0;
	while (p_index < pSize && t_index < tSize) {
		if (people[p_index] <= tshirts[t_index]) {
			answer++;
			p_index++;// people index증기
			t_index++;//tshirts index 증가
		}
		else {
			t_index++;//tshirts index 증가
		}
	}

	cout << answer << endl;


	return 0;

}