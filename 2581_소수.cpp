#include <iostream>
#define endl '\n'
using namespace std;

int n, m, sum;
int minValue = INT32_MAX;

bool checkPrimeNumber(int n);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = n; i <= m; ++i) {
		if (checkPrimeNumber(i)) {
			sum += i;
			if (i < minValue) minValue = i;
		}
	}

	if (minValue == INT32_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << sum << endl;
		cout << minValue << endl;
	}

	return 0;
}

bool checkPrimeNumber(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}