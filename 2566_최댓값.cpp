#include <iostream>
using namespace std;

const int maxNum = 9;
int maxValue = INT32_MIN;
int k, l;

int main() {
	for (int i = 1; i <= maxNum; ++i) {
		for (int j = 1; j <= maxNum; ++j) {
			int tmp;
			cin >> tmp;
			if (maxValue < tmp) {
				maxValue = tmp;
				k = i;
				l = j;
			}
		}
	}

	cout << maxValue << endl;
	cout << k << ' ' << l << endl;

	return 0;
}