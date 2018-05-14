#include <iostream>
using namespace std;

int N;//세로
int M;//가로
int graph[51][51];
bool checkArr[51][51];
int cnt = 0;
int turnCnt = 0;

int turn(int dir){
	dir = dir - 1;
	if (dir < 0)
		dir = 3;
	return dir;
}
void move2(int x, int y, int dir){
	checkArr[x][y] = true;
	if (dir == 0){
		if (turnCnt == 4){
			if (graph[x + 1][y] == 0 && checkArr[x + 1][y] == true){//후진
				turnCnt = 0;
				move2(x + 1, y, dir);
			}
			else if ((graph[x + 1][y] == 1 && checkArr[x + 1][y] == true)){//종료
				return;
			}
		}
		else{
			if (graph[x][y - 1] == 0 && checkArr[x][y - 1] == false){//청소하러감
				turnCnt = 0;
				move2(x, y - 1, turn(dir));
			}
			else{//방향전환 (청소못함)
				turnCnt++;
				move2(x, y, turn(dir));
			}
		}
	}
	else if (dir == 1){
		if (turnCnt == 4){
			if (graph[x][y - 1] == 0 && checkArr[x][y - 1] == true){
				turnCnt = 0;
				move2(x, y - 1, dir);
			}
			else if (graph[x][y - 1] == 1 && checkArr[x][y - 1] == true){
				return;
			}
		}
		else{
			if (graph[x - 1][y] == 0 && checkArr[x - 1][y] == false){
				turnCnt = 0;
				move2(x - 1, y, turn(dir));
			}
			else{
				turnCnt++;
				move2(x, y, turn(dir));
			}
		}
	}
	else if (dir == 2){
		if (turnCnt == 4){
			if (graph[x - 1][y] == 0 && checkArr[x - 1][y] == true){
				turnCnt = 0;
				move2(x - 1, y, dir);
			}
			else if (graph[x - 1][y] == 1 && checkArr[x - 1][y] == true){
				return;
			}
		}
		else{
			if (graph[x][y + 1] == 0 && checkArr[x][y + 1] == false){
				turnCnt = 0;
				move2(x, y + 1, turn(dir));
			}
			else{
				turnCnt++;
				move2(x, y, turn(dir));
			}
		}
	}
	else if (dir == 3){
		if (turnCnt == 4){
			if (graph[x][y + 1] == 0 && checkArr[x][y + 1] == true){
				turnCnt = 0;
				move2(x, y + 1, dir);
			}
			else if (graph[x][y + 1] == 1 && checkArr[x][y + 1] == true){
				return;
			}
		}
		else{
			if (graph[x + 1][y] == 0 && checkArr[x + 1][y] == false){
				turnCnt = 0;
				move2(x + 1, y, turn(dir));
			}
			else{
				turnCnt++;
				move2(x, y, turn(dir));
			}
		}
	}
}
int main(){
	cin >> N >> M;

	int x, y, dir;
	cin >> x >> y >> dir;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			int tmp;
			cin >> tmp;
			graph[i][j] = tmp;
			checkArr[i][j] = false;
		}
	}
	move2(x, y, dir);

	int cnt2 = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (checkArr[i][j] == true)
				cnt2++;
		}
	}
	cout << cnt2 << endl;
}