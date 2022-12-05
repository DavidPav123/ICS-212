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
//  FILE:        Charmander.h
//
//  DESCRIPTION:
//   Holds the function prototypes for the Charmander class.
//
//  REFERENCES:
//   Webpages used:
//      https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c
//      https://www.ibm.com/docs/en/zos/2.4.0?topic=only-virtual-functions-c
//
****************************************************************/

#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "Pokemon.h"

class Charmander : public Pokemon
{
public:
    Charmander();
    virtual ~Charmander();
    void printData();
};

#endif
