/*****************************************************************
//
//  NAME:        David Pavlicek
//
//  HOMEWORK:    10
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 4, 2022
//
//  FILE:        Squirtle.cpp
//
//  DESCRIPTION:
//   Holds the function definitions for the Squirtle class.
//
//  REFERENCES:
//   Homework 10 webpage
//
****************************************************************/

#include <iostream>
#include "Squirtle.h"

/*****************************************************************
//
//  Function name: Squirtle::Squirtle
//
//  DESCRIPTION:   Constructor for the Squirtle class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

Squirtle::Squirtle()
{
    type = "Water";
    weight = 19.8;
    std::cout << "Squirtle Constructor" << std::endl << std::endl;
}

/*****************************************************************
//
//  Function name: Squirtle::~Squirtle
//
//  DESCRIPTION:   Destructor for the Squirtle class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

Squirtle::~Squirtle()
{
    std::cout << "Squirtle Destructor" << std::endl;
}

/*****************************************************************
//
//  Function name: Squirtle::printData
//
//  DESCRIPTION:   Prints the data for the Squirtle class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

void Squirtle::printData()
{
    std::cout << "Squirtle" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Weight: " << weight << std::endl << std::endl;
}
