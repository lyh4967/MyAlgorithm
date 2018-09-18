#include <vector>
#include <string>
#include <iostream>
#include <map>
#define D_MAX_ARRAY_SIZE 5
using namespace std;

string* StringSplit(string strTarget, string strTok)
{
	int     nCutPos;
	int     nIndex = 0;
	string* strResult = new string[D_MAX_ARRAY_SIZE];

	while ((nCutPos = strTarget.find_first_of(strTok)) != strTarget.npos)
	{
		if (nCutPos > 0)
		{
			strResult[nIndex++] = strTarget.substr(0, nCutPos);
		}
		strTarget = strTarget.substr(nCutPos + 1);
	}

	if (strTarget.length() > 0)
	{
		strResult[nIndex++] = strTarget.substr(0, nCutPos);
	}

	return strResult;
}


int main() {
	vector<string> record;
	vector<string> answer;
	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");


	map<string, string> users;

	string command;
	int size = record.size();
	for (int i = 0; i < size; i++) {
		command = record[i];
		string* comArr = StringSplit(command, " ");
		if (comArr[0] == "Enter" || comArr[0] == "Change") {
			users[comArr[1]] = comArr[2];
		}
	}
	string result;

	for (int i = 0; i < size; i++) {
		command = record[i];
		string* comArr = StringSplit(command, " ");
		if (comArr[0] == "Enter") {
			result = users[comArr[1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			answer.push_back(result);

		}
		else if (comArr[0] == "Leave") {
			result = users[comArr[1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			answer.push_back(result);
		}
	}

	return 0;
}