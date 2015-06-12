#include <iostream>
#include <algorithm>
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

int start_point_x = 0;
int start_point_y = 0;

void printSolution(int current_max, int area_left_x, int area_left_y, int x, int y) {

	if (current_max == 0) return;
	if (area_left_x < area_left_y) swap(area_left_x, area_left_y);
	if (x < y) swap(x, y);

	if (area_left_x / x + pack(area_left_x, area_left_y - y, x, y) == current_max) {

		for (int i = 0; i < area_left_x / x; i++) {
			cout << start_point_x + i * x << " " << start_point_y << x << " " << y << endl;
		}

		start_point_y += y;

		printSolution(current_max - area_left_x / x, area_left_x, area_left_y - y, x ,y);

	} else if (x <= area_left_y && area_left_x / y + pack(area_left_x, area_left_y - x, x, y) == current_max) {

		for (int i = 0; i < area_left_x / y; i++) {
			cout << start_point_x + i * y << " " << start_point_y << y << " " << x << endl;
		}

		start_point_y += x;

		printSolution(current_max - area_left_x / y, area_left_x, area_left_y - x, x, y);


	} else if (area_left_y / y + pack(area_left_x - x, area_left_y, x, y) == current_max) {			// we need to pay attentation when area_left_x become smaller than area_left_y

	} else {

	}

}

int main() {
	int area_x, area_y, x, y;
	cin >> area_x >> area_y >> x >> y;
	cout << pack(area_x, area_y, x ,y) << endl;
	return 0;
}
