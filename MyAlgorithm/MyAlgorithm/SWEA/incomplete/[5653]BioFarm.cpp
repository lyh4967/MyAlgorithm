#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int map[1000][1000];
int visited[1000][1000];
struct Node {
	int a, b;
	int life;
	bool status;
	bool extend;
	int inactiveCnt;
	int maxLife;
	Node() {}
	Node(int _a, int _b, int _life, bool _status, int _inativeCnt, bool _extend, int _maxLife) :maxLife(_maxLife), extend(_extend), a(_a), b(_b), life(_life), status(_status), inactiveCnt(_inativeCnt) {}
};
int dirArr[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
void print() {
	for (int i = 395; i < 410; i++) {
		for (int j = 395; j < 410; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void print2() {
	for (int i = 395; i < 410; i++) {
		for (int j = 395; j < 410; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;



	for (int test = 1; test <= T; test++) {
		cin >> N >> M >> K;
		queue<Node> que;
		for (int i = 0; i < 1000; i++) {
			fill(map[i], map[i] + 1000, 0);
			fill(visited[i], visited[i] + 1000, 0);
		}
		queue<Node> tempQ;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[400 + i][400 + j];
				if (map[400 + i][400 + j] != 0) {
					que.push(Node(400 + i, 400 + j, map[400 + i][400 + j], false, map[400 + i][400 + j], false, map[400 + i][400 + j]));
					visited[400 + i][400 + j] = 2;
				}
			}
		}
		Node node;
		for (int time = 0; time <= K; time++) {
			//print();
			//cout << endl;
			/*print2();
			cout << endl;*/
			int cnt = 0;
			while (!que.empty()) {
				node = que.front(); que.pop();
				int a = node.a; int b = node.b; int life = node.life; bool status = node.status; int inactiveCnt = node.inactiveCnt;
				//cout << "log: " << a - 400 << "," << b - 400 << "," << inactiveCnt << endl;
				bool extend = node.extend; int maxLife = node.maxLife;
				if (inactiveCnt > 0) {//비활성화 상태
					node.a = a; node.b = b; node.life = life; node.status = status; node.inactiveCnt = inactiveCnt - 1;
					node.extend = extend; node.maxLife = maxLife;
					tempQ.push(node);
				}
				else {//활성화 상태
					  /*if (visited[a][b] == 2)
					  continue;*/

					if (extend == true) {//한번 분열함
						node.a = a; node.b = b; node.life = life - 1; node.status = status; node.inactiveCnt = inactiveCnt;
						node.extend = extend; node.maxLife = maxLife;
						tempQ.push(node);
						continue;
					}
					//tempQ에서 que로 넣을때 visited 2로 초기화하자 넣을때 life확인도
					for (int i = 0; i < 4; i++) {
						int nA = a + dirArr[i][0];
						int nB = b + dirArr[i][1];

						if (visited[nA][nB] != 2) {//이미 배양

							if (visited[nA][nB] == 1) {//사이클 도는중 이미 있다면 더 큰걸로
								if (map[nA][nB] < maxLife) {
									map[nA][nB] = maxLife;
									node.a = nA; node.b = nB; node.life = map[a][b]; node.status = status; node.inactiveCnt = map[a][b];
									node.extend = false; node.maxLife = maxLife;
									tempQ.push(node);
								}

							}
							else {
								node.a = nA; node.b = nB; node.life = map[a][b]; node.status = status; node.inactiveCnt = map[a][b];
								node.extend = false; node.maxLife = maxLife;
								visited[nA][nB] = 1;
								map[nA][nB] = maxLife;
								tempQ.push(node);

								node.a = a; node.b = b; node.life = life - 1; node.status = status; node.inactiveCnt = inactiveCnt;
								node.extend = extend; node.maxLife = maxLife;

								tempQ.push(node);
							}
						}

					}
				}


			}
			while (!tempQ.empty()) {//que에 다시 넣어줌
				node = tempQ.front(); tempQ.pop();
				if (map[node.a][node.b] != node.maxLife)//그자리의 maxLife랑다르다면
					continue;
				visited[node.a][node.b] = 2;


				if (node.life != 0) {
					que.push(node);
					cnt++;
				}
			}
			//cout << "cnt: " << cnt << endl;


		}//for
		int answer = 0;
		while (!que.empty()) {
			node = que.front(); que.pop();
			if (node.life != 0)
				answer++;
		}
		cout << "#" << test << " " << answer << endl;




	}


	return 0;
}