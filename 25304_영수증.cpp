#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	int money;
	int n;
	int sum = 0;

	cin >> money;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}

	if (sum == money)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}