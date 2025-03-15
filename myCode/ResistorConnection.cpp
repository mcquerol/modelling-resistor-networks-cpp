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
		connectionName = Resistor::getName() + "[";

		for(const auto& resistor : resistors)
		{

			connectionName += resistor->getName();
			connectionName += separator();
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
