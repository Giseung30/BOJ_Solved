#include <iostream>
using namespace std;

int n;
int arr[16];

int main() {
	arr[1] = 3;
	cin >> n;

	for (int i = 2; i <= n; ++i) {
		arr[i] = arr[i - 1] * 2 - 1;
	}

	cout << arr[n] * arr[n] << endl;
	return 0;
}