#pragma once
#pragma once
#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <iostream>
#include <string>
#include <vector>

class Student_info {
public:
	std::string name() const { return n; }
	bool valid() { return !homework.empty(); }
	std::istream& read(std::istream&);
	double grade() const;
	bool fgrade() const;
	double grade_aux() const;
	double average_grade() const;
	double optimistic_median() const;
	bool did_all_hw() const;
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};

typedef std::vector<Student_info> Student_infos;

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif