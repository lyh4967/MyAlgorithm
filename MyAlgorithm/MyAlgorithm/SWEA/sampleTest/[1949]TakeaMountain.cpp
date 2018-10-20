/*
1. ���� ���� ���츮
2. ��->�� ���ζǴ� ���ι������� ����
3. �� �Ѱ��� ���ؼ� �ִ� K���̸�ŭ ������ �������ִ�.

a. �ϴ��� �湮ó�� ���غ��� �ȵǸ� �غ���
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int a, b, cnt, dep;
	bool flag;
	Node() {}
	Node(int _a, int _b, int _cnt, int _dep, bool _flag) :a(_a), b(_b), cnt(_cnt), dep(_dep), flag(_flag) {}
};

int map[8][8];
bool visited[8][8][6];
int N, K;
int answer;

int dirArr[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

bool isRanged(int a, int b) {
	return 0 <= a && a < N && 0 <= b && b < N;
}
int main() {

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {

		//�ʱ�ȭ
		cin >> N >> K;
		queue<Node> que;
		vector<Node> candi;
		int tmpMax = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (tmpMax < map[i][j]) {
					tmpMax = map[i][j];
					candi.clear();
					candi.push_back(Node(i, j, 1, 0, false));
				}
				else if (tmpMax == map[i][j]) {
					candi.push_back(Node(i, j, 1, 0, false));
				}
			}
		}

		answer = 0;
		//	candi.clear();
		Node node; int a, b, cnt, dep; bool flag;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k <= K; k++) {
					map[i][j] = map[i][j] - k;
					for (int big = 0; big < candi.size(); big++) {
						//cout << candi[big].a << "," << candi[big].b << endl;
						que.push(Node(candi[big].a, candi[big].b, candi[big].cnt, candi[big].dep, candi[big].flag));//����� ��� ����;

						while (!que.empty()) {
							node = que.front(); que.pop();
							a = node.a; b = node.b; cnt = node.cnt;
							if (answer < cnt) {
								answer = cnt;
							}

							for (int i = 0; i < 4; i++) {
								int nA = a + dirArr[i][0];
								int nB = b + dirArr[i][1];
								if (isRanged(nA, nB) && map[nA][nB] < map[a][b]) {
									que.push(Node(nA, nB, cnt + 1, 0, false));
								}
							}

						}//que while
					}//Big
					map[i][j] = map[i][j] + k;
				}
			}
		}


		cout << "#" << test << " " << answer << endl;

	}//test

	return 0;
}