#include <iostream>
using namespace std;

int main() {
	int n;
	string str[51];

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> str[i];
	}

	for (int i = 0, l = str[0].length(); i < l; ++i) {
		bool diff = false;
		char ch = str[0][i];

		for (int j = 0; j < n; ++j) {
			if (ch != str[j][i]) {
				diff = true;
				break;
			}
		}

		if (diff) {
			cout << '?';
		}
		else {
			cout << ch;
		}
	}
    
	cout << endl;
	return 0;
}