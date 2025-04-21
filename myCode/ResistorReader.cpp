/*
 * ResistorReader.cpp
 *
 *  Created on: 16 Apr 2025
 *      Author: Mateo C. Querol
 */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "ResistorReader.h"
#include "ResistorPart.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"


void ResistorReader::read(std::istream &in, std::map<std::string, ResistorPtr> &found)
{

    string text, nameStr, nominalValueStr, toleranceStr;
    float nominalValue = 0.0f;
    float tolerance = 0.0f;

    while(getline(in, text))
    {
		istringstream iss(text);
		getline(iss, nameStr, ';');
		getline(iss, nominalValueStr, ';');
		nominalValue = std::stof(nominalValueStr);
		getline(iss, toleranceStr, '\n');
		tolerance = std::stof(toleranceStr);

		size_t openBracket = nameStr.find('[');   // index of '['
		size_t closeBracket = nameStr.find(']');  // index of ']'
		string connectionName = nameStr.substr(0, openBracket);

		if(nameStr.find('[') != string::npos) // resistorconnection object
		{
			string inside = nameStr.substr(openBracket + 1, closeBracket - openBracket - 1);


			if(inside.find('-') != string::npos) // series connection
			{
				size_t separator = inside.find('-');
				string firstResistorPart = inside.substr(0, separator);
				string secondResistorPart = inside.substr(separator + 1);
				SerialResistorConnection sConn(connectionName);
				sConn += found[firstResistorPart];
				sConn += found[secondResistorPart];
				ResistorPtr rConnPtr = std::make_shared<SerialResistorConnection>(sConn);
				found.emplace(connectionName, rConnPtr); //add connection to map
				found.erase(firstResistorPart); //remove first resistor from map
				found.erase(secondResistorPart); //remove second resistor from map
			}
			else
			{
				size_t separator = inside.find('|');
				string firstResistorPart = inside.substr(0, separator);
				string secondResistorPart = inside.substr(separator + 1);
				ParallelResistorConnection pConn(connectionName); // parallel connection
				pConn += found[firstResistorPart];
				pConn += found[secondResistorPart];
				ResistorPtr rConnPtr = std::make_shared<ParallelResistorConnection>(pConn);
				found.emplace(connectionName, rConnPtr);
				found.erase(firstResistorPart); //remove first resistor from map
				found.erase(secondResistorPart); //remove second resistor from map
			}
		}
		else //resistor part object
		{
			ResistorPart r(connectionName, nominalValue, tolerance);
			ResistorPtr rPtr = std::make_shared<ResistorPart>(r);
			found.emplace(connectionName, rPtr);
		}
	}
}
