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

#include <vector>
#include <map>
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
    int i;
    pokemon[0] = new Squirtle();
    pokemon[1] = new Charmander();
    pokemon[2] = new Bulbasaur();

    vector <string> nicknames = { "Squirt", "Charm", "Bulb" };

    map <string, Pokemon*> Pokedex = {
        {"Squirt", pokemon[0]},
        {"Charm", pokemon[1]},
        {"Bulb", pokemon[2]}
    };

    for (i = 0; i < nicknames.size(); i++)
    {
        checkPokedex(Pokedex[nicknames[i]]);
    }

    for (i = 0; i < 3; i++)
    {
        delete pokemon[i];
    }
}

/*****************************************************************
//
//  Function name: checkPokedex
//
//  DESCRIPTION:   Prints the name of the given pokemon
//
//  Parameters:    pokemon (Pokemon*) : The pokemons name to check
//
//  Return values:  none
//
****************************************************************/

void checkPokedex(Pokemon* pokemon)
{
    pokemon->printData();
}
