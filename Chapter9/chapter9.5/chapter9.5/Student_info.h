#pragma once
#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <iostream>
#include <string>
#include <vector>

class Student_info {
private:
	std::string n;
	double midterm, final;
	std::string g;
public:
	Student_info(); // construct an empty Student_info object
	Student_info(std::istream&); // construct a Student_info object based on the input steam

	std::string name() const { return n; };
	std::istream& read(std::istream&);
	std::string grade() const;
};

bool compare(const Student_info&, const Student_info&);

#endif