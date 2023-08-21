#include <iostream>
using namespace std;

int main() {
	string str;

	while (!cin.eof()) {
		char ch = cin.get();
		if (ch != -1)
			cout << ch;
	}
	return 0;
}