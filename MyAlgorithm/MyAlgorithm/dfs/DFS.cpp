#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void dfs(int start, vector<int>graph[], bool check[]){
	check[start] = true;
	cout << start;

	for (int i = 0; i < (int)graph[start].size(); i++){
		int next = graph[start][i];
		//�湮���� �ʾҴٸ�
		if (check[next] = false){
			//����Լ��� ȣ���Ѵ�
			dfs(next, graph, check);
		}
	}
}
