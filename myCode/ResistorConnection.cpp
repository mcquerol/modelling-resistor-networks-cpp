/*
 * ResistorConnection.cpp
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#include "ResistorConnection.h"
#include <string>

using namespace std;

ResistorConnection::ResistorConnection(std::string name) : Resistor(name)
{
}

std::string ResistorConnection::getName() const
{
	string connectionName;

	if(resistors.empty())
	{
		connectionName = Resistor::getName();
	}
	else
	{
		connectionName += Resistor::getName() + "[";
        auto it = resistors.begin();  // Get the first element
        connectionName += (*it)->getName();  // Add first resistor's name
        ++it;  // Move to next element

		while (it != resistors.end()) // Iterate through the rest
		{
			connectionName += separator();  // Add separator before each resistor
			connectionName += (*it)->getName();
			++it;
		}
		connectionName += "]";
	}
	return connectionName;
}

ResistorConnection& ResistorConnection::operator +=(const std::shared_ptr<Resistor> &resistor)
{
	resistors.emplace_back(resistor);
	return *this;
}

char ResistorConnection::separator() const
{
	return ',';
}

void ResistorConnection::write(std::ostream &out)
{
	for(const auto &resistor: resistors)
	{

		resistor->write(out);
		out << endl;
	}
	out << getName() << ';' << nominalValue() << ';' << ( (maximumValue() - nominalValue()) / nominalValue()) << endl;
}
