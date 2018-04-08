#include<iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
int N;//������ ũ��
int cnt;

bool testBoundry(int a, int b){
	return ((a < N&&a >= 0) && (b < N&&b >= 0));
}

int dirArr[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };//Ž���ҹ�������

void dfs(int **graphArr,bool **checkArr, int a,int b){
	cnt++;//�湮�� ī��Ʈ
	checkArr[a][b] = true;//�湮�� üũ�Ѵ�.
	for (int i = 0; i < 4; i++){//4���� ��� Ž���Ѵ�.
		int x = a + dirArr[i][0];
		int y = b + dirArr[i][1];
		if (testBoundry(x, y)&&(checkArr[x][y] == false) && (graphArr[x][y] == 1))
			dfs(graphArr, checkArr, x, y);
	}
}


int main(){

	cin >> N;
	int **graphArr = new int*[N];
	for (int i = 0; i < N; i++)
		graphArr[i] = new int[N];
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%1d", &graphArr[i][j]);
		}
	}

	bool **checkArr = new bool*[N];
	for (int i = 0; i < N; i++){
		checkArr[i] = new bool[N];
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			checkArr[i][j] = false;
		}
	}

	vector<int> cntVector;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if ((graphArr[i][j] == 1)&&(checkArr[i][j]==false)){
				cnt = 0;
				dfs(graphArr, checkArr, i, j);
				cntVector.push_back(cnt);
			}
		}
	}
	sort(cntVector.begin(), cntVector.end());
	cout << cntVector.size() << endl;
	for (int i = 0; i < (int)cntVector.size(); i++)
		cout << cntVector[i] << endl;
	return 0;
}