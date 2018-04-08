#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void dfs(int start, vector<int>graph[], bool check[]){
	check[start] = true;
	cout << start;

	for (int i = 0; i < (int)graph[start].size(); i++){
		int next = graph[start][i];
		//방문하지 않았다면
		if (check[next] = false){
			//재귀함수를 호출한다
			dfs(next, graph, check);
		}
	}
}
