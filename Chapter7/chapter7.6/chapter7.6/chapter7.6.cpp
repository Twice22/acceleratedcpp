// chapter7.6.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "split.h"
#include "sengen.h"

#include <iostream>
#include <ctime>
#include <cstdlib>  // add srand

using namespace std;

int main()
{
	// 7.4
	srand(time(NULL)); // seed for randomness
	vector<string> sentence = gen_sentence(read_grammar(cin));

	// it can display weird phrase with lots of adjectives if we pass the lines
	// defined in sengen.h. For example:
	// the brown large brown absurd brown large cat jumps on the stairs
	display_gensen(sentence);

	system("pause");
	return 0;
}

