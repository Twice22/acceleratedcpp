#include "stdafx.h"
#include "split.h"
#include <algorithm>

using namespace std;

bool space(char c) {
	return isspace(c);
}

bool notspace(char c) {
	return !isspace(c);
}