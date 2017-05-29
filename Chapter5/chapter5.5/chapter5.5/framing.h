#pragma once
#ifndef  _FRAMING_H
#define _FRAMING_H

#include <string>
#include <vector>

typedef std::string::size_type string_size;

string_size maxwidth(const std::vector<std::string>&);
std::vector<std::string> center(const std::vector<std::string>&);
std::vector<std::string> vconcat(const std::vector<std::string>& top, const std::vector<std::string>& bot);
std::vector<std::string> hconcat(const std::vector<std::string>& top, const std::vector<std::string>& bot);

#endif // ! _FRAMING_H
