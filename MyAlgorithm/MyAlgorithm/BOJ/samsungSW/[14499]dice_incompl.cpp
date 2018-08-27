#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int board[21][21];
int dice[3][4];
bool flag = false;

//µ¿: 1 ¼­: 2 ºÏ:3 ³²:4

void MoveDice(int dir){
	if (dir == 1){
		int tmp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = tmp;
	}
	else if (dir == 2){
		int tmp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = tmp;
	}
	else if (dir == 3){
		int tmp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = tmp;
	}
	else{
		int tmp = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = dice[3][1];
		dice[3][1] = tmp;
	}
}

bool IsBoundry(int x, int y){
	return ((0 <= x && x <= N - 1) && (0 <= y && y <= M - 1));
}

void Game(int a, int b, queue<int>& command){

	if (IsBoundry(a, b) && flag == true){
		if (board[a][b] != 0){
			dice[3][1] = board[a][b];
		}
		else{
			board[a][b] = dice[3][1];
		}
		cout << dice[1][1] << endl;
	}
	/*for (int i = 0; i < 4; i++){
	for (int j = 0; j < 3; j++){
	cout << dice[i][j] << ' ';
	}
	cout << endl;
	}
	cout << endl;*/
	flag = true;

	if (command.empty())
		return;

	int dir = command.front();
	command.pop();
	if (dir == 1){
		MoveDice(1);
		Game(a, b + 1, command);
	}
	else if (dir == 2){
		MoveDice(2);
		Game(a, b - 1, command);
	}
	else if (dir == 3){
		MoveDice(3);
		Game(a - 1, b, command);
	}
	else{
		MoveDice(4);
		Game(a + 1, b, command);
	}
}

int main(){
	int x, y, K;
	int tmp;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> tmp;
			board[i][j] = tmp;
		}
	}
	queue<int> command;
	int tmpDir;
	for (int i = 0; i < K; i++){
		cin >> tmpDir;
		command.push(tmpDir);
	}
	Game(x, y, command);

}