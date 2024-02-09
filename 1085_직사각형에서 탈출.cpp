#include <iostream>
#include <algorithm>
using namespace std;

int x, y, w, h;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> x >> y >> w >> h;
	cout << min({ x, w - x, h - y, y }) << endl;
	return 0;
}