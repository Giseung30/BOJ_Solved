#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

long long n, m;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	cout << abs(n - m) << endl;
	return 0;
}