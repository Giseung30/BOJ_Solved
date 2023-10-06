#include <iostream>
#define endl '\n'
using namespace std;

char res[] = { 'E', 'A', 'B', 'C', 'D' };
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; ++i) {
		int n, cnt = 0;
		for (int j = 0; j < 4; ++j) {
			cin >> n;
			if (n == 0) ++cnt;
		}
		cout << res[cnt] << endl;
	}
	return 0;
}