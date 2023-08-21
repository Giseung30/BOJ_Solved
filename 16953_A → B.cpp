#include <iostream>
#include <string>
using namespace std;

int minCnt = INT32_MAX;
long long a, b;

long long addOne(long long n) {
	string str = to_string(n);
	str += '1';
	return stoll(str);
}

void recursion(long long n, int cnt) {
	if (n == b && minCnt > cnt) {
		minCnt = cnt;
		return;
	}
	else if (n > b) {
		return;
	}

	recursion(n * 2, cnt + 1);
	recursion(addOne(n), cnt + 1);
}

int main() {
	cin >> a >> b;
	recursion(a, 1);
	if (minCnt == INT32_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << minCnt << endl;
	}
	
	return 0;
}