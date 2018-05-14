#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int appleBoard[101][101];
bool warmBoard[101][101];

queue<pair<int, int>> warmQ;

int N;
int appleNum;
int time = -1;
int dirChangePos = 0;
vector<pair<int, char>> dirChangeV;

int turn(char c, int dir){
	if (c == 'D'){
		dir = dir + 1;
		if (dir > 3)
			dir = 0;
	}
	else{
		dir = dir - 1;
		if (dir < 0)
			dir = 3;
	}
	return dir;
}
bool IsBoundry(int x, int y){
	return (1 <= x&&x <= N) && (1 <= y&&y <= N);
}

void move(int x, int y, int dir){
	time++;//시간증가

	warmBoard[x][y] = true;//지도체크
	warmQ.push(make_pair(x, y));

	for (int i = dirChangePos; i < (int)dirChangeV.size(); i++){//방향선정
		if (dirChangeV[i].first == time){
			dir = turn(dirChangeV[i].second, dir);
			dirChangePos++;
		}
	}

	if (dir == 0){
		if (!IsBoundry(x - 1, y)){
			time++;//시간증가
			return;
		}
		if (warmBoard[x - 1][y] == true){
			time++;//시간증가
			return;
		}
	}
	else if (dir == 1){
		if (!IsBoundry(x, y + 1)){
			time++;//시간증가
			return;
		}
		if (warmBoard[x][y + 1] == true){
			time++;//시간증가
			return;
		}
	}
	else if (dir == 2){
		if (!IsBoundry(x + 1, y)){
			time++;//시간증가
			return;
		}
		if (warmBoard[x + 1][y] == true){
			time++;//시간증가
			return;
		}
	}
	else{
		if (!IsBoundry(x, y - 1)){
			time++;//시간증가
			return;
		}
		if (warmBoard[x][y - 1] == true){
			time++;//시간증가
			return;
		}
	}

	if (!(appleBoard[x][y] == 1)){//사과없으면 꼬리넣음
		int tailX = warmQ.front().first;
		int tailY = warmQ.front().second;
		warmBoard[tailX][tailY] = false;
		warmQ.pop();
	}
	else{
		appleBoard[x][y] = 0;//사과 먹음
	}

	if (dir == 0){
		move(x - 1, y, dir);
	}
	else if (dir == 1){
		move(x, y + 1, dir);
	}
	else if (dir == 2){
		move(x + 1, y, dir);
	}
	else{
		move(x, y - 1, dir);
	}
}

int main(){

	cin >> N;//보드의 크기
	cin >> appleNum;// 사과갯수


	for (int i = 1; i <= N; i++){//사과보드 초기화
		for (int j = 1; j <= N; j++){
			appleBoard[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++){//지렁이보드 초기화
		for (int j = 1; j <= N; j++){
			warmBoard[i][j] = false;
		}
	}
	int x, y;
	for (int i = 0; i < appleNum; i++){//사과좌표
		cin >> x >> y;
		appleBoard[x][y] = 1;
	}


	int dirChangeNum;//방향전환횟수
	cin >> dirChangeNum;
	int tmpI;
	char tmpC;
	for (int i = 0; i < dirChangeNum; i++){
		cin >> tmpI >> tmpC;
		dirChangeV.push_back(make_pair(tmpI, tmpC));
	}
	move(1, 1, 1);
	cout << time << endl;
	return 0;
}