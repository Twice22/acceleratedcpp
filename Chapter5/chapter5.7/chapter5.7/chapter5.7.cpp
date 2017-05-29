// chapter5.7.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "framing.h"

using namespace std;

int main()
{
	// Answer to Q5.7
	/*
	Doing this will call the function frame and execute all the instruction from frame
	but won't display anything as we don't intercept the return value from frame (moreover
	we have indicated that the frame function won't change the value passed as a reference,
	because we are using const)
	*/
	//vector<string> v;
	//frame(v);

	// to correct the code we can either intercept the return value like this:
	// or even better erase the const from the frame function and work directly on the input
	//vector<string> v;
	//v = frame(v);

	// moreover if v is empty the frame function will still create the upper and lower
	// border and so will return:
	// ****
	// ****

	vector<string> v;
	vector<string> ret = frame(v);
	for (vector<string>::size_type i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	system("pause");
	return 0;
}


