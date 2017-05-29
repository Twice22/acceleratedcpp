#include "stdafx.h"
#include "sengen.h"
#include "split.h"
#include <iostream>

using namespace std;

// Reading the grammar
Grammar read_grammar(istream& in) {

	Grammar ret;
	string line;

	while (getline(in, line)) {

		vector<string> wl = split(line);

		if (!wl.empty()) {
			ret[wl[0]].push_back(Rule(wl.begin() + 1, wl.end()));
		}
	}
	return ret;
}

// predicate that return True if the word is bracketed
bool isbracketed(const string& s) {
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// generate a random integer in range [0, n[
int nrand(int n) {
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = RAND_MAX / n; // bucket of same size
	int r;

	do {
		// represent a random number corresponding to the nb of the bucket
		// in which r resides.
		r = rand() / bucket_size;
	} while (r >= n); // if r is too high (cannot be in any bucket) we loop

	return r;
}

// Answer to Q7.8
// Generate the sentence using 2 vector (one as a stack to avoid recursive calls)
void gen_aux(const Grammar& g, const string& word, vector<string>& v, vector<string>& rules) {

	if (!isbracketed(word)) {
		v.push_back(word);
	}
	else {
		// if we do g[word] and word isn't in g it will
		// create it so we need to use g.find() (that returns g.end() if word is not find)
		Grammar::const_iterator it = g.find(word);

		// if the category doesn't exist
		if (it == g.end())
			throw logic_error("empty rule");

		// it->second is the value of the grammar g
		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		// select one at random
		const Rule& r = c[nrand(c.size())];

		// Push in reverse order to have the sentence in the right order
		// need to change the type to const_reverse_iterator
		for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i) {
			rules.push_back(*i);
		}
	}
}

// Answer to Q7.8
// Generate the sentence
vector<string> gen_sentence(const Grammar& g) {
	vector<string> ret, rules;
	rules.push_back("<sentence>");
	
	while (!rules.empty()) {
		string token = rules.back();
		rules.pop_back();
		gen_aux(g, token, ret, rules);
	}

	return ret;
}

// display sentence
void display_gensen(const vector<string>& vec) {
	vector<string>::const_iterator it = vec.begin();

	while (it != vec.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}