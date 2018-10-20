#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> A;
	A.push_back(1);
	A.push_back(0);
	A.push_back(0);
	A.push_back(1);
	A.push_back(0);
	A.push_back(0);

	int arr[2];
	fill(arr, arr + 2, 0);
	int N = A.size();
	for (int i = 0; i < N; i++) {
		arr[A[i]]++;
	}
	int answer = min(arr[0], arr[1]);
	cout << answer << endl;



	return 0;
}