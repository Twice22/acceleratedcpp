#pragma once
#ifndef _XREF_TABLE_
#define _XREF_TABLE_

#include <map>
#include <vector>
#include <string>
#include "split.h"


// find all the lines that refer to each word in the input
template <class OutIter>
OutIter xref(std::istream& in,
	OutIter out,
	void find_words(const string&, std::back_insert_iterator<std::vector<std::string> >)) {

	std::string wl;
	int line = 0;
	map<string, vector<int> > ret;

	while (getline(cin, wl)) {
		++line;

		std::vector<std::string> word_vec = find_words(wl);

		for (std::vector<std::string>::const_iterator it = word_vec.begin(); it != word_vec.end(); it++) {
			*out++ = std::make_pair(*it, line);
		}
	}

	return out;
}

#endif // !_XREF_TABLE_
