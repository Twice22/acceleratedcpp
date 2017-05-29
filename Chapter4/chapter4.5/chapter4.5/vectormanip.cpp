#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "vectormanip.h"

using namespace std;

void display(vector<string> list) {
	// no copy because we sort it
	vect_sz size = list.size();

	sort(list.begin(), list.end());

	int j = 0, c = 0;
	for (vect_sz i = 0; i < size; i += c) {
		j = i + 1;
		c = 1;
		while (j < size && list[j] == list[i]) {
			++c; ++j;
		}
		cout << list[i] << " appears " << c << endl;
	}
}