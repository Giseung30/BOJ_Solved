#include <iostream>
using namespace std;

int main() {
	int n;
	int cnt = 1;
	int var = 1;

	cin >> n;

	if (n != 1) {
		for (int i = 0; ; ++i) {
			if (var - i * 6 + 1 <= n && n <= var) {
				break;
			}
			++cnt;
			var += (i + 1) * 6;
		}
	}

	cout << cnt << endl;
	return 0;
}