#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int idx;
	int damage;
	int health;
	Node() {}
	Node(int _idx, int _damage, int _health) :idx(_idx), damage(_damage), health(_health) {}
};

bool compare(Node a, Node b) {
	if (a.health == b.health)
		return a.damage > b.damage;
	else
		return a.health < b.health;
}

int main() {


	int N;//캐릭 수
	int M;//아이템 수
	vector<int> healths;
	vector<vector<int>> items;
	vector<int> answer;
	cin >> N >> M;
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

	int h_size = healths.size();
	int i_size = items.size();
	vector<Node> items_my;
	for (int i = 0; i < i_size; i++) {
		items_my.push_back(Node(i + 1, items[i][0], items[i][1]));//인덱스, 공격력, 체력
	}

	sort(healths.begin(), healths.end());
	sort(items_my.begin(), items_my.end(), compare);


	/*cout << "health: ";
	for (int i = 0; i < h_size; i++) {
	cout << healths[i] << " ";
	}
	cout << endl;
	*/
	cout << "items_health,damage: ";
	for (int i = 0; i < i_size; i++) {
		cout << items_my[i].health << "," << items_my[i].damage << " ";
	}
	cout << endl;

	int h_idx = 0;
	int i_idx = 0;
	while (h_idx < h_size && i_idx < i_size) {
		if ((healths[h_idx] - items_my[i_idx].health) >= 100) {
			answer.push_back(items_my[i_idx].idx);
			h_idx++;
			i_idx++;

		}
		else {
			h_idx++;
		}
	}

	sort(answer.begin(), answer.end());

	cout << "answer: ";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;


	return 0;
}