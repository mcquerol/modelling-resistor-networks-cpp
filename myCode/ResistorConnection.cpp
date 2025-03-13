/*
 * ResistorConnection.cpp
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#include "ResistorConnection.h"
#include <string>

ResistorConnection::ResistorConnection(std::string name) : Resistor(name)
{
}

std::string ResistorConnection::getName() const
{
	return "";
}

ResistorConnection& ResistorConnection::operator +=(const std::shared_ptr<Resistor> &resistor)
{
	return *this;
}
