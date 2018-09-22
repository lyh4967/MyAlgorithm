#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int map[201][201];//0: 빈칸, 1:집, 2:공장



int main() {

	int N;//공장수
	int M;//집의 수
	int answer = 0;
	cin >> N >> M;
	vector<vector<int>> house;
	for (int i = 0; i < M; i++) {
		vector<int> tmp;
		int tmpX, tmpY;
		cin >> tmpX >> tmpY;
		tmp.push_back(tmpX); tmp.push_back(tmpY);
		house.push_back(tmp);
	}

	int h_size = house.size();

	for (int i = 0; i < 201; i++) {
		fill(map[i], map[i] + 201, 0);
	}
	vector<vector<int>> houses;//진짜!!
	vector<vector<int>> factories;
	for (int i = 0; i < h_size; i++) {//집 건설
		vector<int> tmp;
		tmp.push_back(house[i][0] + 100);
		tmp.push_back(house[i][1] + 100);
		map[house[i][1] + 100][house[i][0] + 100] = 1;
		houses.push_back(tmp);
	}

	for (int tmpC = 0; tmpC < N; tmpC++) {//공장건설
		int maxDis = 0;
		int i_x, i_y;
		vector<int> factory;
		for (int i = 0; i < 201; i++) {
			for (int j = 0; j < 201; j++) {
				if (map[i][j] != 0)
					continue;
				int dis = 0;

				for (int k = 0; k < h_size; k++) {//모든 집과 거리 계산
					dis += ((int)pow(houses[k][0] - j, 2) + (int)pow(houses[k][1] - i, 2));
				}
				if (maxDis < dis) {
					maxDis = dis;
					i_x = j; i_y = i;
				}

			}
		}
		map[i_y][i_x] = 2;
		factory.push_back(i_x); factory.push_back(i_y);
		factories.push_back(factory);
	}

	/*cout << "houses: ";
	for (int i = 0; i < houses.size(); i++) {
	cout <<"("<< houses[i][0] << "," << houses[i][1]<<")" << " ";
	}
	cout << endl;
	cout << "factories: ";
	for (int i = 0; i < factories.size(); i++) {
	cout << "(" << factories[i][0] << "," << factories[i][1] << ")" << " ";
	}
	cout << endl;*/

	answer = 987654321;
	int f_size = factories.size();
	for (int i = 0; i < f_size; i++) {
		for (int j = 0; j < h_size; j++) {
			int dis = ((int)pow(factories[i][0] - houses[j][0], 2) + (int)pow(factories[i][1] - houses[j][1], 2));
			if (answer > dis) {
				answer = dis;
			}
		}
	}
	if (answer == 987654321) {
		answer = -1;
	}


	cout << answer << endl;


	return 0;
}