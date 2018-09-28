#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int a; int b;
	Node() {}
	Node(int _a, int _b) :a(_a), b(_b) {}
};
int N;
vector<Node> wormHalls[11];
long long answer;

int map[100][100];
//E:0, S:1, W:2, N:3
int dirArr[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
bool isRanged(int a, int b) {
	return 0 <= a && a < N && 0 <= b && b < N;
}
void simul(int sA, int sB, int sDir) {

	int a = sA; int b = sB; int dir = sDir;
	int nA, nB;
	long long score = 0;

	while (true) {
		nA = a + dirArr[dir][0];
		nB = b + dirArr[dir][1];
		if (isRanged(nA, nB)) {

			if ((nA == sA && nB == sB) || (map[nA][nB] == -1)) {
				if (answer < score) {
					answer = score;
				}
				break;
			}
			else if (map[nA][nB] == 0) {
				a = nA;
				b = nB;
				continue;
			}
			else if (map[nA][nB] == 1) { //1번
				if (dir == 0) {
					dir = 2;
				}
				else if (dir == 1) {
					dir = 0;
				}
				else if (dir == 2) {
					dir = 3;
				}
				else {//3
					dir = 1;
				}
				score++;
			}
			else if (map[nA][nB] == 2) { //2번
				if (dir == 0) {
					dir = 2;
				}
				else if (dir == 1) {
					dir = 3;
				}
				else if (dir == 2) {
					dir = 1;
				}
				else {//3
					dir = 0;
				}
				score++;
			}
			else if (map[nA][nB] == 3) { //3번
				if (dir == 0) {
					dir = 1;
				}
				else if (dir == 1) {
					dir = 3;
				}
				else if (dir == 2) {
					dir = 0;
				}
				else {//3
					dir = 2;
				}
				score++;
			}
			else if (map[nA][nB] == 4) { //1번
				if (dir == 0) {
					dir = 3;
				}
				else if (dir == 1) {
					dir = 2;
				}
				else if (dir == 2) {
					dir = 0;
				}
				else {//3
					dir = 1;
				}
				score++;

			}
			else if (map[nA][nB] == 5) { //1번
				dir = (dir + 2) % 4;
				score++;

			}
			else if (6 <= map[nA][nB] && map[nA][nB] <= 10) {//6~10
				if (wormHalls[map[nA][nB]][0].a == nA && wormHalls[map[nA][nB]][0].b == nB) {

					int tmpA, tmpB;
					tmpA = wormHalls[map[nA][nB]][1].a;
					tmpB = wormHalls[map[nA][nB]][1].b;
					nA = tmpA;
					nB = tmpB;
				}
				else {
					int tmpA, tmpB;
					tmpA = wormHalls[map[nA][nB]][0].a;
					tmpB = wormHalls[map[nA][nB]][0].b;
					nA = tmpA;
					nB = tmpB;
				}

			}
			a = nA; b = nB;

		}
		else {
			dir = (dir + 2) % 4;
			score++;
			a = nA; b = nB;
		}

	}


}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;

	for (int test = 1; test <= T; test++) {
		answer = 0;
		for (int i = 6; i <= 10; i++)
			wormHalls[i].clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (6 <= map[i][j] && map[i][j] <= 10) {
					wormHalls[map[i][j]].push_back(Node(i, j));
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 4; k++) {
					if (map[i][j] == 0)
						simul(i, j, k);
				}
			}
		}
		cout << "#" << test << " " << answer << endl;
	}

	return 0;
}