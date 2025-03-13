/*
 * ParallelResistorConnection.h
 *
 *  Created on: 13 Mar 2025
 *      Author: mateo
 */

#ifndef PARALLELRESISTORCONNECTION_H_
#define PARALLELRESISTORCONNECTION_H_

#include "ResistorConnection.h"

#include <string>

class ParallelResistorConnection : public ResistorConnection
{
public:
    ParallelResistorConnection(std::string name);

    char separator() const;

    float nominalValue() const;
    float minimumValue() const;
    float maximumValue() const;
};

#endif /* PARALLELRESISTORCONNECTION_H_ */
