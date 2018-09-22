#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {


	int N;//캐릭 수
	int M;//아이템 수
	vector<int> healths;
	vector<vector<int>> items;
	vector<int> answer;

	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		healths.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		vector<int> tmp;
		int tmpA; cin >> tmpA;
		int tmpB; cin >> tmpB;
		tmp.push_back(tmpA);//공격증가
		tmp.push_back(tmpB);//체력감소
		items.push_back(tmp);
	}





	return 0;
}