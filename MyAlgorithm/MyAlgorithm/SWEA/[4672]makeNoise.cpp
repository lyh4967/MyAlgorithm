#include <iostream>
#include <string>
using namespace std;

int main() {

	int T; cin >> T;
	for (int test = 1; test <= T; test++) {

		string strOri; cin >> strOri;
		int n; cin >> n;
		int arr[100];
		int tmpArr[21]; fill(tmpArr, tmpArr + 21, 0);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		string str;
		str = strOri;
		for (int i = 0; i < n; i++) {
			/*
			cout << "tmpArr: ";
			for (int j = 1; j <= strOri.size(); j++)
			cout << tmpArr[j] << ' ';
			cout << endl;
			cout << "log: " << str << endl;*/
			int index = arr[i] + tmpArr[arr[i]];
			string temp1 = str.substr(0, index);
			string temp2 = str.substr(index);


			temp1 += "-";
			str = temp1 + temp2;
			for (int j = arr[i]; j <= strOri.size(); j++)
				tmpArr[j]++;
		}
		cout << "#" << test << " " << str << endl;

	}


	return 0;
}