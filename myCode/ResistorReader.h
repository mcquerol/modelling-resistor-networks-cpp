/*
 * ResistorReader.h
 *
 *  Created on: 16 Apr 2025
 *      Author: Mateo C. Querol
 */

#ifndef RESISTORREADER_H_
#define RESISTORREADER_H_

#include <istream>
#include <string>
#include <map>
#include <memory>

#include "Resistor.h"

class ResistorReader
{

public:
	void read(std::istream& in, std::map<std::string, ResistorPtr>& found);
};

#endif /* RESISTORREADER_H_ */
