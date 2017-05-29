// chapter7.9.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int nrand(int n);

int nrand_aux(int n) {
	const int bucket_size = n % RAND_MAX == 0 ? n / RAND_MAX : n / RAND_MAX + 1;
	int r;
	do {
		r = (nrand(bucket_size) + 1) * RAND_MAX;
	} while (r >= n);

	return r;
}

// generate a random integer in range [0, n[
int nrand(int n) {
	if (n <= 0 || n > RAND_MAX)
		return nrand_aux(n);

	const int bucket_size = RAND_MAX / n; // bucket of same size
	int r;

	do {
		// represent a random number corresponding to the nb of the bucket
		// in which r resides.
		r = rand() / bucket_size;
	} while ( r >= n ); // if r is too high (cannot be in any bucket) we loop

	return r;
}

int main()
{
	srand(time(NULL));
	int range = 200000 + 1.0; // RAND_MAX is 37768; INT_MAX is 2147483647
	int random_nb = nrand(range);

	cout << "number is: " << random_nb << endl;

	system("pause");
    return 0;
}

