#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int N, K;
char baseArr[28];
set<long long> result;
void rotate() {
	char temp = baseArr[N - 1];
	for (int i = N - 1; i > 0; i--)
		baseArr[i] = baseArr[i - 1];
	baseArr[0] = temp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;

	for (int test = 1; test <= T; test++) {

		cin >> N >> K;
		result.clear();
		for (int i = 0; i < N; i++)
			cin >> baseArr[i];

		int unit = N / 4;
		for (int cnt = 0; cnt < N; cnt++) {
			for (int i = 0; i < 4; i++) {
				long long candi = 0;
				int upper = unit - 1;
				for (int j = unit * i; j < unit * i + unit; j++) {
					int num;
					if ('A' <= baseArr[j] && baseArr[j] <= 'F')
						num = baseArr[j] - 'A' + 10;
					else
						num = baseArr[j] - '0';
					int cal = pow(16, upper) * num;
					candi = candi + cal;
					upper--;
				}
				result.insert(candi);
			}
			rotate();
		}
		long long answer = 0;
		int tmpCnt = 1;
		for (auto iter = result.rbegin(); iter != result.rend(); iter++) {
			tmpCnt++;
			if (tmpCnt == K + 1) {
				answer = *iter;
				break;
			}
		}
		cout << "#" << test << " " << answer << endl;


	}

	return 0;
}