#include <iostream>
#include <string>
using namespace std;

int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s1; cin >> s1;
		int index1 = 0;
		int index2 = 0;
		int length = s1.size();
		string s2;
		while (index1 < length) {
			if (s1[index1] == ')') {
				index2--;
			}
			else {
				s2 += s1[index1];
				index2++;
			}
			index1++;
			if (index2 == -1)
				break;
		}
		if (index2 != 0 || index2 == -1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}