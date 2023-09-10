#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n, m, cnt;
vector<vector<int>> graph;
vector<bool> visited;

void simulation(int num) {
	if (visited[num]) return;

	visited[num] = true;
	++cnt;
	for (int i = 0, l = graph[num].size(); i < l; ++i) {
		simulation(graph[num][i]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	cin >> m;

	graph.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	simulation(1);
	cout << cnt - 1 << endl;

	return 0;
}