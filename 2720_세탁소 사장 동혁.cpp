#include <iostream>
#define endl '\n'
using namespace std;

int t;
int n;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		cout << n / 25 << ' ';
		cout << n % 25 / 10 << ' ';
		cout << n % 25 % 10 / 5 << ' ';
		cout << n % 25 % 10 % 5 << endl;
	}
	return 0;
}