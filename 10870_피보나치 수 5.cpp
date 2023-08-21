#include <iostream>
using namespace std;

const int maxNum = 21;

int main() {
	int n;
	long long arr[maxNum] = { 0 };
	arr[1] = 1;

	cin >> n;
	for (int i = 2; i < maxNum; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n] << endl;
	return 0;
}