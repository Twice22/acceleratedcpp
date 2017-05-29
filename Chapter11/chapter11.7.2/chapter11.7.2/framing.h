#pragma once
#ifndef  _FRAMING_H
#define _FRAMING_H

#include <string>

// Answer to Q11.7
#include "Vec.h"

typedef std::string::size_type string_size;

string_size maxwidth(const Vec<std::string>&);
Vec<std::string> frame(const Vec<std::string>&);
Vec<std::string> vconcat(const Vec<std::string>& top, const Vec<std::string>& bot);
Vec<std::string> hconcat(const Vec<std::string>& top, const Vec<std::string>& bot);

#endif // ! _FRAMING_H
