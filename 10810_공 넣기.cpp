#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	int arr[101] = { 0, };
	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = a, l = b; i <= l; ++i){
			arr[i] = c;
		}
	}

	for (int i = 1, l = n; i <= l; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}