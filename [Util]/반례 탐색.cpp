#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void createInput(ofstream* fout);
void codeCorrect(ifstream* fin, ofstream * fout);
void codeIncorrect(ifstream* fin, ofstream* fout);

string inputName = "Input.txt";
string correctName = "Correct.txt";
string incorrectName = "Incorrect.txt";

int main() {
	srand(time(NULL));

	int cnt;
	cout << "¹Ý·Ê Å½»ö È½¼ö  : ";
	cin >> cnt;

	for (int i = 0; cnt < 0 || i < cnt; ++i) {
		cout << i + 1 << "¹øÂ° ..." << endl;

		ifstream fin;
		ofstream fout;

		fout.open(inputName);
		createInput(&fout);
		fout.close();

		fin.open(inputName);
		fout.open(correctName);
		codeCorrect(&fin, &fout);
		fin.close();
		fout.close();

		fin.open(inputName);
		fout.open(incorrectName);
		codeIncorrect(&fin, &fout);
		fin.close();
		fout.close();

		ifstream fin1(correctName);
		ifstream fin2(incorrectName);
		bool check = true;
		while (true) {
			if (!fin1.eof() && !fin2.eof()) {
				char ch1 = fin1.get();
				char ch2 = fin2.get();

				if (ch1 != ch2){
					check = false;
					break;
				}
			}
			else if (fin1.eof() && !fin2.eof()) {
				check = false;
				break;
			}
			else if (!fin1.eof() && fin2.eof()) {
				check = false;
				break;
			}
			else {
				break;
			}
		}
		fin1.close();
		fin2.close();

		if (!check) {
			cout << "¹Ý·Ê ¹ß°ß!" << endl;
			break;
		}
	}

	return 0;
}

//--------------------------------------------------------------- Create Input
void createInput(ofstream* fout) {
}

//--------------------------------------------------------------- Code Correct
void codeCorrect(ifstream* fin, ofstream* fout) {
}

//--------------------------------------------------------------- Code Incorrect
void codeIncorrect(ifstream* fin, ofstream* fout) {
}