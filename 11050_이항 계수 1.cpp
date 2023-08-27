#include <iostream>
using namespace std;

int n, k;
int fac[11];

int main() {
	cin >> n >> k;

	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i;
	}
	cout << fac[n] / (fac[k] * fac[n - k]);
}