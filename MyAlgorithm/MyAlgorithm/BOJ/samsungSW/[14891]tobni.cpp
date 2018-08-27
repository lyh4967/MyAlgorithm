#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

int tobniArr[5][9];
int checkArr[5];

bool IsBoundry(int num){
	return (1 <= num&&num <= 4);
}

void rotate(int tobniNum, int dire){
	checkArr[tobniNum] = true;
	if (IsBoundry(tobniNum + 1) && (checkArr[tobniNum + 1] == false) && (tobniArr[tobniNum][3] != tobniArr[tobniNum + 1][7])){
		rotate(tobniNum + 1, dire*-1);
	}
	if (IsBoundry(tobniNum - 1) && (checkArr[tobniNum - 1] == false) && (tobniArr[tobniNum][7] != tobniArr[tobniNum - 1][3])){
		rotate(tobniNum - 1, dire*-1);
	}
	int copy[9];
	if (dire == 1){
		int tmp;
		tmp = tobniArr[tobniNum][8];
		for (int i = 1; i <= 7; i++)
			copy[i] = tobniArr[tobniNum][i];
		tobniArr[tobniNum][1] = tmp;
		for (int i = 1; i <= 7; i++)
			tobniArr[tobniNum][i + 1] = copy[i];
	}
	else{
		int tmp;
		tmp = tobniArr[tobniNum][1];
		for (int i = 1; i <= 7; i++)
			copy[i] = tobniArr[tobniNum][i + 1];
		tobniArr[tobniNum][8] = tmp;
		for (int i = 1; i <= 7; i++)
			tobniArr[tobniNum][i] = copy[i];
	}
}

int main(){
	for (int i = 1; i <= 4; i++){
		for (int j = 1; j <= 8; j++){
			int tmp;
			scanf("%1d", &tmp);
			tobniArr[i][j] = tmp;
		}
	}
	int rotateNum, tobniNum, direction;
	cin >> rotateNum;
	for (int i = 0; i < rotateNum; i++){
		fill(checkArr, checkArr + 5, false);
		cin >> tobniNum >> direction;
		rotate(tobniNum, direction);
	}


	int sum = 0;
	if (tobniArr[1][1] == 1)
		sum += 1;
	if (tobniArr[2][1] == 1)
		sum += 2;
	if (tobniArr[3][1] == 1)
		sum += 4;
	if (tobniArr[4][1] == 1)
		sum += 8;
	cout << sum << endl;
}