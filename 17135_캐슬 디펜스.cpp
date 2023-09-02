#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

typedef struct Dot{
	int x;
	int y;
	int d;
	Dot() {
		x = y = d = 0;
	}
	Dot(int X, int Y, int D) {
		x = X, y = Y, d = D;
	}
}Dot;

const int maxN = 16;
int n, m, d;
int maxDead;
int arr[maxN][maxN];
int dead[maxN][maxN];
int visited[maxN][maxN];
queue<Dot> qu;
Dot t, t2, t3;

void simulate(int x, int y, Dot* t);
void clearVisited();
int clearDead();
bool cmpDot(Dot a, Dot b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				for (int l = n - 1; l >= 0; --l) {
					simulate(l, i, &t);
					simulate(l, j, &t2);
					simulate(l, k, &t3);

					if (t.x != -1 && t.y != -1) dead[t.x][t.y] = true;
					if (t2.x != -1 && t2.y != -1) dead[t2.x][t2.y] = true;
					if (t3.x != -1 && t3.y != -1) dead[t3.x][t3.y] = true;
				}
				int deadCnt = clearDead();
				if (maxDead < deadCnt) maxDead = deadCnt;
			}
		}
	}

	cout << maxDead << endl;
	return 0;
}

void simulate(int x, int y, Dot* t) {
	clearVisited();
	t->x = t->y = -1;
	while (!qu.empty()) qu.pop();
	qu.push(Dot(x, y, 1));

	while (!qu.empty()) {
		Dot dot = qu.front();
		qu.pop();

		visited[dot.x][dot.y] = true;
		if (arr[dot.x][dot.y] && !dead[dot.x][dot.y]) {
			*t = dot;
			return;
		}

		if (dot.d < d) {
			if (dot.y > 0 && !visited[dot.x][dot.y - 1]) {
				qu.push(Dot(dot.x, dot.y - 1, dot.d + 1));
			}
			if (dot.x > 0 && !visited[dot.x - 1][dot.y]) {
				qu.push(Dot(dot.x - 1, dot.y, dot.d + 1));
			}
			if (dot.y + 1 < m && !visited[dot.x][dot.y + 1]) {
				qu.push(Dot(dot.x, dot.y + 1, dot.d + 1));
			}
		}
	}
}

void clearVisited() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = false;
		}
	}
}

int clearDead() {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dead[i][j]) {
				++cnt;
				dead[i][j] = false;
			}
		}
	}
	return cnt;
}

bool cmpDot(Dot a, Dot b) {
	if (a.d == b.d) {
		if (a.y == b.y) {
			return a.x > b.x;
		}
		else {
			return a.y < b.y;
		}
	}
	else {
		return a.d < b.d;
	}
}