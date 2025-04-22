/*
 * ResistorPart.cpp
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#include "ResistorPart.h"
#include <string>
#include <sstream>

using namespace std;

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

ResistorPtr ResistorPart::from(std::string line)
{
    string text, nameStr, nominalValueStr, toleranceStr;
    float nominalValue;
    float tolerance;

	istringstream iss(line);
	getline(iss, nameStr, ';');
	getline(iss, nominalValueStr, ';');
	nominalValue = std::stof(nominalValueStr);
	getline(iss, toleranceStr, '\n');
	tolerance = std::stof(toleranceStr);

	ResistorPart r(nameStr, nominalValue, tolerance);
	ResistorPtr rPtr = std::make_shared<ResistorPart>(r);
	return rPtr;
}
