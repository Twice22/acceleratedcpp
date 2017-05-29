#include "stdafx.h"
#include "grade.h"

using namespace std;

double grade(double midterm, double final, const vector<double>& homework) {
	if (homework.size() == 0) throw domain_error("student has done no homework");
	return grade(midterm, final, median(homework));
}

double grade(double midterm, double final, double hw) {
	return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

// Answer to Q13.4
string letter_grade(double g) {

	static const double grade[] = { 97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };

	static const char* const letter[] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };

	static const size_t size = sizeof(letter) / sizeof(*letter);

	for (size_t i = 0; i < size; ++i) {
		if (g >= grade[i]) return letter[i];
	}

	// Student have a negative grade ?
	return "\?\?\?";
}