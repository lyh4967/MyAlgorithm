#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

#define VSIZE 500
void graph(){
	int VertexN; //정점의 갯수
	int EdgeN;// 간선의 갯수
	cin >> VertexN >> EdgeN;
	vector<tuple<int, int, int>> Edge(EdgeN);

	//간선의 정보를 저장
	for (int i = 0; i < EdgeN; i++){
		int A, B, W;//A에서 B로 W의 가중치를 가진다.
		cin >> A >> B >> W;
		Edge.push_back(make_tuple(A, B, W));
	}

	//인접행렬
	int graphMatrix[VSIZE + 1][VSIZE + 1];//최대 갯수만큼 미리 선언
	for (auto i : Edge){
		int V1 = get<0>(i);//A
		int V2 = get<1>(i);//B
		int W = get<2>(i);///W

		//양방향 기록
		graphMatrix[V1][V2] = W;
		graphMatrix[V2][V1] = W;
	}
	for (int i = 1; i < EdgeN + 1; i++)
		graphMatrix[i][i] = 0;
	cout << "========인접행렬=======" << endl;
	for (int i = 1; i < EdgeN + 1; i++){
		for (int j = 1; j < EdgeN + 1; j++){
			cout << graphMatrix[i][j] << ' ';
		}
		cout << endl;
	}


	//인접리스트
	vector<pair<int, int>> graphList[VSIZE + 1];
	for (auto i : Edge){
		int V1 = get<0>(i);//A
		int V2 = get<1>(i);//B
		int W = get<2>(i);//W

		graphList[V1].push_back(make_pair(V2, W));
		graphList[V2].push_back(make_pair(V1, W));
	}
	cout << 2 * EdgeN << endl;
	cout << "========인접리스트=======" << endl;
	for (int i = 1; i <= EdgeN; i++){
		for (int j = 0; j <= 1; j++)
			cout << i << "->" << graphList[i][j].first << ":" << graphList[i][j].second << endl;
	}

}