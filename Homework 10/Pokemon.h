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
//  FILE:        Pokemon.h
//
//  DESCRIPTION:
//   Holds the function prototypes for the Pokemon class.
//
//  REFERENCES:
//   Webpages used:
//      https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c
//      https://www.ibm.com/docs/en/zos/2.4.0?topic=only-virtual-functions-c
//
****************************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
protected:
    std::string type;
    float weight;

public:
    Pokemon();
    virtual ~Pokemon();
    virtual void printData() = 0;
};

#endif
