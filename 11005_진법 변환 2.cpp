#include <iostream>
#define endl '\n'
#define maxBN 1000000000
using namespace std;

const char digit[36] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

long long int customPow(long long int a, long long int b) {
	long long int res = 1;
	for (long long int i = 0; i < b; ++i) {
		res *= a;
	}
	return res;
}

int getMaxDigit(long long int b) {
	long long int lb = b;
	int cnt = 0;
	while (customPow(lb, cnt + 1) <= maxBN) {
		++cnt;
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, b;
	bool output = false;
	int curr;

	cin >> n >> b;

	curr = n;
	for (int i = getMaxDigit(b); i >= 0; --i) {
		int powVar = customPow(b, i);
		if (curr / powVar == 0) {
			if (output) {
				cout << digit[curr / powVar];
			}
		}
		else {
			cout << digit[curr / powVar];
			output = true;
		}
		curr = curr % powVar;
	}
	cout << endl;

	return 0;
}