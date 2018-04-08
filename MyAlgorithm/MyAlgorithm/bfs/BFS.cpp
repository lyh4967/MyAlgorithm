#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int start, vector<int> graph[], bool check[]){
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()){
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for (int i = 0; i<(int)graph[tmp].size(); i++){

			// 방문하지 않았다면
			if (check[graph[tmp][i]] == false){
				// 큐에 넣어주고 방문했음을 표시한다.
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}

}
