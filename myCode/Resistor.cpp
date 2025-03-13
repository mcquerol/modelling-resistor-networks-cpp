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

std::string Resistor::toString()
{
	return name;
}
