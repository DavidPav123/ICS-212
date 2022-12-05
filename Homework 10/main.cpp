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
//  DATE:        December 4th 2022
//
//  FILE:        main.cpp
//
//  DESCRIPTION:
//   Main file for Homework 10 that executes the creation of Pokemon objects
//   and prints their data.
//
//  REFERENCES:
//   Websites used:
//      https://cplusplus.com/reference/vector/vector/vector/
//      https://en.cppreference.com/w/cpp/container/vector
//      https://en.cppreference.com/w/cpp/container/map
//      http://www.cplusplus.com/reference/map/map/
//
****************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Pokemon.h"
#include "Squirtle.h"

using namespace std;

void checkPokedex(Pokemon* pokemon);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Executes the creation of Pokemon objects and 
//                 prints their data.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : exited successfully
//
****************************************************************/

int main(int argc, char* argv[])
{
    Pokemon* pokemon[3];
    long unsigned int i;

    pokemon[0] = new Squirtle();
    pokemon[1] = new Charmander();
    pokemon[2] = new Bulbasaur();

    vector<string> nicknames;
    nicknames.push_back("Squirt");
    nicknames.push_back("Charm");
    nicknames.push_back("Bulb");

    map <string, Pokemon*> Pokedex;
    for (i = 0; i < 3; i++)
    {
        Pokedex[nicknames[i]] = pokemon[i];
    }

    for (i = 0; i < nicknames.size(); i++)
    {
        cout << "Calling Key: " << nicknames[i] << endl;
        checkPokedex(Pokedex[nicknames[i]]);
    }

    for (i = 0; i < 3; i++)
    {
        delete pokemon[i];
    }

    return 0;
}

/*****************************************************************
//
//  Function name: checkPokedex
//
//  DESCRIPTION:   Prints the data of a Pokemon object.
//
//  Parameters:    pokemon (Pokemon*) : The pokemons object to print data of.
//
//  Return values:  none
//
****************************************************************/

void checkPokedex(Pokemon* pokemon)
{
    pokemon->printData();
}
