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
	return '|';
}

float ParallelResistorConnection::nominalValue() const
{
	float nominalValueSum = 0.0f;
	if(resistors.empty())
	{
		return 0.0f;
	}
	for(const auto& resistor : resistors)
	{
		nominalValueSum += (1/resistor->nominalValue());
	}

	return 1/nominalValueSum;
}

float ParallelResistorConnection::minimumValue() const
{
	float minimumValueSum = 0.0f;
	if(resistors.empty())
	{
		return 0.0f;
	}
	for(const auto& resistor : resistors)
	{
		minimumValueSum += (1/resistor->minimumValue());
	}

	return 1/minimumValueSum;
}

float ParallelResistorConnection::maximumValue() const
{
	float maximumValueSum = 0.0f;
	if(resistors.empty())
	{
		return 0.0f;
	}
	for(const auto& resistor : resistors)
	{
		maximumValueSum += (1/resistor->maximumValue());
	}

	return 1/maximumValueSum;
}
