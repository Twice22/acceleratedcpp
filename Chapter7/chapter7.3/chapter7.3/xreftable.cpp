#include "stdafx.h"
#include "xreftable.h"
#include "split.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&)) {

	string wl;
	int line = 0;
	map<string, vector<int> > ret;

	while (getline(cin, wl)) {
		++line;

		vector<string> word_vec = find_words(wl);


		for (vector<string>::const_iterator it = word_vec.begin(); it != word_vec.end(); it++) {
			// Answer to Q7.3
			// if we don't find the line in ret[*it] then add that line
			if (find(ret[*it].begin(), ret[*it].end(), line) == ret[*it].end()) {
				ret[*it].push_back(line);
			}
		}
	}

	return ret;
}

// display word along with the lines in which they occur.
void display_xref(const map<string, vector<int> >& xtable) {

	for (map<string, vector<int> >::const_iterator it = xtable.begin();
		it != xtable.end(); ++it) {

		cout << "word " << it->first << " appears on line(s): ";

		vector<int>::const_iterator iter = it->second.begin();
		cout << *iter;

		++iter;
		while ( iter != it->second.end()) {
			cout << ", " << *iter;
			++iter;
		}
		cout << endl;
	}
}