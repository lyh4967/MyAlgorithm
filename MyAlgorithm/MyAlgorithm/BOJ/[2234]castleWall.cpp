#include<iostream>
#include <queue>
using namespace std;
int map[50][50];
int visited[50][50];
int roomNum = 0;
int maxSize = 0;
int dir[4][2] = { { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };
int n, m;
int pro3 = 0;
bool isRanged(int a, int b) {
	return 0 <= a && a < m && 0 <= b && b < n;
}
int max_m(int a, int b) {
	return a > b ? a : b;
}
struct Node {
	int a; int b;

};
void print() {
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			visited[i][j] = -1;
		}
	}
	queue<Node> que;
	Node node;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			if (visited[i][j] == -1) {
				roomNum++;//방갯수 증가
				node.a = i; node.b = j;
				que.push(node);
				int roomSize = 0; //방크기
				int pro3_re = 0; //3번문항 후보
				while (!que.empty()) {
					node = que.front(); que.pop();
					int a = node.a; int b = node.b;

					if (visited[a][b] != -1)
						continue;
					visited[a][b] = 0;
					roomSize++;//방크기증가
					for (int k = 0; k < 4; k++) {
						int bit = 1;
						if (((bit << k) & map[a][b]) == 0) {//비어있는곳 확인
							int nextA = a + dir[k][0];
							int nextB = b + dir[k][1];
							bool flag = true;
							int tempBit;
							if (k == 0)
								tempBit = 2;
							else if (k == 1)
								tempBit = 3;
							else if (k == 2)
								tempBit = 0;
							else
								tempBit = 1;
							if (((bit << tempBit) & map[nextA][nextB]) != 0)// 다음 칸의 벽 확인
								flag = false;
							if (isRanged(nextA, nextB) && flag && visited[nextA][nextB] == -1) {
								node.a = nextA; node.b = nextB;
								que.push(node);
							}
						}
						else {//1칸 뚫을 준비
							int nextA = a + dir[k][0];
							int nextB = b + dir[k][1];
							if (isRanged(nextA, nextB) && (visited[nextA][nextB] != -1) && (visited[nextA][nextB] != 0)) {
								pro3_re = max_m(pro3_re, visited[nextA][nextB]);
							}
						}

					}
				}
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						if (visited[i][j] == 0)
							visited[i][j] = roomSize;
					}
				}
				if (maxSize < roomSize)
					maxSize = roomSize;
				pro3 = max_m(pro3, roomSize + pro3_re);
			}
		}
	}
	//print();
	cout << roomNum << endl << maxSize << endl << pro3 << endl;
	return 0;
}