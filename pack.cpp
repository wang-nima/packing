#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int pack(int area_left_x, int area_left_y, int x, int y) {
	if (area_left_x < area_left_y) swap(area_left_x, area_left_y);
	if (x < y) swap(x, y);
	if (x > area_left_x || y > area_left_y)	return 0;
	int a = area_left_x / x + pack(area_left_x, area_left_y - y, x, y);
	int b = -1;
	if (x <= area_left_y) {
		b = area_left_x / y + pack(area_left_x, area_left_y - x, x, y);
	}
	int c = area_left_y / y + pack(area_left_x - x, area_left_y, x, y);
	int d = -1;
	if (x <= area_left_y) {
		d = area_left_y / x + pack(area_left_x - y, area_left_y, x, y);
	}
	return max(max(a, b), max(c, d));
}


int start_point_x;
int start_point_y;

vector<int> v;

void turn() {					// the size of v is always the multiple of 4
	for (int i = 0; i < v.size(); i++) {
		if ((i & 1) == 0) {
			swap(v[i], v[i+1]);
		}
	}
}

void printSolution(int current_max, int area_left_x, int area_left_y, int x, int y) {

	if (current_max == 0) return;
	if (area_left_x < area_left_y) swap(area_left_x, area_left_y);
	if (x < y) swap(x, y);

	if (area_left_x / x + pack(area_left_x, area_left_y - y, x, y) == current_max) {

		for (int i = 0; i < area_left_x / x; i++) {
			v.push_back(start_point_x + i * x);
			v.push_back(start_point_y);
			v.push_back(x);
			v.push_back(y);
		}

		start_point_y += y;

		printSolution(current_max - area_left_x / x, area_left_x, area_left_y - y, x ,y);

	} else if (x <= area_left_y && area_left_x / y + pack(area_left_x, area_left_y - x, x, y) == current_max) {

		for (int i = 0; i < area_left_x / y; i++) {
			v.push_back(start_point_x + i * y);
			v.push_back(start_point_y);
			v.push_back(y);
			v.push_back(x);
		}

		start_point_y += x;

		printSolution(current_max - area_left_x / y, area_left_x, area_left_y - x, x, y);

	} else if (area_left_y / y + pack(area_left_x - x, area_left_y, x, y) == current_max) {			// we need to pay attentation when area_left_x become smaller than area_left_y
		for (int i = 0; i < area_left_y / y; i++) {
			v.push_back(start_point_x);
			v.push_back(start_point_y + i * y);
			v.push_back(x);
			v.push_back(y);
		}
		
		start_point_x += x;
		
		if (area_left_x - x < area_left_y) {
			turn();
		}

		printSolution(current_max - area_left_y / y, area_left_x - x, area_left_y, x, y);

	} else {
		for (int i = 0; i < area_left_y / x; i++) {
			v.push_back(start_point_x);
			v.push_back(start_point_y + i * x);
			v.push_back(y);
			v.push_back(x);
		}

		start_point_x += y;

		if (area_left_x - y < area_left_y) {
			turn();
		}

		printSolution(current_max - area_left_y / x, area_left_x - y, area_left_y, x , y);
	}
}

int main() {
	start_point_x = 0;
	start_point_y = 0;
	int area_x, area_y, x, y;
	cin >> area_x >> area_y >> x >> y;
	int score = pack(area_x, area_y, x ,y);
	freopen("data.txt", "w", stdout);
	cout << score << endl;
	printSolution(score, area_x, area_y, x ,y);
	if (start_point_x < start_point_y) {
		turn();
	}
	//cout << "Solution:" << endl;
	for (int i = 0; i < v. size(); i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
