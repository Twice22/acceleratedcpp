#pragma once
#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <iostream>
#include <string>

#include "Vec.h"

class Student_info {
private:
	std::string n;
	double midterm, final;
	Vec<double> homework;
public:
	Student_info(); // construct an empty Student_info object
	Student_info(std::istream&); // construct a Student_info object based on the input steam
	std::string name() const { return n; };
	std::istream& read(std::istream&);
	double grade() const;
	bool valid() { return !homework.empty(); };
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, Vec<double>&);

#endif