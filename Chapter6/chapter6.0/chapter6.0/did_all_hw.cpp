#include "stdafx.h"
#include "did_all_hw.h"
#include "Student_info.h"


bool did_all_hw(const Student_info& student) {
	// we suppose that when a student didn't do a homework he has a 0
	// if the student did the homework he's grade will be higher than 0.
	return ((find(student.homework.begin(), student.homework.end(), 0)) == student.homework.end());
}
