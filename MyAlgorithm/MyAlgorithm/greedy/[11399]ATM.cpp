#include <iostream>
#include<algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;

	int* arrP = new int[N];
	int* arrSum = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arrP[i];

	sort(arrP, arrP + N);
	arrSum[0] = arrP[0];
	int result = arrSum[0];
	for (int i = 1; i < N; i++) {
		arrSum[i] = arrP[i] + arrSum[i - 1];
		result += arrSum[i];
	}
	cout << result << endl;
	return 0;
}