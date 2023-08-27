#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxN = 500001;

int n;
int arr[maxN];
int sum;
int maxCnt = 1;
map<int, int> cnt;
map<int, int>::iterator iter;
vector<int> maxCntArr;

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];

		iter = cnt.find(arr[i]);
		if (iter == cnt.end()) {
			cnt.insert(pair<int, int>(arr[i], 1));
		}
		else {
			++(iter->second);
			if (iter->second > maxCnt)
				maxCnt = iter->second;
		}
	}

	sort(arr, arr + n, less<int>());

	double avg = round((double)sum / n);
	if (avg == 0)
		cout << 0 << endl;
	else
		cout << avg << endl;

	cout << arr[(n - 1) / 2] << endl;

	for (iter = cnt.begin(); iter != cnt.end(); ++iter) {
		if (iter->second == maxCnt)
			maxCntArr.push_back(iter->first);
	}
	sort(maxCntArr.begin(), maxCntArr.end(), less<int>());
	if (maxCntArr.size() > 1)
		cout << maxCntArr[1] << endl;
	else
		cout << maxCntArr[0] << endl;

	cout << arr[n - 1] - arr[0] << endl;
	
	return 0;
}