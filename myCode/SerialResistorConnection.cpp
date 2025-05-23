/*
 * SeriesResistorConnection.cpp
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#include "SerialResistorConnection.h"

#include <string>

SerialResistorConnection::SerialResistorConnection(std::string name) : ResistorConnection(name)
{
}

char SerialResistorConnection::separator() const
{
	return '-';
}

float SerialResistorConnection::nominalValue() const
{
	float nominalValueSum = 0.0f;
	if(resistors.empty())
	{
		return 0.0f;
	}
	for(const auto& resistor : resistors)
	{
		nominalValueSum += resistor->nominalValue();
	}

	return nominalValueSum;
}

float SerialResistorConnection::minimumValue() const
{
	float minimumValueSum = 0.0f;
	if(resistors.empty())
	{
		return 0.0f;
	}
	for(const auto& resistor : resistors)
	{
		minimumValueSum += resistor->minimumValue();
	}

	return minimumValueSum;
}

float SerialResistorConnection::maximumValue() const
{
	float maximumValueSum = 0.0f;
	if(resistors.empty())
	{
		return 0.0f;
	}
	for(const auto& resistor : resistors)
	{
		maximumValueSum += resistor->maximumValue();
	}

	return maximumValueSum;
}
