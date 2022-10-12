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

#include <stdio.h>
#include <string.h>
#include "pokemon.h"
#include "iofunctions.h"

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Makes calls to the writefile and readfile functions to show that they work
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : main exited succesfully
//
****************************************************************/

int main(int argc, char* argv[])
{
    struct pokemon pokemonbank[5];
    struct pokemon pokeDex[5];

    int numpokemons, funcReturn;

    struct pokemon Charmander;
    struct pokemon Squirtle;
    struct pokemon Bulbasaur;
    struct pokemon Turtwig;
    struct pokemon Hitmonchamp;

    Charmander.level = 4;
    strcpy(Charmander.name, "Charmander");
    Squirtle.level = 27;
    strcpy(Squirtle.name, "Squirtle");
    Bulbasaur.level = 100;
    strcpy(Bulbasaur.name, "Bulbasaur");
    Turtwig.level = 16;
    strcpy(Turtwig.name, "Turtwig");
    Hitmonchamp.level = 86;
    strcpy(Hitmonchamp.name, "Hitmonchamp");

    pokemonbank[0] = Charmander;
    pokemonbank[1] = Squirtle;
    pokemonbank[2] = Bulbasaur;
    pokemonbank[3] = Hitmonchamp;
    pokemonbank[4] = Turtwig;

    numpokemons = 5;

    printf("Calling function writefile with an array of 5 pokemon "
    "and writing to file test_file.txt\n\n");

    funcReturn = writefile(pokemonbank, numpokemons, "test_file.txt");

    printf("\nwritefile returned ");
    printf("%d", funcReturn);

    if (funcReturn == 0)
    {
        printf(" indicating the file was opened and written to sucesfully\n\n");
    }
    else if (funcReturn == -1)
    {
        printf(" indicating the file was not succesfully opened\n\n");
    }

    numpokemons = 7;

    printf("Calling function readfile with a max array size of 7 pokemon "
    "and reading from file test_file.txt\n\n");

    readfile(pokeDex, &numpokemons, "test_file.txt");

    printf("\n%s%d", "Number of pokemon read from file: ", numpokemons);

    printf("\nreadfile returned ");
    printf("%d", funcReturn);

    if (funcReturn == 0)
    {
        printf(" indicating the file was opened and read from sucesfully\n\n");
    }
    else if (funcReturn == -1)
    {
        printf(" indicating the file was not succesfully opened\n\n");
    }

    numpokemons = 3;

    printf("Calling function readfile with a max array size of 3 pokemon "
    "and reading from file test_file.txt\n\n");

    readfile(pokeDex, &numpokemons, "test_file.txt");

    printf("\n%s%d", "Number of pokemon read from file: ", numpokemons);

    printf("\nreadfile returned ");
    printf("%d", funcReturn);

    if (funcReturn == 0)
    {
        printf(" indicating the file was opened and read from sucesfully\n\n");
    }
    else if (funcReturn == -1)
    {
        printf(" indicating the file was not succesfully opened\n\n");
    }

    return 0;
}
