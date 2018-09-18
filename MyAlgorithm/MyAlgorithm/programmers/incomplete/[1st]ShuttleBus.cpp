#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Time {
public:
	int hh; int mm;
	Time() {}
	Time(string a) {
		string strHH = a.substr(0, 2);
		string strMM = a.substr(3);
		hh = stoi(strHH);
		mm = stoi(strMM);
	}

	bool operator <= (Time a) {
		if (hh == a.hh) {
			return mm <= a.mm;
		}
		else
			return hh < a.hh;
	}

	void operator + (int a) {
		mm += a;
		if (mm >= 60) {
			hh += mm / 60;
			mm = mm % 60;
		}
	}
};

bool comp(string a, string b) {
	string strHH = a.substr(0, 2);
	string strMM = a.substr(3);
	int a_hh = stoi(strHH);
	int a_mm = stoi(strMM);
	strHH = b.substr(0, 2);
	strMM = b.substr(3);
	int b_hh = stoi(strHH);
	int b_mm = stoi(strMM);
	if (a_hh == b_hh) {
		return a_mm < b_mm;
	}
	else
		return a_hh < b_hh;
}

int main() {
	int n, t, m;
	string answer = "";
	int num;
	vector<string> timetable;
	cin >> n >> t >> m;
	cin >> num;

	int length = timetable.size();
	for (int i = 0; i < num; i++) {
		string temp;
		cin >> temp; timetable.push_back(temp);
	}

	sort(timetable.begin(), timetable.end(), comp);

	int i = 0;
	Time curBus("09:00"); Time nextBus("09:10");
	int busCnt = 1;
	int cnt = 0;
	while (i < length && busCnt <= n) {
		string curStr = timetable[i];
		Time curCrew(curStr);
		if (i)
			if (curCrew <= curBus) {
				cnt++;
				if (cnt == m) {
					cnt = 0;
					curBus + t;
					busCnt++;
				}
				i++;
				continue;
			}
			else {
				cnt = 0;
				curBus + t;
				busCnt++;
			}
	}

	if (curBus.hh == 9 && curBus.mm == 0)
		answer = "09:00";
	else {

	}

	return 0;
}