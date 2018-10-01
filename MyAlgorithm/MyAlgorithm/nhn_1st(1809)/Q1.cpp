#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
using namespace std;


int main() {
	int C, P, N;
	cin >> C >> P;
	deque<int> dq;
	deque<int> answer;

	for (int i = 1; i <= C; i++) {
		answer.push_back(i);
	}


	for (int tmpP = 0; tmpP < P; tmpP++) {
		cin >> N;
		while (!answer.empty()) {
			dq.push_back(answer.front());
			answer.pop_front();
		}
		deque<int> tmpDQ;
		int cardNum = C;
		bool flag = true;

		while (flag) {
			if (cardNum > 2 * N) {
				for (int i = 0; i < N; i++) {
					answer.push_front(dq.back());
					dq.pop_back();
				}
				for (int i = 0; i < N; i++) {
					tmpDQ.push_back(dq.front());
					dq.pop_front();
				}
				while (!tmpDQ.empty()) {
					answer.push_front(tmpDQ.back());
					tmpDQ.pop_back();
				}
				cardNum = cardNum - 2 * N;
			}
			else {
				while (!dq.empty()) {
					int tmp = dq.back();
					answer.push_front(tmp);
					dq.pop_back();
				}
				flag = false;//³¡
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << answer.front() << endl;
		answer.pop_front();
	}

	return 0;
}