#include <iostream>
#include <cmath>
using namespace std;

struct Node {
	int x; int y;
	int C; int P;
	Node() {}
	Node(int _a, int _b, int _C, int _P) :x(_a), y(_b), C(_C), P(_P) {}
};

int M, A;
int comA[100];
int comB[100];
Node infoBC[8];
bool a_candi[8];
bool b_candi[8];
int selecCandi[2];
int a_x = 1;
int a_y = 1;
int b_x = 10;
int b_y = 10;
int map[11][11];
int answer = 0;
void check() {
	for (int i = 0; i < A; i++) {//영향받는 리스트 추가
		if ((abs(a_x - infoBC[i].x) + abs(a_y - infoBC[i].y)) <= infoBC[i].C) {
			a_candi[i] = true;
		}
		if ((abs(b_x - infoBC[i].x) + abs(b_y - infoBC[i].y)) <= infoBC[i].C) {
			b_candi[i] = true;
		}
	}
}

void charge() {
	int maxCharge = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			if (a_candi[i] == true || b_candi[j] == true) {
				int result = 0;
				if (a_candi[i] == true && b_candi[j] == true && i == j) {
					result = (infoBC[i].P + infoBC[j].P) / 2;
				}
				else {
					if (a_candi[i] == true) {
						result += infoBC[i].P;
					}
					if (b_candi[j] == true) {
						result += infoBC[j].P;
					}
				}

				if (maxCharge < result) {
					maxCharge = result;
				}
			}
		}
	}
	answer += maxCharge;
}


void move_a(int dir) {
	if (dir == 1) {
		a_y -= 1;
	}
	else if (dir == 2) {
		a_x += 1;
	}
	else if (dir == 3) {
		a_y += 1;
	}
	else if (dir == 4) {
		a_x -= 1;
	}
}
void move_b(int dir) {
	if (dir == 1) {
		b_y -= 1;
	}
	else if (dir == 2) {
		b_x += 1;
	}
	else if (dir == 3) {
		b_y += 1;
	}
	else if (dir == 4) {
		b_x -= 1;
	}
}

void print() {
	cout << "candi_a:  ";
	for (int i = 0; i < 8; i++) {
		cout << a_candi[i] << " ";
	}
	cout << endl;
	cout << "candi_b:  ";
	for (int i = 0; i < 8; i++) {
		cout << b_candi[i] << " ";
	}
	cout << endl;
}
int main() {

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		answer = 0;
		a_x = 1;
		a_y = 1;
		b_x = 10;
		b_y = 10;
		cin >> M >> A;
		for (int i = 0; i < 10; i++)
			fill(map[i], map[i] + 10, 0);
		for (int i = 0; i < M; i++) {
			cin >> comA[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> comB[i];
		}


		for (int i = 0; i < A; i++) {
			int tmpA, tmpB, tmpC, tmpP;
			cin >> tmpA >> tmpB;
			cin >> tmpC;
			cin >> tmpP;
			infoBC[i] = Node(tmpA, tmpB, tmpC, tmpP);
		}
		int i = 0;
		while (i <= M) {
			fill(a_candi, a_candi + A, false);
			fill(b_candi, b_candi + A, false);
			check();
			charge();

			move_a(comA[i]);
			move_b(comB[i]);
			i++;
		}
		cout << "#" << test << " " << answer << endl;



	}
}