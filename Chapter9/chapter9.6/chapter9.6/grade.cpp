#include "stdafx.h"
#include "grade.h"

using namespace std;

string grade(double midterm, double final_grade) {
	double g = 0.5 * (midterm + final_grade);
	if (g > 60) {
		return "P";
	}
	return "F";
}