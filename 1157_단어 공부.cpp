#include <iostream>
#define alphaNum 26
using namespace std;

void toUpper(char* ch) {
	if ('a' <= *ch && *ch <= 'z') {
		*ch -= 'a' - 'A';
	}
}

int main() {
	string str;
	int strLen;
	int cnt[alphaNum] = { 0 };
	
	int maxCnt = INT32_MIN;
	char maxCh;

	cin >> str;

	strLen = str.length();

	for (int i = 0; i < strLen; ++i) {
		toUpper(&str[i]);
		++cnt[str[i] - 'A'];
	}

	for (int i = 0; i < alphaNum; ++i) {
		if (maxCnt < cnt[i]) {
			maxCnt = cnt[i];
			maxCh = i + 'A';
		}
	}

	bool several = false;
	for (int i = 0; i < alphaNum; ++i) {
		if (maxCnt == cnt[i] && maxCh != i + 'A') {
			several = true;
			break;
		}
	}

	if (several) {
		cout << '?' << endl;
	}
	else {
		cout << maxCh << endl;
	}

	return 0;
}