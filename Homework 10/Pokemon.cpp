/*****************************************************************
//
//  NAME:        Ravi Narayan
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 3, 2112
//
//  FILE:        template.c
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//   List references used here 
//
****************************************************************/

#include <iostream>
#include "Pokemon.h"

Pokemon::Pokemon(){
    std::cout << "Pokemon Constructor" << std::endl;
}

Pokemon::~Pokemon(){
    std::cout << "Pokemon Destructor" << std::endl;
}
