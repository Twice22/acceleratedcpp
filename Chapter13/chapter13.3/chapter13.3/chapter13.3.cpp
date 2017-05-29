// chapter13.3.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Grad.h"
#include "Core.h"
#include "Student_info.h"

using namespace std;

int main()
{
	Student_info s(cin);


	// if G (Graduate student), s.valid() is true if you submit
	// more than 3 grades. For U (Undergraduate) s.valid() is true if nb_grades > 2
	if (s.valid()) {
		cout << "This student has done homework" << endl;
	}
	else {
		cout << "This student hasn't done any homework" << endl;
	}

	system("pause");
    return 0;
}

