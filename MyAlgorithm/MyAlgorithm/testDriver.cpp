#include <iostream>
#include <string>
using namespace std;
bool isRanged(int a, int b) {
	return 1 <= a && a <= 8 && 1 <= b && b <= 8;
}
int main() {

	string stone, king;
	cin >> king >> stone;
	int n; cin >> n;
	int s_b = stone[0] - 64;
	int s_a = stone[1]-'0';
	int k_b = king[0] - 64;
	int k_a = king[1]-'0';
	for (int i = 0; i < n; i++) {
		string command; cin >> command;
		int next_s_a=s_a; int next_s_b=s_b;
		int next_k_a=k_a; int next_k_b=k_b;

		if (command == "R") {
			next_k_a = k_a;
			next_k_b = k_b + 1;
			if (next_k_a == s_a && next_k_b == s_b) {
				next_s_a = s_a;
				next_s_b = s_b + 1;
			}			
		}
		else if (command == "L") {
			next_k_a = k_a;
			next_k_b = k_b - 1;
			if (next_k_a == s_a && next_k_b == s_b) {
				next_s_a = s_a;
				next_s_b = s_b - 1;
			}
		}
		else if (command == "B") {
			next_k_a = k_a - 1;
			next_k_b = k_b;
			if (next_k_a == s_a && next_k_b == s_b) {
				next_s_a = s_a - 1;
				next_s_b = s_b;
			}
		}
		else if (command == "T") {
			next_k_a = k_a + 1;
			next_k_b = k_b;
			if (next_k_a == s_a && next_k_b == s_b) {
				next_s_a = s_a + 1;
				next_s_b = s_b;
			}
		}
		else if (command == "RT") {
			next_k_a = k_a + 1;
			next_k_b = k_b + 1;
			if (next_k_a == s_a && next_k_b == s_b) {
				next_s_a = s_a + 1;
				next_s_b = s_b + 1;
			}
		}
		else if (command == "LT") {
			next_k_a = k_a + 1;
			next_k_b = k_b - 1;
			if (next_k_a == s_a && next_k_b == s_b) {
				next_s_a = s_a + 1;
				next_s_b = s_b - 1;
			}
		}
		else if (command == "RB") {
			next_k_a = k_a - 1;
			next_k_b = k_b + 1;
			if (next_k_a == s_a && next_k_b == s_b) {
				next_s_a = s_a - 1;
				next_s_b = s_b + 1;
			}
		}
		else if (command == "LB") {
			next_k_a = k_a - 1;
			next_k_b = k_b - 1;
			if (next_k_a == s_a && next_k_b == s_b) {
				next_s_a = s_a - 1;
				next_s_b = s_b - 1;
			}
		}
		if (isRanged(next_s_a, next_s_b) && isRanged(next_k_a, next_k_b)) {
			s_a = next_s_a;
			s_b = next_s_b;
			k_a = next_k_a;
			k_b = next_k_b;
		}
	}
	cout << (char)(k_b + 64) << (char)(k_a + '0') << endl;
	cout << (char)(s_b + 64) << (char)(s_a + '0') << endl;

	return 0;
}