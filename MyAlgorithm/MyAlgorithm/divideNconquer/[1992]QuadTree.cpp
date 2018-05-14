#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;


int arr[64][64];

void compress(int startA, int startB, int endA, int endB){

	if (startA >= endA || startB >= endB){
		cout << arr[startA][startB];
		return;
	}
	bool flag = true;
	int tmp = arr[startA][startB];
	for (int i = startA; i <= endA; i++){
		for (int j = startB; j <= endB; j++){
			if (tmp != arr[i][j]){
				flag = false;
			}
		}
	}
	int midA = (startA + endA) / 2;
	int midB = (startB + endB) / 2;
	if (flag == true){
		cout << arr[startA][startB];
	}
	else{
		cout << "(";
		compress(startA, startB, midA, midB);
		compress(startA, midB + 1, midA, endB);
		compress(midA + 1, startB, endA, midB);
		compress(midA + 1, midB + 1, endA, endB);
		cout << ")";
	}

}

int main(){

	int N;
	cin >> N;//변의 길이


	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			int tmp;
			scanf("%1d", &tmp);
			arr[i][j] = tmp;
		}
	}
	compress(0, 0, N - 1, N - 1);


	return 0;
}