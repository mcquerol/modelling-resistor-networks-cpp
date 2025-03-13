/*
 * ParallelResistorConnection.cpp
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#include "ParallelResistorConnection.h"
#include <string>

ParallelResistorConnection::ParallelResistorConnection(std::string name) : ResistorConnection(name)
{
}

char ParallelResistorConnection::separator() const
{
	return ' ';
}

float ParallelResistorConnection::nominalValue() const
{
	return 0.0;
}

float ParallelResistorConnection::minimumValue() const
{
	return 0.0;
}

float ParallelResistorConnection::maximumValue() const
{
	return 0.0;
}
