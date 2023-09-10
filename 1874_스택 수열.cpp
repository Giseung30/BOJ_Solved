#include <iostream>
#include <vector>
#include <stack>
#define endl '\n'
using namespace std;

int n, arr[100001];
int pointer;
int cnt = 1;
bool impossible;
stack<int> st;
vector<char> res;

void save(char ch) {
	res.push_back(ch);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	st.push(0);
	while (pointer < n) {
		if (arr[pointer] > st.top()) {
			if (cnt > arr[pointer]) {
				impossible = true;
				break;
			}
			else {
				st.push(cnt++);
				save('+');
			}
		}
		else if (arr[pointer] < st.top()) {
			if (cnt < arr[pointer]) {
				impossible = true;
				break;
			}
			else {
				st.pop();
				save('-');
			}
		}
		else {
			st.pop();
			save('-');
			++pointer;
		}
	}

	if (impossible) {
		cout << "NO" << endl;
	}
	else {
		for (int i = 0, l = res.size(); i < l; ++i) {
			cout << res[i] << endl;
		}
	}

	return 0;
}