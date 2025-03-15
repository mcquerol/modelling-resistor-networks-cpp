#include <iostream>
#include <cstdlib>

#include "ResistorPart.h"
#include "SeriesResistorConnection.h"
#include "Resistor.h"
using namespace std;

int main ()
{
	/* test 1 Create a ResistorPart object */
	ResistorPart r("R1", 42, 5);
	cout << r << endl;

	cout << endl;
	/* test 2 Series connection */
    std::shared_ptr<Resistor> r3 = std::make_shared<ResistorPart>("R3", 1000, 10);
    std::shared_ptr<Resistor> r4 = std::make_shared<ResistorPart>("R4", 4700, 10);

    // Create a serial resistor connection named R2
    SerialResistorConnection conn1("R2");

    // Add R3 and R4 to the serial connection
    conn1 += r3;
    conn1 += r4;

    // Print the connection name
    std::cout << conn1.getName() << std::endl;
	return 0;
}
