#pragma once
#ifndef _FIND_URL_
#define _FIND_URL_

#include <vector>
#include <string>

bool not_url_char(char);
std::string::const_iterator end_urls(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator begin_urls(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);

#endif