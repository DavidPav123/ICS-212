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
//  DATE:        September 3, 2112
//
//  FILE:        Squirtle.h
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//   List references used here
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