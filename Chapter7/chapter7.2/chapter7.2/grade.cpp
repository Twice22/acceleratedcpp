#include "stdafx.h"
#include "grade.h"
#include "median.h"

using namespace std;

string gradetoletter(double grade) {
	if (grade >= 90) {
		return "A 90-100";
	}
	else if (grade >= 80) {
		return "B 80-89.99";
	}
	else if (grade >= 70) {
		return "C 70-79.99";
	}
	else if (grade >= 60) {
		return "D 60-69.99";
	}
	return "F <60";
}

string grade(double midterm, double final_grade, const std::vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("Student has done no homework!");
	return grade(midterm, final_grade, median(hw));
}

string grade(double midterm, double final_grade, double median) {
	double grade = 0.2 * midterm + 0.4 * final_grade + 0.4 * median;
	return gradetoletter(grade);
}