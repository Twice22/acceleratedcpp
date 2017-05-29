#pragma once
#ifndef _CLASSIFY_
#define _CLASSIFY_

#include "Student_info.h"
#include "grade.h"
#include <list>
#include <vector>
#include <iomanip>

bool pgrade(const Student_info&);
Student_infos classify(Student_infos&, bool criteria(const Student_info&));
void display(const Student_infos&, std::string, std::string::size_type);

#endif