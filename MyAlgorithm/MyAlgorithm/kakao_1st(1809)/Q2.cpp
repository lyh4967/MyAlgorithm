#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
	int index;
	double per;
public:
	Node() {}
	Node(int _index, double _per) : index(_index), per(_per) {}
};

bool cmp(Node n1, Node n2)
{
	if (n1.per > n2.per)
		return true;
	else if (n1.per == n2.per)
	{
		if (n1.index < n2.index)
			return true;
	}
	return false;
}

int main() {

	int N; cin >> N;
	int peo; cin >> peo;

	vector<int> stages;
	vector<int> answer;
	for (int i = 0; i < peo; i++) {
		int tmp; cin >> tmp;
		stages.push_back(tmp);
	}



	int** staArr = new int*[2];
	for (int i = 0; i < 2; i++) {
		staArr[i] = new int[N + 2];
		fill(staArr[i], staArr[i] + N + 2, 0);
	}
	//sta[0] 은 도달한 사람들
	//sta[1] 은 머물러있는 사람들
	int size = stages.size();
	for (int i = 0; i < size; i++) {
		int reach = stages[i];
		for (int j = 1; j <= reach; j++) {
			staArr[0][j]++;//도달 수 체크;
		}
		staArr[1][reach]++;//머물러 체크;
	}

	vector<double> fail;
	for (int i = 1; i <= N; i++) {
		if (staArr[0][i] == 0) {
			fail.push_back(0);
		}
		else {
			double result = (double)staArr[1][i] / staArr[0][i];
			fail.push_back(result);
		}

	}

	int failSize = fail.size();
	Node* tmpRe = new Node[failSize];
	for (int i = 0; i < failSize; i++) {
		tmpRe[i] = Node(i + 1, fail[i]);
	}

	sort(tmpRe, tmpRe + failSize, cmp);
	for (int i = 0; i < failSize; i++) {
		answer.push_back(tmpRe[i].index);
	}

	return 0;
}