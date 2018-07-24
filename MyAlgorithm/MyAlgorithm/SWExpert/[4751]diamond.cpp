#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int test = 0; test < n; test++) {
		string str;
		cin >> str;
		int length = str.size();

		for (int i = 0; i < length; i++) {
			cout << "..#."; if (i == length - 1)cout << ".";
		}
		cout << endl;
		for (int i = 0; i < length * 2; i++) {
			cout << ".#"; if (i == length * 2 - 1)cout << ".";
		}
		cout << endl;
		for (int i = 0; i < length; i++) {
			cout << "#." << str[i] << "."; if (i == length - 1)cout << "#";
		}
		cout << endl;
		for (int i = 0; i < length * 2; i++) {
			cout << ".#"; if (i == length * 2 - 1)cout << ".";
		}
		cout << endl;
		for (int i = 0; i < length; i++) {
			cout << "..#."; if (i == length - 1)cout << ".";
		}
		cout << endl;
	}
	return 0;

}