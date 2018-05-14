#include<iostream>
#include <vector>
using namespace std;
int Answer;

int comapreMsg(vector<pair<int, int>> g1, vector<pair<int, int>> g2, int year){
	int arriYear = 0;
	int minArriYear = -1;
	for (int i = 0; i < (int)g1.size(); i++){
		for (int j = 0; j < (int)g2.size(); j++){
			arriYear = (i + 1) + abs(g1[i].first - g2[j].first) + abs(g1[i].second - g2[j].second);

			if (minArriYear == -1){
				minArriYear = arriYear;
			}
			if (arriYear<j - i){
				continue;
			}

			if (minArriYear>arriYear){//일반적인경우
				minArriYear = arriYear;
			}
		}
	}
	if (minArriYear > year){
		minArriYear = -1;
	}
	return minArriYear;
}

int main(void)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		int scheduleNum;
		cin >> scheduleNum;
		vector<pair<int, int>> G1;
		vector<pair<int, int>> G2;
		int g1X, g1Y, g2X, g2Y;
		for (int i = 1; i <= scheduleNum; i++){
			cin >> g1X >> g1Y >> g2X >> g2Y;
			G1.push_back(make_pair(g1X, g1Y));
			G2.push_back(make_pair(g2X, g2Y));
		}
		Answer = comapreMsg(G1, G2, scheduleNum);
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		cout << "Case#" << test_case + 1 << endl;
		cout << Answer << endl;

	}

	return 0;//Your program should return 0 on normal termination.
}