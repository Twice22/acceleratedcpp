#include "stdafx.h"
#include "xreftable.h"
#include "split.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

// Answer to Q7.4
#include <sstream> 
#define MAX_LENGTH 80

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
			if (find(ret[*it].begin(), ret[*it].end(), line) == ret[*it].end()) {
				ret[*it].push_back(line);
			}
		}
	}

	return ret;
}

// Answer to Q7.4
// display word along with the lines in which they occur.
void display_xref(const map<string, vector<int> >& xtable) {

	for (map<string, vector<int> >::const_iterator it = xtable.begin();
		it != xtable.end(); ++it) {

		stringstream sstream;

		sstream << "word " << it->first << " appears on line(s): ";

		vector<int>::const_iterator iter = it->second.begin();
		sstream << *iter;

		++iter;
		while (iter != it->second.end()) {
			sstream << ", " << *iter;
			++iter;
		}

		// Answer to Q7.4
		string out = sstream.str();

		for (string::size_type i = 0; i < out.size(); ++i) {
			cout << out[i];
			if ((i + 1) % MAX_LENGTH == 0) {
				cout << endl;
			}
		}

		// separate each word
		cout << endl;

	}
}