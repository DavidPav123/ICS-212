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
//  FILE:        Bulbasaur.cpp
//
//  DESCRIPTION:
//   Holds the function definitions for the Bulbasaur class.
//
//  REFERENCES:
//   Homework 10 webpage
//
****************************************************************/

#include <iostream>
#include "Bulbasaur.h"

/*****************************************************************
//
//  Function name: Bulbasaur::Bulbasaur
//
//  DESCRIPTION:   Constructor for the Bulbasaur class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

Bulbasaur::Bulbasaur()
{
    type = "Grass";
    weight = 15.2;
    std::cout << "Bulbasaur Constructor" << std::endl << std::endl;
}

/*****************************************************************
//
//  Function name: Bulbasaur::~Bulbasaur
//
//  DESCRIPTION:   Destructor for the Bulbasaur class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

Bulbasaur::~Bulbasaur()
{
    std::cout << "Bulbasaur Destructor" << std::endl;
}

/*****************************************************************
//
//  Function name: Bulbasaur::printData
//
//  DESCRIPTION:   Prints the data for the Bulbasaur class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

void Bulbasaur::printData()
{
    std::cout << "Bulbasaur" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Weight: " << weight << std::endl << std::endl;
}