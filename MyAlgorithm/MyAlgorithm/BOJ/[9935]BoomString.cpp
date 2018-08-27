#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	string s1, s2;
	cin >> s1 >> s2;
	stack<char> result;
	stack<char>tmpStack;
	int length1 = s1.size();
	int length2 = s2.size();
	char lastAlpha = s2[s2.size() - 1];
	for (int i = 0; i < length1; i++) {
		result.push(s1[i]);
		if (s1[i] == lastAlpha && i >= length2 - 1) {
			int j = length2 - 1;
			while (j >= 0) {
				if (s2[j] == result.top()) {
					tmpStack.push(result.top());
					result.pop();
					j--;
				}
				else {
					while (!tmpStack.empty()) {
						result.push(tmpStack.top());
						tmpStack.pop();
					}
					break;
				}
			}
			while (!tmpStack.empty())
				tmpStack.pop();
		}
	}
	string answer;
	stack<char> reverse;
	while (!result.empty()) {
		reverse.push(result.top());
		result.pop();
	}
	while (!reverse.empty()) {
		answer += reverse.top();
		reverse.pop();
	}
	if (answer.size() == 0)
		cout << "FRULA" << endl;
	else
		cout << answer << endl;

	return 0;
}