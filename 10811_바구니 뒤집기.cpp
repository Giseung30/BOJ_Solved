#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 101;

void setReverse(int *arr, int a, int b) {
	int tArr[maxN] = { 0, };
	for (int i = 0, l = b - a + 1; i < l; ++i) {
		tArr[i] = arr[b - i];
	}
	for (int i = 0, l = b - a + 1; i < l; ++i) {
		arr[a + i] = tArr[i];
	}
}

int main() {
	int arr[maxN] = { 0, };
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		arr[i] = i;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		setReverse(arr, a, b);
	}

	for (int i = 1, l = n; i <= l; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}