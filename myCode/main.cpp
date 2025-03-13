#include <iostream>
#include <cstdlib>

#include "ResistorPart.h"
#include "Resistor.h"
using namespace std;

int main ()
{

//	Resistor r = new ResistorPart("R1", 42, 5);
//	cout << r;

	ResistorPart r("R1", 42, 5);  // Create a ResistorPart object
	std::cout << r << std::endl;   // Calls Resistor::toString() dynamically


	return 0;
}
