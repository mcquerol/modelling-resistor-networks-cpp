/*
 * Resistor.cpp
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#include "Resistor.h"
#include <string>

Resistor::Resistor(std::string name) : name{name}
{
}

Resistor::~Resistor()
{
}

std::string Resistor::getName() const
{
	return name;
}

std::string Resistor::toString() const
{
	return name + " = " + std::to_string(nominalValue()) + " Ohm";
}

std::ostream& operator<<(std::ostream& out, const Resistor& resistor)
{
	out << resistor.toString();
	return out;
}

void Resistor::write(std::ostream &out)
{
	 out << name << ';' << nominalValue() << ';' << (maximumValue() - nominalValue()) / nominalValue();
}
