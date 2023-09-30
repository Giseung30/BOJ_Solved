#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int recursion(int sum, int rMin, int rMax, int cMin, int cMax);

int n, row, col;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> row >> col;
	cout << recursion(0, 0, pow(2, n), 0, pow(2, n)) << endl;

	return 0;
}

int recursion(int sum, int rMin, int rMax, int cMin, int cMax) {
	int rHalf = rMin + (rMax - rMin) / 2;
	int cHalf = cMin + (cMax - cMin) / 2;
	int childSize = (int)pow((rMax - rMin) / 2, 2);

	if (childSize == 0) {
		return sum;
	}

	if (rMin <= row && row < rHalf && cMin <= col && col < cHalf) {
		return recursion(sum, rMin, rHalf, cMin, cHalf);
	}
	else if (rMin <= row && row < rHalf && cHalf <= col && col < cMax) {
		return recursion(sum + childSize, rMin, rHalf, cHalf, cMax);
	}
	else if (rHalf <= row && row < rMax && cMin <= col && col < cHalf) {
		return recursion(sum + childSize * 2, rHalf, rMax, cMin, cHalf);
	}
	else {
		return recursion(sum + childSize * 3, rHalf, rMax, cHalf, cMax);
	}
}