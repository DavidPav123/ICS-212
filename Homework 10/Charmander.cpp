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
//  FILE:        Charmander.cpp
//
//  DESCRIPTION:
//   Holds the function definitions for the Charmander class.
//
//  REFERENCES:
//   Homework 10 webpage
//
****************************************************************/

#include <iostream>
#include "Charmander.h"

/*****************************************************************
//
//  Function name: Charmander::Charmander
//
//  DESCRIPTION:   Constructor for the Charmander class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

Charmander::Charmander()
{
    type = "Fire";
    weight = 18.7;
    std::cout << "Charmander Constructor" << std::endl<< std::endl;
}

/*****************************************************************
//
//  Function name: Charmander::~Charmander
//
//  DESCRIPTION:   Destructor for the Charmander class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

Charmander::~Charmander()
{
    std::cout << "Charmander Destructor" << std::endl;
}

/*****************************************************************
//
//  Function name: Charmander::printData
//
//  DESCRIPTION:   Prints the data for the Charmander class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

void Charmander::printData()
{
    std::cout << "Charmander" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Weight: " << weight << std::endl << std::endl;
}
