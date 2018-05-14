#include <iostream>
#include <vector>
#include <stdio.h>
#include <bitset>
#include <cmath>
using namespace std;

int N, M;
int cnt = 0;
int* boxArr;
int* T; //상자출력
int* data;//상자
void process(int q) {
	int result = 0;
	for (int i = q - 1; i >= 0; i--) {

		result = result | boxArr[T[i]];
	}
	if (result == (pow(2, M) - 1))
		cnt++;
}
/*data[]에서 앞에서부터 n개의 숫자 중 r개를 선택해서 조합을 출력하는 함수. q는 출력 시 출력 갯수 지정*/
void Comb(int n, int r, int q) {
	if (r == 0) {
		process(q);
		return;
	}
	else if (n<r) {
		return;
	}
	else {  //loop이 아님
		T[r - 1] = data[n - 1];
		Comb(n - 1, r - 1, q);  //n-1Cr-1: 현재 아이템을 선택한 경우
		Comb(n - 1, r, q);    //n-1Cr: 현재 아이템을 선택하지 않은 경우
	}
}
int main() {

	cin >> N >> M;

	boxArr = new int[N + 1];
	fill(boxArr, boxArr + N + 1, 0);
	data = new int[N];
	T = new int[N];
	for (int i = 0; i < N; i++) {
		data[i] = i;
	}

	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int tmp;
			cin >> tmp;
			boxArr[i] = boxArr[i] | (1 << tmp);
		}
		boxArr[i] = boxArr[i] >> 1;
	}


	for (int i = 1; i <= N; i++) {
		Comb(N, i, i);
	}
	cout << cnt << endl;

}
