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
//  FILE:        Squirtle.h
//
//  DESCRIPTION:
//   Holds the function definitions for the Squirtle class.
//
//  REFERENCES:
//   Webpages used:
//      https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c
//      https://www.ibm.com/docs/en/zos/2.4.0?topic=only-virtual-functions-c
//
****************************************************************/

#ifndef SQUIRTLE_H
#define SQUIRTLE_H

#include "Pokemon.h"

class Squirtle : public Pokemon
{
public:
    Squirtle();
    virtual ~Squirtle();
    void printData();
};

#endif