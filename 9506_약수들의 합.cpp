#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n, sum;
vector <int> res;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	while (true) {
		cin >> n;
		if (n == -1) break;

		res.clear();
		sum = 0;
		for (int i = 1; i < n; ++i) {
			if (n % i == 0) {
				res.push_back(i);
				sum += i;
			}
		}
		if (sum == n) {
			cout << n << " = ";
			for (int i = 0, l = res.size(); i < l; ++i) {
				cout << res[i];
				if (i == l - 1)
					cout << endl;
				else
					cout << " + ";
			}
		}
		else {
			cout << n << " is NOT perfect." << endl;
		}
	}
	return 0;
}