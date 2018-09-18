#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct Node {
	int index;
	int cnt;
};

int main() {
	vector<int> food_times; long long k;

	food_times.push_back(3);
	food_times.push_back(1);
	food_times.push_back(2);
	k = 5;
	int answer = 0;


	deque<Node> deque;

	int size = food_times.size();
	for (int i = 0; i < size; i++) {
		Node node;
		node.index = i; node.cnt = food_times[i];
		deque.push_back(node);
	}

	for (int i = 0; i < k; i++) {
		Node node = deque[0];
		if (node.cnt > 0)
		{
			node.cnt--;
			deque.pop_front();
			if (node.cnt == 0)
				continue;
			deque.push_back(node);
		}
	}

	if (deque.size() == 0)
		answer = -1;
	else
		answer = deque[0].index + 1;


	return 0;
}

