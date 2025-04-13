#include <iostream>
#include <cstdlib>

#include "ResistorPart.h"
#include "SeriesResistorConnection.h"
#include "ParallelResistorConnection.h"
#include "Resistor.h"
using namespace std;

int main ()
{
	/* test 1 Create a ResistorPart object */
	ResistorPart r("R1", 1000, 5);
	cout << r << endl;

	/* test 2 Series connection */
    std::shared_ptr<Resistor> r3 = std::make_shared<ResistorPart>("R3", 1000, 0.1);
    std::shared_ptr<Resistor> r4 = std::make_shared<ResistorPart>("R4", 4700, 0.1);

    // Create a serial resistor connection named R2
    SerialResistorConnection conn1("R2");

    // Add R3 and R4 to the serial connection
    conn1 += r3;
    conn1 += r4;
    // Print the connection name
    cout << conn1.getName() << endl;
    cout << conn1 <<endl;

    /* test 3 Parallel connection */
    std::shared_ptr<Resistor> r6 = std::make_shared<ResistorPart>("R6", 1000, 0.1);
    std::shared_ptr<Resistor> r7 = std::make_shared<ResistorPart>("R7", 4700, 0.1);

    // Create a serial resistor connection named R2
    ParallelResistorConnection conn2("R5");

    // Add R6 and R7 to the serial connection
    conn2 += r6;
    conn2 += r7;
    // Print the connection name
    cout << conn2.getName() << endl;
    cout << conn2 << endl;

	return 0;
}
