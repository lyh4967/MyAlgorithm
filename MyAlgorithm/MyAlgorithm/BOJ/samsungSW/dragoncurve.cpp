#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool map[101][101];
struct Pair {
	int x;
	int y;
	Pair() {}
	Pair(int _x, int _y) :x(_x), y(_y) {}
};

void curve(int&x, int&y, int pivotX, int pivotY) {
	//원점이동
	int zeroX = x - pivotX;
	int zeroY = y - pivotY;
	//cout << "curve: " << zeroX << "," << zeroY << endl;

	//90도 회전
	int temp = zeroX;
	zeroX = -zeroY;
	zeroY = temp;

	//복귀
	x = zeroX + pivotX;
	y = zeroY + pivotY;
}
int main() {

	int n;
	cin >> n;
	for (int test = 0; test < n; test++) {
		vector<Pair> vec;
		stack<Pair>sta;
		int startX, startY, dir, depth;
		cin >> startX >> startY >> dir >> depth;

		int pivotX = startX;
		int	pivotY = startY;

		if (dir == 0) pivotX += 1; //첫 피벗을 잡는다.
		else if (dir == 1) pivotY -= 1;
		else if (dir == 2) pivotX -= 1;
		else pivotY += 1;//dir==3

		map[startY][startX] = true;
		map[pivotY][pivotX] = true;

		Pair node(startX, startY);
		vec.push_back(node);
		sta.push(node);//피벗은 빼고 스택에넣음

		node.x = pivotX; node.y = pivotY;
		vec.push_back(node);

		for (int i = 0; i < depth; i++) {
			while (!sta.empty()) {
				node = sta.top(); sta.pop();
				int x = node.x; int y = node.y;/*
											   cout << "curlog: " << x << "," << y << endl;
											   cout << "plog: " << pivotX << "," << pivotY << endl;*/
				curve(x, y, pivotX, pivotY);
				map[y][x] = true;
				node.x = x; node.y = y;
				vec.push_back(node);
			}
			for (int j = 0; j < vec.size() - 1; j++) {
				node.x = vec[j].x; node.y = vec[j].y;
				sta.push(node);
			}
			pivotX = vec[vec.size() - 1].x;
			pivotY = vec[vec.size() - 1].y;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}