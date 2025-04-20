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
		cout << "Line is : " << nameStr << " " << nominalValue << " " << tolerance << endl;

		if(nameStr.find('[') != string::npos) // resistorconnection object
		{
			size_t openBracket = nameStr.find('[');   // index of '['
			size_t closeBracket = nameStr.find(']');  // index of ']'
			string connectionName = nameStr.substr(0, openBracket);
			string inside = nameStr.substr(openBracket + 1, closeBracket - openBracket - 1);

			if(inside.find('-') != string::npos) // series connection
			{
				SerialResistorConnection s(inside);
				cout << "series " << inside << " " << __LINE__ << endl;
			}
			else
			{
				ParallelResistorConnection p(inside); // parallel connection
				cout << "parallel " << inside << " " << __LINE__ << endl;
			}
		}
		else //resistor part object
		{
			ResistorPart r(nameStr, nominalValue, tolerance);
			ResistorPtr rPtr = std::make_shared<ResistorPart>(r);
		}
	}
}
