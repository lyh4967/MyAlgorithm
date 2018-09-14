#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {


	int answer = 0;
	string str1, str2;
	cin >> str1 >> str2;


	vector<string> str1Arr;
	vector<string> str2Arr;
	int length1 = str1.size();
	int length2 = str2.size();

	for (int i = 0; i < length1 - 1; i++) {
		if ((('a' <= str1[i] && str1[i] <= 'z') || ('A' <= str1[i] && str1[i] <= 'Z')) && (('a' <= str1[i + 1] && str1[i + 1] <= 'z') || ('A' <= str1[i + 1] && str1[i + 1] <= 'Z'))) {
			string temp;
			if ('a' <= str1[i] && str1[i] <= 'z')
				temp += (str1[i] - 32);
			else
				temp += (str1[i]);

			if ('a' <= str1[i + 1] && str1[i + 1] <= 'z')
				temp += (str1[i + 1] - 32);
			else
				temp += (str1[i + 1]);
			str1Arr.push_back(temp);
		}
		else
			continue;
	}

	for (int i = 0; i < length2 - 1; i++) {
		if ((('a' <= str2[i] && str2[i] <= 'z') || ('A' <= str2[i] && str2[i] <= 'Z')) && (('a' <= str2[i + 1] && str2[i + 1] <= 'z') || ('A' <= str2[i + 1] && str2[i + 1] <= 'Z'))) {
			string temp;
			if ('a' <= str2[i] && str2[i] <= 'z')
				temp += (str2[i] - 32);
			else
				temp += (str2[i]);

			if ('a' <= str2[i + 1] && str2[i + 1] <= 'z')
				temp += (str2[i + 1] - 32);
			else
				temp += (str2[i + 1]);
			str2Arr.push_back(temp);
		}
		else
			continue;
	}


	map<string, int> str1Map;
	map<string, int> str2Map;

	map<string, int>::iterator ite;

	int size1 = str1Arr.size();
	int size2 = str2Arr.size();

	/*for (int i = 0; i < size1; i++) {
	cout << str1Arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size2; i++) {
	cout << str2Arr[i] << " ";
	}
	cout << endl;*/


	for (int i = 0; i < size1; i++) {//¸Ê1 ¸¸µë
		str1Map[str1Arr[i]] += 1;
	}

	for (int i = 0; i < size2; i++) {//¸Ê2 ¸¸µë
		str2Map[str2Arr[i]] += 1;
	}



	map<string, int> hap;
	for (auto ite = str1Map.begin(); ite != str1Map.end(); ite++)
		hap[ite->first] = ite->second;
	for (auto ite = str2Map.begin(); ite != str2Map.end(); ite++) {
		if (hap[ite->first] != 0) {
			hap[ite->first] = max(hap[ite->first], ite->second);
		}
		else
			hap[ite->first] = ite->second;
	}

	map<string, int> kyo;

	for (auto ite = hap.begin(); ite != hap.end(); ite++) {
		if (str1Map[ite->first] != 0 && str2Map[ite->first] != 0) {
			kyo[ite->first] = min(str1Map[ite->first], str2Map[ite->first]);
		}
	}
	/*cout << "kyo: ";
	for (auto ite = kyo.begin(); ite != kyo.end(); ite++)
	cout << ite->first << "," << ite->second << " ";
	cout << endl;*/

	int nume = 0;
	for (auto ite = kyo.begin(); ite != kyo.end(); ite++)
		nume += ite->second;

	int deci = 0;
	for (auto ite = hap.begin(); ite != hap.end(); ite++)
		deci += ite->second;

	float result;
	if (nume == 0 && deci == 0) {
		result = 1;
	}
	else {
		result = (float)nume / deci;
	}
	/*cout << "log: " << nume << "," << deci << endl;
	cout << result << endl;*/
	answer = (int)(result * 65536);
	cout << answer << endl;
	return 0;
}