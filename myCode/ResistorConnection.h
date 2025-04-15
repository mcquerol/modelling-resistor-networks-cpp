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
#include <ostream>

#include "Resistor.h"

class ResistorConnection : public Resistor
{
protected:
    std::list<std::shared_ptr<Resistor>> resistors;

public:
    ResistorConnection(std::string name);

    virtual char separator() const;

    std::string getName() const;

    ResistorConnection& operator+=(const std::shared_ptr<Resistor>& resistor);

    void write(std::ostream& out);
};
#endif /* RESISTORCONNECTION_H */
