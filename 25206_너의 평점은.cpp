#include <stdio.h>
#include <string.h>

const int gradeNum = 9;
const char gradeStr[][3] = { "A+", "A0", "B+","B0", "C+", "C0", "D+", "D0","F" };
const double gradeScore[] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0 };

int getGrade(char* grade, double* result) {
	for (int i = 0, l = gradeNum; i < l; ++i) {
		if (strcmp(grade, gradeStr[i]) == 0) {
			*result = gradeScore[i];
			return 1;
		}
	}
	return 0;
}

int main() {
	char name[100];
	double credit;
	char str[5];

	double grade;
	double creditSum = 0;
	double sum = 0;

	for (int i = 0, l = 20; i < l; ++i) {
		scanf("%s %lf %s", name, &credit, str);
		if (getGrade(str, &grade) == 1) {
			creditSum += credit;
			sum += credit * grade;
		}
	}

	printf("%.6lf\n", sum / creditSum);
	return 0;
}