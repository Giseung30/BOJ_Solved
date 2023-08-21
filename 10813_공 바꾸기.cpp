#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 100;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int arr[101] = { 0, };
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= maxN; ++i) {
		arr[i] = i;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		swap(&arr[a], &arr[b]);
	}

	for (int i = 1, l = n; i <= l; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}