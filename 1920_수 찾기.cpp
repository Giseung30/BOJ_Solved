#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int n, m, arr[100001], tmp;
map<int, bool> exists;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		exists.insert(pair<int, bool>(arr[i], true));
	}

	cin >> m;
	while (m--) {
		cin >> tmp;
		if (exists.find(tmp) == exists.end()) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}

	return 0;
}