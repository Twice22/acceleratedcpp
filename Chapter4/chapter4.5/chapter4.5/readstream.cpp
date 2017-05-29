#include "stdafx.h"
#include "readstream.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

vector<string> read_w(istream& in) {
	string word;
	vector<string> wordlist;

	while (in >> word)
		wordlist.push_back(word);

	in.clear();

	return wordlist;
}