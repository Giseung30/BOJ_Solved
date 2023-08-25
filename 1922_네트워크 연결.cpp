#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	int a;
	int b;
	int c;
}Line;

int n, m, result;
vector<int> root;
vector<Line> lines;

bool sortLine(Line a, Line b);
int getRoot(int val);
void connect(int a, int b);

int main() {
	cin >> n >> m;

	lines.resize(m);

	for (int i = 0; i <= n; ++i)
		root.push_back(i);

	for (int i = 0; i < m; ++i)
		cin >> lines[i].a >> lines[i].b >> lines[i].c;

	sort(lines.begin(), lines.end(), sortLine);

	for (int i = 0; i < m; ++i) {
		if (getRoot(lines[i].a) != getRoot(lines[i].b)) {
			connect(lines[i].a, lines[i].b);
			result += lines[i].c;
		}
	}

	cout << result << endl;
	return 0;
}

bool sortLine(Line a, Line b) {
	return a.c < b.c;
}

int getRoot(int val) {
	if (val == root[val]) {
		return val;
	}
	return getRoot(root[val]);
}

void connect(int a, int b) {
	root[getRoot(b)] = getRoot(a);
}