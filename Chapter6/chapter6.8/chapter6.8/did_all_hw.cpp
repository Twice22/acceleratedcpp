#include "stdafx.h"
#include "did_all_hw.h"
#include <algorithm>


bool did_all_hw(const Student_info& student) {
	// we suppose that when a student didn't do a homework he has a 0
	// if the student did the homework he's grade will be higher than 0.
	return ((find(student.homework.begin(), student.homework.end(), 0)) == student.homework.end());
}

Student_infos extract_didnt(Student_infos& students) {
	// rearrange the elements in students. elements that satisfy the predicate did_all_hw (did all the hw)
	// precede the ones that don't satisfy pgrade. It returns an iterator that represents the second
	// element of the second section
	Student_infos::iterator iter = stable_partition(students.begin(), students.end(), did_all_hw);

	// didnt is construct as a copy of student from range iter to the end
	Student_infos didnt(iter, students.end());

	// erase students who didn't do all the hw from students
	students.erase(iter, students.end());

	return didnt;
}