#include <iostream>
#include <cmath>
using namespace std;

int arr[91], n, sum;
string str;

void init() {
	arr['0'] = 0;
	arr['1'] = 1;
	arr['2'] = 2;
	arr['3'] = 3;
	arr['4'] = 4;
	arr['5'] = 5;
	arr['6'] = 6;
	arr['7'] = 7;
	arr['8'] = 8;
	arr['9'] = 9;
	arr['A'] = 10;
	arr['B'] = 11;
	arr['C'] = 12;
	arr['D'] = 13;
	arr['E'] = 14;
	arr['F'] = 15;
	arr['G'] = 16;
	arr['H'] = 17;
	arr['I'] = 18;
	arr['J'] = 19;
	arr['K'] = 20;
	arr['L'] = 21;
	arr['M'] = 22;
	arr['N'] = 23;
	arr['O'] = 24;
	arr['P'] = 25;
	arr['Q'] = 26;
	arr['R'] = 27;
	arr['S'] = 28; 
	arr['T'] = 29;
	arr['U'] = 30;
	arr['V'] = 31;
	arr['W'] = 32;
	arr['X'] = 33;
	arr['Y'] = 34;
	arr['Z'] = 35;
}
int main() {
	init();

	cin >> str;
	cin >> n;
	
	for (int i = 0, l = str.length(); i < l; ++i) {
		sum += pow(n, i) * arr[str[l - i - 1]];
	}

	cout << sum << endl;
	return 0;
}