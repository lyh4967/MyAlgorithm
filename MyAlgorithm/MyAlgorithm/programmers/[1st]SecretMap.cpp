#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {

	int n; cin >> n;
	vector<int> arr1;
	vector<int> arr2;
	vector<string> answer;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr1.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		cin >> input;
		arr2.push_back(input);
	}
	int bit = (int)pow(2, n - 1);
	string str;
	for (int i = 0; i < n; i++) {
		int result = arr1[i] | arr2[i];
		str = "";
		for (int j = 0; j < n; j++) {
			if ((result & (bit >> j)) == bit >> j)
				str += "#";
			else
				str += " ";
		}
		answer.push_back(str);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}



	return 0;
}