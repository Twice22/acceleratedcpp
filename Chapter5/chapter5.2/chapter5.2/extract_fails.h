#pragma once
#ifndef _EXTRACT_FAILS_
#define _EXTRACT_FAILS_

#include "Student_info.h"
#include "grade.h"
#include <list>
#include <vector>
#include <iomanip>

std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
void display_v(const std::vector<Student_info>&, std::string, std::string::size_type);
void display_l(const std::list<Student_info>&, std::string, std::string::size_type);

#endif