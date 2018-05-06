#include <iostream>
#include <algorithm>
using namespace std;

struct Point{
	int x;
	int y;
};

Point* arrPoint;

bool compareX(Point& a, Point& b){
	return a.x < b.x;
}

bool checkEquation(int start, int end){
	for (int i = start; i < end - 1; i++){
		for (int j = i + 1; j < end; j++){

		}
	}
}

bool checkPoint(int start, int end){


}

int main(){

	int n, p;
	cin >> n;
	cin >> p;
	arrPoint = new Point[n];
	for (int i = 0; i < n; i++)
		cin >> arrPoint[i].x >> arrPoint[i].y;

	sort(arrPoint, arrPoint + n, compareX);



}