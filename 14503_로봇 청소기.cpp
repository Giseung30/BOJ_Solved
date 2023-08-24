#include <iostream>
using namespace std;

const int maxNum = 51;

int n, m;
int r, c;
int d;
int cnt;
int room[maxNum][maxNum];
bool clean[maxNum][maxNum];

bool aroundUncleaned(int row, int col) {
	bool result = false;
	if (row > 0 && room[row - 1][col] == 0 && !clean[row - 1][col]) result = true;
	if (row - 1 < r && room[row + 1][col] == 0 && !clean[row + 1][col]) result = true;
	if (col > 0 && room[row][col - 1] == 0 && !clean[row][col - 1]) result = true;
	if (col - 1 < c && room[row][col + 1] == 0 && !clean[row][col + 1]) result = true;
	return result;
}
bool forwardUncleaned(int row, int col, int dir) {
	switch (dir) {
	case 0:
		if (row > 0 && room[row - 1][col] == 0)
			return !clean[row - 1][col];
		break;
	case 1:
		if (col - 1 < c && room[row][col + 1] == 0)
			return !clean[row][col + 1];
		break;
	case 2:
		if (row - 1 < r && room[row + 1][col] == 0)
			return !clean[row + 1][col];
		break;
	case 3:
		if (col > 0 && room[row][col - 1] == 0)
			return !clean[row][col - 1];
		break;
	}
	return false;
}
bool moveBackward(int* row, int* col, int dir) {
	switch (dir) {
	case 0:
		if (*row - 1 < r && room[*row + 1][*col] == 0) {
			*row += 1;
			return true;
		}
		break;
	case 1:
		if (*col > 0 && room[*row][*col - 1] == 0) {
			*col -= 1;
			return true;
		}
		break;
	case 2:
		if (*row > 0 && room[*row - 1][*col] == 0)
		{
			*row -= 1;
			return true;
		}
		break;
	case 3:
		if (*col - 1 < c && room[*row][*col + 1] == 0)
		{
			*col += 1;
			return true;
		}
		break;
	}
	return false;
}
bool moveForward(int* row, int* col, int dir) {
	switch (dir) {
	case 0:
		if (*row > 0 && room[*row - 1][*col] == 0) {
			*row -= 1;
			return true;
		}
		break;
	case 1:
		if (*col - 1 < c && room[*row][*col + 1] == 0)
		{
			*col += 1;
			return true;
		}
		break;
	case 2:
		if (*row - 1 < r && room[*row + 1][*col] == 0)
		{
			*row += 1;
			return true;
		}
		break;
	case 3:
		if (*col > 0 && room[*row][*col - 1] == 0)
		{
			*col -= 1;
			return true;
		}
		break;
	}
	return false;
}
void counterWise(int* dir) {
	switch (*dir) {
	case 0:
		*dir = 3;
		break;
	case 1:
		*dir = 0;
		break;
	case 2:
		*dir = 1;
		break;
	case 3:
		*dir = 2;
		break;
	}
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> room[i][j];
		}
	}

	while (true) {
		if (!clean[r][c]) {
			clean[r][c] = true;
			++cnt;
		}
		if (aroundUncleaned(r, c)) {
			counterWise(&d);
			if (forwardUncleaned(r, c, d)) {
				moveForward(&r, &c, d);
			}
		}
		else {
			if (!moveBackward(&r, &c, d)) {
				break;
			}
		}
	}
	
	cout << cnt << endl;
	return 0;
}