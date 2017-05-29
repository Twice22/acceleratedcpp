#include "stdafx.h"
#include "grade.h"

using namespace std;

// Answer to 10.1
string grade(double midterm, double final_grade) {
	const double g = 0.5 * (midterm + final_grade);

	static const double grade[] = { 97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };
	static const char *letter[] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };

	size_t size = sizeof(grade) / sizeof(*grade);
	for (size_t i = 0; i < size; i++) {
		if (g > grade[i]) return letter[i];
	}

	return "\?\?\?";
}