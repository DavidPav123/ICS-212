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
//  FILE:        Bulbasaur.h
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//   List references used here
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