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

// Generate recursively the sentence
void gen_aux(const Grammar& g, const string& word, list<string>& v) {

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
		// fetch the et of possible rules
		const Rule_collection& c = it->second;

		// select one at random
		const Rule& r = c[nrand(c.size())];

		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
			gen_aux(g, *i, v);
		}
	}
}

// Generate the sentence
list<string> gen_sentence(const Grammar& g) {
	list<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

// display sentence
void display_gensen(const list<string>& vec) {
	list<string>::const_iterator it = vec.begin();

	while (it != vec.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}