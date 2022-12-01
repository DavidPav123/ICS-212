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

#include "Bulbasaur.h"
#include "Charmander.h"
#include "Pokemon.h"
#include "Squirtle.h"

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

int main(int argc, char* argv[])
{
    Pokemon* pokemon[3];
    pokemon[0] = new Squirtle();
    pokemon[1] = new Charmander();
    pokemon[2] = new Bulbasaur();
}
