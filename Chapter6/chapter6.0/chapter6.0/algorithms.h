#pragma once
#ifndef _ALGO_H_
#define _ALGO_H_

#include <algorithm>
#include <vector>
#include <string>

bool space(char);
bool not_space(char);

bool is_palindrom(const std::string&);
bool not_url_char(char);
std::vector<std::string> split(const std::string&);


std::string::const_iterator end_url(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator begin_url(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);

#endif // !_ALGO_H_
