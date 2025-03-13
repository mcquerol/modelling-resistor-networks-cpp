/*
 * ResistorConnection.h
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#ifndef RESISTORCONNECTION_H_
#define RESISTORCONNECTION_H_

#include <list>
#include <memory>
#include <string>

#include "Resistor.h"

class ResistorConnection : public Resistor
{
protected:
    std::list<std::shared_ptr<Resistor>> resistors;

public:
    ResistorConnection(std::string name);

    char separator() const;

    std::string getName() const;

    ResistorConnection& operator+=(const std::shared_ptr<Resistor>& resistor);
};
#endif /* RESISTORCONNECTION_H */
