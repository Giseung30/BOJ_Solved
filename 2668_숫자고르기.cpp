#include <iostream>
#include <vector>
using namespace std;
const int maxSize = 101;

int n;
int arr[maxSize];
int start;
vector<int> path;
bool result[maxSize];
bool visited[maxSize];

void recursion(int index) {
	if (visited[arr[index]]) return;

	visited[arr[index]] = true;
	path.push_back(arr[index]);

	if (arr[index] == start) {
		for (int i = 0, l = path.size(); i < l; ++i) {
			result[path[i]] = true;
		}
		return;
	}

	recursion(arr[index]);
	path.pop_back();
	visited[arr[index]] = false;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; ++i) {
		start = i;
		recursion(i);
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (result[i]) ++cnt;
	}

	cout << cnt << endl;
	for (int i = 1; i <= n; ++i) {
		if (result[i])
			cout << i << endl;
	}

	return 0;
}