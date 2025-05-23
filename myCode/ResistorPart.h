/*
 * ResistorPart.h
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#ifndef RESISTORPART_H_
#define RESISTORPART_H_

#include <string>
#include "Resistor.h"

class ResistorPart : public Resistor
{

private:
	float value;
	float tolerance;

public:
	ResistorPart(std::string name, float value, float tolerance);

	float nominalValue() const;
	float minimumValue() const;
	float maximumValue() const;

	static ResistorPtr from(std::string line);
};

#endif /* RESISTORPART_H_ */
