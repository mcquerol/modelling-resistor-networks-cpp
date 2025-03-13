/*
 * ResistorPart.cpp
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#include "ResistorPart.h"
#include <string>

ResistorPart::ResistorPart(std::string name, float value, float tolerance) : Resistor{name}, value{value}, tolerance{tolerance}
{
}

float ResistorPart::nominalValue() const
{
	return value;
}

float ResistorPart::minimumValue() const
{
	return value * (1 - tolerance);
}

float ResistorPart::maximumValue() const
{
	return value * (1 + tolerance);
}
