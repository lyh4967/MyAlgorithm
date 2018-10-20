#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	return ltrim(rtrim(str, chars), chars);
}
int main() {

	string S = "We test coders. Give us a try?";

	vector<string> result;
	int length = S.size();
	int start = 0;
	for (int i = 0; i < length; i++) {
		if (S[i] == '.' || S[i] == '?' || S[i] == '!') {
			string temp = S.substr(start, i - start);
			start = i + 1;
			result.push_back(temp);
		}
	}
	int answer = 0;
	for (int i = 0; i < result.size(); i++) {
		int cnt = 0;
		string word = result[i];
		trim(word);
		stringstream ss(word);
		while (ss >> word) {
			cnt++;
		}
		if (answer < cnt)
			answer = cnt;
	}

	cout << answer << endl;

	return 0;
}