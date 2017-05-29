#pragma once
#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	std::string total;
};

std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif