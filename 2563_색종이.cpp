#include <iostream>
using namespace std;

const int maxNum = 101;
const int paperSize = 10;

int arr[maxNum][maxNum];

int main() {
	int n;
	cin >> n;

	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + paperSize; ++i) {
			for (int j = y; j < y + paperSize; ++j) {
				arr[i][j] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i < maxNum; ++i) {
		for (int j = 1; j < maxNum; ++j) {
			sum += arr[i][j];
		}
	}
	cout << sum << endl;
	return 0;
}