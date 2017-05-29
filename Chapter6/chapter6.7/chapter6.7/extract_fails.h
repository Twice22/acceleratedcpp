#pragma once
#ifndef _EXTRACT_FAILS_
#define _EXTRACT_FAILS_

#include "Student_info.h"
#include "grade.h"
#include <list>
#include <vector>
#include <iomanip>


Student_infos extract_fails(Student_infos&);
void display(const Student_infos&, std::string, std::string::size_type);

#endif