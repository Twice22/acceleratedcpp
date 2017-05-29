// chapter10.2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <class T, class Iterator>
T median(Iterator b, Iterator e) {
	if (b == e)
		throw domain_error("median of an empty array");

	// can't do 
	// size_t size = sizepf(b) / sizeof(*b);
	// can't do 
	// sort(e, b)
	// because it would have change the order of the element in the array
	// which we don't want!

	// use vector instead
	vector<T> temp;
	for (; b != e; ++b) {
		temp.push_back(*b);
	}

	// don't forget to sort
	sort(temp.begin(), temp.end());

	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = temp.size();
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (temp[mid] + temp[mid-1]) / 2 : temp[mid];
}


int main()
{
	vector<double> vdouble{ 14.7, 78.9 ,58.6, 45.6, 46.5 };
	vector<int> vint{ 15, 79 ,59, 45, 46 };

	cout << "vector: median[double]: " << median<double>(vdouble.begin(), vdouble.end()) << endl;
	cout << "vector: median[int]: " << median<int>(vint.begin(), vint.end()) << endl;

	double adouble[] = { 14.7, 78.9, 58.6, 45.6, 46.5 };
	int aint[] = { 15, 79 ,59, 45, 46 };

	size_t size_ad = sizeof(adouble) / sizeof(*adouble);
	size_t size_ai = sizeof(aint) / sizeof(*aint);

	cout << "array: median[double]: " << median<double>(adouble, adouble + size_ad) << endl;
	cout << "array: median[int]: " << median<int>(aint, aint + size_ai) << endl;

	// Answer to Q10.3 (ensure elements are still in the same order)
	for (size_t i = 0; i < size_ad; ++i) {
		cout << adouble[i] << " ";
	}
	cout << endl;

	for (vector<int>::const_iterator it = vint.begin(); it != vint.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

