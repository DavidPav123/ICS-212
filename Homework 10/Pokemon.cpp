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
//  FILE:        Pokemon.cpp
//
//  DESCRIPTION:
//   Holds the function definitions for the Pokemon class.
//
//  REFERENCES:
//   Homework 10 webpage
//
****************************************************************/

#include <iostream>
#include "Pokemon.h"

/*****************************************************************
//
//  Function name: Pokemon::Pokemon
//
//  DESCRIPTION:   Constructor for the Pokemon class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

Pokemon::Pokemon()
{
    std::cout << "Pokemon Constructor" << std::endl;
}

/*****************************************************************
//
//  Function name: Pokemon::~Pokemon
//
//  DESCRIPTION:   Destructor for the Pokemon class.
//
//  Parameters:    none
//
//  Return values:  none
//
****************************************************************/

Pokemon::~Pokemon()
{
    std::cout << "Pokemon Destructor" << std::endl << std::endl;
}
