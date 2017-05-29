// chapter6.4.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iterator> // add iterator

using namespace std;

int main()
{
	vector<int> u(10, 100); // u contains 10 times 100 (size = 10)
	vector<int> v; // initialize a vector v (empty)
	//copy(u.begin(), u.end(), v.begin()); // try to copy u into v

	// correction
	// 1. use back_inserter that yields an iterator on the container v
	copy(u.begin(), u.end(), back_inserter(v));

	//2. use inserter that inserts elements before the iterator (second argument of the fct)
	//copy(u.begin(), u.end(), inserter(v, v.end()));

	return 0;
}
