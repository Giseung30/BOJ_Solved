#include <iostream>
#define endl '\n'
using namespace std;

const int longByte = 4;

int main() {
	char longStr[] = "long";
	char intStr[] = "int";

	int n;
	cin >> n;

	for (int i = 0, l = n / longByte; i < l; ++i) {
		cout << longStr << ' ';
	}

	cout << intStr << endl;
	return 0;
}