#include <iostream>
using namespace std;

int C = 0;
class Node {
public:
	Node() {}
	Node(int _item) :item(_item) {}

	int item;
	Node* left;
	Node* right;

};

void insert(int x, Node* n) {
	if (n->item == NULL) {
		n->item = x;
	}
	else if (x < n->item) {
		C++;
		if (n->left == NULL) {
			Node* temp = new Node;
			temp->item = x;
			n->left = temp;
		}
		else
			insert(x, n->left);
	}
	else {
		C++;
		if (n->right == NULL) {
			Node* temp = new Node;
			temp->item = x;
			n->right = temp;
		}
		else
			insert(x, n->right);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	Node* root = new Node;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		insert(num, root);
		cout << C << endl;
	}

	return 0;
}