#pragma once
#ifndef _XREF_TABLE_
#define _XREF_TABLE_

#include <map>
#include <vector>
#include <string>
#include "findurl.h"

// Answer to Q7.8 (only need to change = find_urls and write find_urls)
std::map<std::string, std::vector<int> > xref(std::istream&, std::vector<std::string> find_words(const std::string&) = find_urls);
void display_xref(const std::map<std::string, std::vector<int> >&);

#endif // !_XREF_TABLE_
