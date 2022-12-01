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
//  FILE:        Charmander.h
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//   List references used here
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