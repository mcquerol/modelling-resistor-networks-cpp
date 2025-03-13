/*
 * SeriesResistorConnection.h
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#ifndef SERIALRESISTORCONNECTION_H_
#define SERIALRESISTORCONNECTION_H_

#include "ResistorConnection.h"

class SerialResistorConnection : public ResistorConnection
{
public:
    SerialResistorConnection(std::string name);

    char separator() const;

    float nominalValue() const;
    float minimumValue() const;
    float maximumValue() const;
};

#endif /* SERIALRESISTORCONNECTION_H_ */
