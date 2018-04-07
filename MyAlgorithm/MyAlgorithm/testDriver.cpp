#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<int> *graph, bool *check,int& cnt){
	if (check[start]){//�̹� �湮�ߴ����̶�� ����
		return;
	}
	check[start] = true;
	int next = graph[start][0]; // ���� �湮��� ����
	if (!check[next])
		dfs(next, graph, check, cnt);
	else
		cnt++;// �����湮��Ұ� üũ�Ǿ��ִٸ� ī��Ʈ++
}

int main(){
	int testNum, nodeNum;
	cin >> testNum;

	while (testNum > 0){
		cin >> nodeNum;   
		bool *checkArr = new bool[nodeNum + 1];
		fill(checkArr, checkArr + nodeNum + 1, false);
		vector<int> *graphList = new vector<int>[nodeNum+1];
		for (int i = 1; i <= nodeNum; i++){
			int tmp;
			cin >> tmp;
			graphList[i].push_back(tmp);
		}
		int cnt = 0; 
		for (int i = 1; i <= nodeNum; i++)
			dfs(i, graphList, checkArr, cnt);
		cout << cnt << endl;
		testNum--;
	}
}