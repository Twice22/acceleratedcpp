#pragma once
#ifndef _XREF_TABLE_
#define _XREF_TABLE_

#include <map>
#include <vector>
#include <string>
#include "split.h"

std::map<std::string, std::vector<int> > xref(std::istream&, std::vector<std::string> find_words(const std::string&) = split);
void display_xref(const std::map<std::string, std::vector<int> >&);

#endif // !_XREF_TABLE_
