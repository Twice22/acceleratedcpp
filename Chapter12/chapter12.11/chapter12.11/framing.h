#pragma once
#ifndef  _FRAMING_H
#define _FRAMING_H


#include "Str.h"

#include <vector>

typedef Str::size_type string_size;

Str::size_type maxwidth(const std::vector<Str>&);
std::vector<Str> frame(const std::vector<Str>&);
std::vector<Str> vconcat(const std::vector<Str>& top, const std::vector<Str>& bot);
std::vector<Str> hconcat(const std::vector<Str>& top, const std::vector<Str>& bot);

#endif // ! _FRAMING_H
