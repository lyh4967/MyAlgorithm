#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int answer = 0;
vector<vector<int>> pkArr;
int colSize;
int rowSize;
map<string, int> canCheck;
bool visited[8];
vector<vector<string>> relation;

void printVi() {
	cout << endl;
	for (int i = 0; i < colSize; i++) {
		cout << visited[i] << " ";
	}
	cout << endl;

}


bool minCheck() {
	int arrSize = pkArr.size();
	for (int i = 0; i < arrSize; i++) {
		int pkSize = pkArr[i].size();
		int cnt = 0;
		for (int j = 0; j < pkSize; j++) {
			int elem = pkArr[i][j];
			if (visited[elem] == true) {
				cnt++;
			}
		}
		if (cnt == pkSize)
			return false;
	}
	return true;

}


bool check() {//pkArr 체크해줘야함
	if (!minCheck()) {//최소성 검사
		return false;
	}

	for (int i = 0; i < rowSize; i++) {
		string temp;
		for (int j = 0; j < colSize; j++) {//유일성 검사
			if (visited[j] == true) {
				temp += relation[i][j];
			}
		}
		if (canCheck[temp] == 1) {
			return false;
		}
		canCheck[temp] = 1;
	}
	return true;
}



void dfs(int maxCnt, int cnt, int index) {

	if (maxCnt == cnt) {
		//printVi();

		if (check()) {
			vector<int>pk;//pk만드는작업
			for (int i = 0; i < colSize; i++) {
				if (visited[i] == true) {
					pk.push_back(i);
				}
			}
			answer++;
			pkArr.push_back(pk);
		}
		canCheck.clear();
		return;
	}
	if (index == colSize) {
		return;
	}
	visited[index] = true;
	dfs(maxCnt, cnt + 1, index + 1);
	visited[index] = false;
	dfs(maxCnt, cnt, index + 1);
}

int main() {
	for (int i = 0; i < 6; i++) {
		vector<string> tmp;
		relation.push_back(tmp);
		for (int j = 0; j < 4; j++) {
			string temp; cin >> temp;
			relation[i].push_back(temp);
		}
	}

	colSize = relation[0].size();
	rowSize = relation.size();


	for (int i = 1; i <= colSize; i++) {

		fill(visited, visited + colSize, false);//visit초기화
		dfs(i, 0, 0);
	}
	cout << answer << endl;




	return 0;
}