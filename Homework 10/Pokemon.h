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
//  FILE:        Pokemon.h
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//   List references used here
//
****************************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
protected:
    std::string type; // e.g., electric, poison, etc
    float weight;

public:
    Pokemon();
    virtual ~Pokemon();
    virtual void printData();
};

#endif
