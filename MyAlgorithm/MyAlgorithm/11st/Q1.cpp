#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> A;
	A.push_back(1);
	A.push_back(4);
	A.push_back(-1);
	A.push_back(3);
	A.push_back(2);


	int index = 0;
	int answer = 0;
	while (true) {
		if (A[index] >= 0) {
			index = A[index];
			answer++;
		}
		else {//-1
			answer++;
			break;
		}
	}
	cout << answer << endl;

	return 0;
}