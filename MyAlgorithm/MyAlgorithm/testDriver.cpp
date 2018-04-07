#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define NSIZE 1000

void dfs(int start, vector<int> graph[], bool* checkArr){
	checkArr[start] = true;
	cout << start << ' ';
	for (int i = 0; i <= (int)graph[start].size(); i++){
		int next = graph[start][i];
		if (!checkArr[next])
			dfs(next, graph, checkArr);
	}

}

void main(){
	int nodeNum, edgeNum, start;
	cin >> nodeNum >> edgeNum >> start;

	bool *checkArr = new bool[nodeNum + 1];
	fill(checkArr, checkArr + nodeNum + 1, false);
	vector<int> *graphList = new vector<int>[nodeNum + 1];
	for (int i = 0; i < edgeNum; i++){
		int startN, endN;
		cin >> startN >> endN;
		graphList[startN].push_back(endN);
	}
	for (int i = 1; i <= nodeNum; i++)
		sort(graphList[i].begin(), graphList[i].end());
	/*for (int i = 1; i < nodeNum; i++){
	cout << i << ":";
	for (int j = 0; j < (int)graphList[i].size(); j++){
	cout<<graphList[i][j] << ' ';
	}
	cout << endl;
	}*/
	dfs(start, graphList, checkArr);

}