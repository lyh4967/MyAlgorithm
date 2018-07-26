#include <iostream>
#include <string>
#include <queue>
using namespace std;
string s1, s2, s3;
int length, length1, length2;
int dp[201][201];


int dfs(int index,int index_s1,int index_s2) {

	if (index == length)
		return 1;

	if (dp[index_s1][index_s2] != -1) {
		return dp[index_s1][index_s2];
	}
	
	dp[index_s1][index_s2] = 0;

	if (s3[index] == s1[index_s1] && index_s1<length1) 
		dp[index_s1][index_s2] |= dfs(index + 1, index_s1 + 1, index_s2);
	
	if (s3[index] == s2[index_s2] && index_s2<length2) 
		dp[index_s1][index_s2] |= dfs(index + 1, index_s1, index_s2 + 1);

	return dp[index_s1][index_s2];
}

void print() {
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2 >> s3;
		length = s3.size();
		length1 = s1.size();
		length2 = s2.size();
		for (int i = 0; i < 201; i++)
			fill(dp[i], dp[i] + 201, -1 );
		if (dfs(0, 0, 0)>0)
			cout << "Data set " << i << ": yes" << endl;
		else
			cout << "Data set " << i << ": no" << endl;
		/*
		cout << dfs(0, 0, 0) << endl;
		print();
		*/
	}

	return 0;
}
