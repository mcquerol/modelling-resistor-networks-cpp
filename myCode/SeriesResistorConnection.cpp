/*
 * SeriesResistorConnection.cpp
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#include "SeriesResistorConnection.h"
#include <string>

SerialResistorConnection::SerialResistorConnection(std::string name) : ResistorConnection(name)
{
}

char SerialResistorConnection::separator() const
{
	return ' ';
}

float SerialResistorConnection::nominalValue() const
{
	return 0.0;
}

float SerialResistorConnection::minimumValue() const
{
	return 0.0;
}

float SerialResistorConnection::maximumValue() const
{
	return 0.0;
}
