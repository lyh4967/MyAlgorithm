#include <iostream>
#include <queue>
using namespace std;

int m, n;
int map[101][101];
bool visited[101][101][5];
int dir1[2] = { 2,3 };
int dir2[2] = { 1,2 };
int dir3[2] = { -1,-2 };
int dir4[2] = { -2,-3 };
int answer = 987654321;
struct Node {
	int a;
	int b;
	int dir;
	int cnt;
};
bool isRanged(int a, int b) {
	return 1 <= a && a <= m && 1 <= b && b <= n;
}
int main() {

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int sa, sb, sd, ea, eb, ed;
	cin >> sa >> sb >> sd >> ea >> eb >> ed;

	Node node;
	node.a = sa; node.b = sb; node.dir = sd; node.cnt = 0;
	queue<Node> que;
	que.push(node);
	while (!que.empty()) {
		node = que.front(); que.pop();
		int a = node.a; int b = node.b; int dir = node.dir; int cnt = node.cnt;
		if (answer < cnt)
			continue;
		if (a == ea && b == eb && dir == ed) {
			if (cnt < answer) {
				answer = cnt;
			}
		}

		if (visited[a][b][dir])
			continue;
		visited[a][b][dir] = true;

		int nextA, nextB;
		for (int i = 1; i <= 3; i++) {
			if (dir == 1) {
				nextA = a; nextB = b + i;
			}
			else if (dir == 2) {
				nextA = a; nextB = b - i;
			}
			else if (dir == 3) {
				nextA = a + i; nextB = b;
			}
			else {//dir==4
				nextA = a - i; nextB = b;
			}
			if (map[nextA][nextB] == 1)//���������� �극��ũ
				break;
			if (isRanged(nextA, nextB) && map[nextA][nextB] == 0 && !visited[nextA][nextB][dir]) {
				node.a = nextA; node.b = nextB; node.dir = dir; node.cnt = cnt + 1;
				que.push(node);
			}
		}
		int nextDir;
		for (int i = 0; i < 2; i++) {
			if (dir == 1)
				nextDir = dir + dir1[i];
			else if (dir == 2)
				nextDir = dir + dir2[i];
			else if (dir == 3)
				nextDir = dir + dir3[i];
			else
				nextDir = dir + dir4[i];
			if (!visited[a][b][nextDir]) {
				node.a = a; node.b = b; node.dir = nextDir; node.cnt = cnt + 1;
				que.push(node);
			}
		}
	}
	cout << answer << endl;

	return 0;
}
/*
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int m, n;
int map[101][101];
bool visited[101][101];
int dir1[4] = { 1,4,2,3 };
int dir2[4] = { 2,3,1,4 };
int dir3[4] = { 3,2,4,1 };
int dir4[4] = { 4,2,3,1 };
struct Node {
int a;
int b;
int dir;
long long cnt;
};

bool isRanged(int a, int b) {
return 1 <= a && a <= m && 1 <= b && b <= n;
}

long long answer = 9876543219999999;

int main() {
ios_base::sync_with_stdio(false); cin.tie();
cin >> m >> n;
for (int i = 1; i <= m; i++) {
for (int j = 1; j <= n; j++) {
cin >> map[i][j];
visited[i][j] = false;
}
}
int sa, sb, sd, ea, eb, ed;
cin >> sa >> sb >> sd >> ea >> eb >> ed;
Node node;
queue<Node> que;

node.a = sa; node.b = sb; node.dir = sd; node.cnt = 0;
que.push(node);
while (!que.empty()) {
node = que.front(); que.pop();
int a = node.a; int b = node.b; int dir = node.dir; long long cnt = node.cnt;
if (answer < cnt)
continue;
if (a == ea && b == eb) {
if (ed == 2) {
if (dir == 3 || dir == 4)
cnt += 1;
else if (dir == 1)
cnt += 2;
}
else if (ed == 3) {
if (dir == 2 || dir == 1)
cnt += 1;
else if (dir == 4)
cnt += 2;
}
else if (ed == 4) {
if (dir == 2 || dir == 1)
cnt += 1;
else if (dir == 3)
cnt += 2;
}
else {//ed==1
if (dir == 4 || dir == 3)
cnt += 1;
else if (dir == 2)
cnt += 2;
}
if (answer > cnt)
answer = cnt;
continue;
}
if (visited[a][b])
continue;
//cout << "log: " << a << "," << b << "," << dir << "," << cnt << endl;

visited[a][b] = true;
int nextA, nextB;
int tempDir;
for (int j = 0; j < 4; j++) {
if (dir == 1)
tempDir = dir1[j];
else if (dir == 2)
tempDir = dir2[j];
else if (dir == 3)
tempDir = dir3[j];
else
tempDir = dir4[j];
for (int i = 1; i <= 3; i++) {
if (tempDir == 1) {
nextA = a; nextB = b + i;
}
else if (tempDir == 2) {
nextA = a; nextB = b - i;
}
else if (tempDir == 3) {
nextA = a + i; nextB = b;
}
else {//tempDir==4
nextA = a - i; nextB = b;
}
if (map[nextA][nextB] == 1)//���������� �극��ũ
break;
if (isRanged(nextA, nextB) && !visited[nextA][nextB] && map[nextA][nextB] == 0) {
if (j == 1 || j == 3) {
node.a = nextA; node.b = nextB; node.dir = tempDir; node.cnt = cnt + 2;
}
else if (j == 2) {
node.a = nextA; node.b = nextB; node.dir = tempDir; node.cnt = cnt + 3;
}
else {//j==0
node.a = nextA; node.b = nextB; node.dir = tempDir; node.cnt = cnt + 1;
}
que.push(node);
}
}
}
}
cout << answer << endl;
return 0;
}
*/