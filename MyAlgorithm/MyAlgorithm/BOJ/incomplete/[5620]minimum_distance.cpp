#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}
	double min = pow(arr[0].first - arr[1].first, 2) + pow(arr[0].second - arr[1].second, 2);
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			double distance = pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2);
			if (min>distance)
				min = distance;
		}
	}
	cout << min << endl;

	return 0;

}