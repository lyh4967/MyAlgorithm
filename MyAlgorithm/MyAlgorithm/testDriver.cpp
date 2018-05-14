#include <iostream>
#include <string>
using namespace std;



int main() {

	string document,word;
	getline(cin,document);
	getline(cin,word);
	int index = 0;
	int cnt = 0;
	while (document.find(word,index) <= 2500) {
		cnt++;
		index = document.find(word, index)+word.size();
	}
	cout << cnt << endl;


	
	return 0;

}