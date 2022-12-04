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
#include "Charmander.h"

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

Charmander::Charmander()
{
    type = "Fire";
    weight = 18.7;
    std::cout << "Charmander Constructor" << std::endl;
}

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

Charmander::~Charmander()
{
    std::cout << "Charmander Destructor" << std::endl;
}

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

void Charmander::printData()
{
    std::cout << "Charmander" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Weight: " << weight << std::endl;
}