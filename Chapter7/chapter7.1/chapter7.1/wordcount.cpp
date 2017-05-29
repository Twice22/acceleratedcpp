#include "stdafx.h"
#include "wordcount.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// count number of times each distinct word occurs in input
void wordcount() {
	string s;
	map<string, int> wc;

	// use freq as the key and add all the words with such a frequency.
	map<int, vector<string> > wfreq;

	while (cin >> s) {
		// if the key `s` doesn't exit, it will create it and initialize the value (int here) to 0.
		++wc[s];
	}

	for (map<string, int>::const_iterator it = wc.begin(); it != wc.end(); ++it) {
		wfreq[it->second].push_back(it->first);
	}

	// display
	for (map<int, vector<string> >::const_iterator it = wfreq.begin(); it != wfreq.end(); ++it) {
		cout << "freq: " << it->first << ", words:";

		for (vector<string>::const_iterator iter = it->second.begin(); iter != it->second.end(); ++iter) {
			cout << " " << *iter;
		}
		cout << endl;
	}
}