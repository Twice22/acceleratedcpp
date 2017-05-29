// chapter11.5.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

#include "grade.h"
#include "Student_info.h"

using namespace std;

void test() {
	// copy 
	Student_info std1 = Student_info(cin);

	// create
	Student_info std2;

	// assign
	std2 = std1;

	// copy
	Student_info std3(std2);

	// return and destroy (3 instances of Student_info ==> 3 destroys!)

}

int main()
{

	test();
	system("pause");
	return 0;
}

