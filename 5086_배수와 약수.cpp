#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		if (b % a == 0) {
			cout << "factor" << endl;
		}
		else if (a % b == 0) {
			cout << "multiple" << endl;
		}
		else {
			cout << "neither" << endl;
		}
	}
	return 0;
}