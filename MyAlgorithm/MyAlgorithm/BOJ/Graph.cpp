#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

#define VSIZE 500
void graph(){
	int VertexN; //������ ����
	int EdgeN;// ������ ����
	cin >> VertexN >> EdgeN;
	vector<tuple<int, int, int>> Edge(EdgeN);

	//������ ������ ����
	for (int i = 0; i < EdgeN; i++){
		int A, B, W;//A���� B�� W�� ����ġ�� ������.
		cin >> A >> B >> W;
		Edge.push_back(make_tuple(A, B, W));
	}

	//�������
	int graphMatrix[VSIZE + 1][VSIZE + 1];//�ִ� ������ŭ �̸� ����
	for (auto i : Edge){
		int V1 = get<0>(i);//A
		int V2 = get<1>(i);//B
		int W = get<2>(i);///W

		//����� ���
		graphMatrix[V1][V2] = W;
		graphMatrix[V2][V1] = W;
	}
	for (int i = 1; i < EdgeN + 1; i++)
		graphMatrix[i][i] = 0;
	cout << "========�������=======" << endl;
	for (int i = 1; i < EdgeN + 1; i++){
		for (int j = 1; j < EdgeN + 1; j++){
			cout << graphMatrix[i][j] << ' ';
		}
		cout << endl;
	}


	//��������Ʈ
	vector<pair<int, int>> graphList[VSIZE + 1];
	for (auto i : Edge){
		int V1 = get<0>(i);//A
		int V2 = get<1>(i);//B
		int W = get<2>(i);//W

		graphList[V1].push_back(make_pair(V2, W));
		graphList[V2].push_back(make_pair(V1, W));
	}
	cout << 2 * EdgeN << endl;
	cout << "========��������Ʈ=======" << endl;
	for (int i = 1; i <= EdgeN; i++){
		for (int j = 0; j <= 1; j++)
			cout << i << "->" << graphList[i][j].first << ":" << graphList[i][j].second << endl;
	}

}