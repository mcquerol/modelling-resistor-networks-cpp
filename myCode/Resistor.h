/*
 * Resistor.h
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_

#include <string>
#include <memory>

typedef std::shared_ptr<Resistor> ResistorPtr;
class Resistor
{

private:
	std::string name;
public:
	Resistor(std::string name);
	virtual ~Resistor();

	std::string getName();

	virtual float nominalValue() const = 0;
	virtual float minimumValue() const = 0;
	virtual float maximumValue() const = 0;

	std::string toString();
};
#endif /* RESISTOR_H_ */
