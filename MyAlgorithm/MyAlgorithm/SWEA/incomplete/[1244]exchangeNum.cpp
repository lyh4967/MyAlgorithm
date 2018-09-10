#include <iostream>
#include <string>
using namespace std;



string maxNum;
void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

void dfs(string number, int length, int position, int cnt, int maxCnt) {

	if (cnt == maxCnt) {
		if (maxNum<number)
			maxNum = number;
		return;
	}

	if (position == length - 2) {
		if (number[position - 1] == number[position]) {
			swap(number[position], number[position - 1]);

		}
		else {
			swap(number[position], number[length - 1]);
		}
		dfs(number, length, position, cnt + 1, maxCnt);
		return;
	}
	char tempMax = 0;
	for (int i = position; i < length; i++) {
		if (tempMax < number[i]) {
			tempMax = number[i];
		}
	}
	if (number[position] == tempMax) {
		dfs(number, length, position + 1, cnt, maxCnt);
	}
	else {
		for (int i = position + 1; i < length; i++) {
			if (number[i] == tempMax) {
				swap(number[position], number[i]);
				dfs(number, length, position + 1, cnt + 1, maxCnt);
				swap(number[position], number[i]);
			}
		}
	}


}

int main() {

	int testNum;
	cin >> testNum;
	for (int test = 1; test <= testNum; test++) {

		string number;
		int maxCnt;

		cin >> number >> maxCnt;

		int length = number.size();
		maxNum = "";
		dfs(number, length, 0, 0, maxCnt);

		cout << "#" << test << ' ' << maxNum << endl;

	}

	return 0;
}