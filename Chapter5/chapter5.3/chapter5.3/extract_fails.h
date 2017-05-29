#pragma once
#ifndef _EXTRACT_FAILS_
#define _EXTRACT_FAILS_

#include "Student_info.h"
#include "grade.h"
#include <list>
#include <vector>
#include <iomanip>

// Answer to Q5.3
// switch between list and vector by commenting/uncommenting below lines
typedef std::list<Student_info> Student_infos;
//typedef std::vector<Student_info> Student_infos;

Student_infos extract_fails(Student_infos&);
void display(const Student_infos&, std::string, std::string::size_type);

#endif