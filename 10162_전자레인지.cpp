#include <iostream>
using namespace std;

int main() {
	int t;
	int a, b, c;

	cin >> t;

	a = t / 300;
	b = t % 300 / 60;
	c = t % 300 % 60 / 10;

	if (a * 300 + b * 60 + c * 10 == t) {
		cout << a << ' ' << b << ' ' << c << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}