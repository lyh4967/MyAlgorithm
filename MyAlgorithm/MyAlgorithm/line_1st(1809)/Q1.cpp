#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {

	string line;
	getline(cin, line);
	stringstream ss(line);
	int money = 20000;
	bool flag = false;
	for (int distance; !(ss >> distance).fail(); ) {
		//int sum = 0;
		if (4 <= distance && distance <= 178) {
			if (distance <= 40) {
				money -= 720;
			}
			else {
				money -= 720;
				//sum += 720;
				money -= (((distance - 40) / 8) * 80);
				//sum += ((distance - 40) / 8) * 80;
				if (distance % 8 != 0)
					money -= 80;
			}
			if (money <= 0) {
				cout << 0 << endl;
				flag = true;
				break;
			}
		}
		else {
			cout << money << endl;
			flag = true;
			break;
		}
		//cout <<"log: "<< money <<","<<sum<< endl;

	}
	if (!flag)
		cout << money << endl;
	return 0;
}