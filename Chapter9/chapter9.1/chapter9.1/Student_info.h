#pragma once
#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <iostream>
#include <string>
#include <vector>

class Student_info {
private:
	std::string n;
	// Answer to Q9.1
	double midterm, final, total_grade;
	std::vector<double> homework;
public:
	Student_info(); // construct an empty Student_info object
	Student_info(std::istream&); // construct a Student_info object based on the input steam
	std::string name() const { return n; };
	std::istream& read(std::istream&);
	double grade() const;
	bool valid() { return !homework.empty(); };
};

/*
Answer to Q9.2
if change std::string name() const { return n; };
to std::string name() { return n; };
we would need to change each function that call name().
therefore, we would need to change
bool compare(const Student_info&, const Student_info&);
to bool compare(Student_info&, Student_info&);
Indeed, we cannot call noncost function on cost object!
*/
bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif