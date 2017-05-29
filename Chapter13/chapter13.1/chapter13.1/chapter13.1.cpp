// chapter13.1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Core.h"
#include "Grad.h"
#include "Student_info.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

	// test Q13.1
	Core c1; // Call default constructor of Core
	Grad g1; // Call defaut constructor of Core and then default constructor of Grad

	Core c2(cin); // Call constructor (that takes one arg) of Core
	Grad g2(cin); // Call defaut constructor of Core and then constructor (that takes one arg) of Grad

	system("pause");
	return 0;
}

