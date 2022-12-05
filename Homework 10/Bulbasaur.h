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
//  FILE:        Bulbasaur.h
//
//  DESCRIPTION:
//   Holds the function prototypes for the Bulbasaur class.
//
//  REFERENCES:
//   Webpages used:
//      https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c
//      https://www.ibm.com/docs/en/zos/2.4.0?topic=only-virtual-functions-c
//
****************************************************************/

#ifndef BULBASAUR_H
#define BULBASAUR_H

#include "Pokemon.h"

class Bulbasaur : public Pokemon
{
public:
    Bulbasaur();
    virtual ~Bulbasaur();
    void printData();
};

#endif