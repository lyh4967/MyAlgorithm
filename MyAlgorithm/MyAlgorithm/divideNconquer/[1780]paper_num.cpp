#include <iostream>
#include <vector>
using namespace std;

int arr[2188][2188];
vector<int> result;

void slice(int startA, int startB, int endA, int endB){

	if (startA >= endA || startB >= endB){
		result.push_back(arr[startA][startB]);
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
	int mid1A = (endA - startA + 1) / 3 + startA - 1;
	int mid2A = (endA - startA + 1) / 3 * 2 + startA - 1;
	int mid1B = (endB - startB + 1) / 3 + startB - 1;
	int mid2B = (endB - startB + 1) / 3 * 2 + startB - 1;
	if (flag == true){
		result.push_back(arr[startA][startB]);
	}
	else{
		slice(startA, startB, mid1A, mid1B);//arr11
		slice(startA, mid1B + 1, mid1A, mid2B);//arr12
		slice(startA, mid2B + 1, mid1A, endB);//arr13
		slice(mid1A + 1, startB, mid2A, mid1B);//arr21
		slice(mid1A + 1, mid1B + 1, mid2A, mid2B);//arr22
		slice(mid1A + 1, mid2B + 1, mid2A, endB);//arr23
		slice(mid2A + 1, startB, endA, mid1B);//arr31
		slice(mid2A + 1, mid1B + 1, endA, mid2B);//arr32
		slice(mid2A + 1, mid2B + 1, endA, endB);//arr33
	}

}

int main(){
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	slice(1, 1, N, N);
	int cntMi = 0;
	int cntZe = 0;
	int cntPl = 0;
	for (int i = 0; i < (int)result.size(); i++){
		if (result[i] == -1)
			cntMi++;
		else if (result[i] == 0)
			cntZe++;
		else
			cntPl++;
	}
	cout << cntMi << endl << cntZe << endl << cntPl << endl;
}