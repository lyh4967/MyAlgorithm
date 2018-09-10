#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		int n, m;
		cin >> n >> m;

		int problems[100001];
		for (int i = 1; i <= n; i++)
			cin >> problems[i];
		long long cnt = 0;

		for (int query = 0; query < m; query++) {
			int q, v;
			cin >> q >> v;
			if (q == 1) {
				problems[v]++;
			}
			else if (q == 2) {
				problems[v]--;
			}
			else {//q==3
				long long chargedTime = 0;
				if (v <= 500000 / 2) {
					for (int i = 1; i <= n; i++) {
						chargedTime += ceil(problems[i] / double(v));
					}
				}
				else {
					sort(problems + 1, problems + n + 1);
					int start = 1;
					int end = 1;
					int cnt = 1;
					while (end <= n + 1) {
						end = upper_bound(problems + 1, problems + n + 1, v*cnt) - problems;
						int dis = end - start;
						chargedTime += dis * cnt;
						if (end == n + 1)
							break;
						start = end;
						cnt++;
					}
				}
				cnt += chargedTime;
			}
		}
		cout << "#" << test << " " << cnt << endl;
	}

	return 0;
}