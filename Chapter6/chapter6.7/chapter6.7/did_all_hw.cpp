#include "stdafx.h"
#include "did_all_hw.h"
#include "Student_info.h"
#include <algorithm>


// Answer to Q6.7
Student_infos extract_didnt(Student_infos& students) {
	// rearrange the elements in students. elements that satisfy the predicate did_all_hw (did all the hw)
	// precede the ones that don't satisfy pgrade. It returns an iterator that represents the second
	// element of the second section
	Student_infos::iterator iter = stable_partition(students.begin(), students.end(), Student_info::did_all_hw);

	// didnt is construct as a copy of student from range iter to the end
	Student_infos didnt(iter, students.end());

	// erase students who didn't do all the hw from students
	students.erase(iter, students.end());

	return didnt;
}