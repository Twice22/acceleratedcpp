#include "stdafx.h"
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include <algorithm>

using namespace std;

bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name() < s2.name();
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		double n;

		// get rid of previous content
		hw.clear();

		// read homework grades
		while (in >> n) {
			hw.push_back(n);
		}

		// clear the stream so that the ouput will work for the next student
		in.clear();
	}
	return in;
}

istream& Student_info::read(istream& in) {
	in >> n >> midterm >> final;
	::read_hw(in, homework);
	return in;
}

double Student_info::grade() const {
	return ::grade(midterm, final, homework);
}

bool Student_info::fgrade() const {
	return grade() < 60;
}

double Student_info::grade_aux() const {
	try {
		return grade();
	}
	catch (domain_error) {
		return ::grade(midterm, final, 0);
	}
}

double Student_info::average_grade() const {
	return ::grade(midterm, final, average(homework));
}

double Student_info::optimistic_median() const {
	// compute median only on homework that the students did (homework whose
	// grades are differents from 0)
	vector<double> nonzero;
	// only add non that are different from 0.0 to nonzero vector
	remove_copy(homework.begin(), homework.end(), back_inserter(nonzero), 0.0);
	if (nonzero.empty()) {
		return ::grade(midterm, final, 0);
	}
	else {
		return ::grade(midterm, final, ::median(nonzero));
	}

}

bool Student_info::did_all_hw() const {
	// we suppose that when a student didn't do a homework he has a 0
	// if the student did the homework he's grade will be higher than 0.
	return ((find(homework.begin(), homework.end(), 0)) == homework.end());
}