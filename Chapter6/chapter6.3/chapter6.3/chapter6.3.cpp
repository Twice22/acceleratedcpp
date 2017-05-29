// chapter6.3.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>

using namespace std;

int main()
{
	vector<int> u(10, 100); // u contains 10 times 100 (size = 10)
	vector<int> v; // initialize a vector v (empty)
	copy(u.begin(), u.end(), v.begin()); // try to copy u into v

    return 0;
}

