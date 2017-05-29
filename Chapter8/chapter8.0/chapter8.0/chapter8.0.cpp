// chapter8.1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <class T>
T median(vector<T> v) {
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

bool not_space(char c) {
	return !isspace(c);
}

bool space(char c) {
	return isspace(c);
}

template <class Out>
void split(const string& s, Out out) {
	typedef string::const_iterator iter;

	iter b = s.begin();

	while (b != s.end()) {
		b = find_if(b, s.end(), not_space);

		iter after = find_if(b, s.end(), space);

		if (b != s.end()) {
			// write word to the current pos in the container
			*out++ = string(b, after);
			b = after;
		}
	}
}

int main()
{
	vector<double> vdouble{ 14.7, 78.9 ,58.6, 45.6, 46,5 };
	vector<int> vint{ 15, 79 ,59, 45, 46 };

	cout << "median[int]: " << median(vint) << endl;
	cout << "median[double]: " << median(vdouble) << endl;

	list<string> word_list;

	string s;
	while (getline(cin, s)) {
		split(s, back_inserter(word_list));
	}

	// display words in word_list
	typedef list<string>::const_iterator iter;
	for (iter it = word_list.begin(); it != word_list.end(); ++it) {
		cout << *it << " ";
	}

	cout << endl;

	system("pause");
    return 0;
}

