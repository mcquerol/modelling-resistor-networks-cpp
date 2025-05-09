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
#include <ostream>

class Resistor
{


private:
	std::string name;
public:
	Resistor(std::string name);
	virtual ~Resistor();

	std::string getName() const;

	virtual float nominalValue() const = 0;
	virtual float minimumValue() const = 0;
	virtual float maximumValue() const = 0;

	virtual std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const Resistor& resistor);

	void write(std::ostream& out);
};
typedef std::shared_ptr<Resistor> ResistorPtr;

#endif /* RESISTOR_H_ */
