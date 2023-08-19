#include <iostream>
#include <string>
using namespace std;

const int operNum = 4;
const int operation[] = { '+', '-', '*', '/' };

int n;
int arr[12];
int operUsed[4];
int resultMax = INT32_MIN;
int resultMin = INT32_MAX;

int calculate(int a, int b, char op) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (a < 0)
			return -(-a / b);
		else
			return a / b;
	}
	return NULL;
}

void backTracking(int idx, int result) {
	if (idx == n) {
		resultMax = result > resultMax ? result : resultMax;
		resultMin = result < resultMin ? result : resultMin;
	}
	else {
		for (int i = 0, l = operNum; i < l; ++i) {
			if (operUsed[i] > 0) {
				--operUsed[i];
				backTracking(idx + 1, calculate(result, arr[idx], operation[i]));
				++operUsed[i];
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0, l = n; i < l; ++i)
		cin >> arr[i];

	for (int i = 0, l = operNum; i < l; ++i)
		cin >> operUsed[i];

	backTracking(1, arr[0]);

	cout << resultMax << endl;
	cout << resultMin << endl;

	return 0;
}