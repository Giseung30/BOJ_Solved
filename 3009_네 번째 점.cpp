#include <iostream>
using namespace std;

int main() {
	int a[3], b[3];

	for (int i = 0; i < 3; ++i)
		cin >> a[i] >> b[i];

	if (a[0] == a[1])
		cout << a[2];
	else if (a[0] == a[2])
		cout << a[1];
	else
		cout << a[0];

	cout << ' '; 

	if (b[0] == b[1])
		cout << b[2];
	else if (b[0] == b[2])
		cout << b[1];
	else
		cout << b[0];

	return 0;
}