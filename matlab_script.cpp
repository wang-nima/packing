#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("data.txt","r",stdin);
	freopen("script.txt","w",stdout);
	int num;
	cin >> num;
	int x, y, length, height;
	for (int i = 0; i < num; i++) {
		cin >> x >> y >> length >> height;
		printf("rectangle('Position',[%d,%d,%d,%d])\n", x, y, length, height);
	}
	return 0;
}
