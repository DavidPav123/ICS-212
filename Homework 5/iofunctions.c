/*****************************************************************
//
//  NAME:        David Pavlicek
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 8th, 2022
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION:
//   Holds the function defintions for the readfile and writefile functions
//
//  REFERENCES:
//    Textbook sections 6.2, 6.3, 6.4, 7.5
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "pokemon.h"

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   reads the pokemon provided in the array and 
//                 writes their deconstructed components into 
//                 the file specified by filename
//
//  Parameters:    pokearray (struct pokemon []) : Holds the pokemons
//                                   whos levels and names are written in
//                                   the file named filename
//                 num (int) : length of the array
//                 filename (char []) : name of the file to be written to 
//
//  Return values:  0 : file was opened and read succesfully
//                 -1 : file failed to open
//
****************************************************************/

int writefile(struct pokemon pokearray[], int num, char filename[])
{
    FILE *fptr;
    int i;

    fptr = fopen(filename, "w+");

    if (fptr == NULL)
    {
        return -1;
    }

    for (i = 0; i < num; i++)
    {
        printf("Writing data from pokemon in array position ");
        printf("%d\n", i);
        fprintf(fptr, "%d\n", pokearray[i].level);
        printf("Pokemon level: ");
        printf("%d\n", pokearray[i].level);
        fprintf(fptr, "%s\n", pokearray[i].name);
        printf("Pokemon name: ");
        printf("%s\n", pokearray[i].name);
    }
    fclose(fptr);

    return 0;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads levels and names of pokemon from a file 
//                 and puts them into the provided array. Also
//                 puts length of array into num.
//
//  Parameters:    pokearray (struct pokemon []) : holds the pokemon 
//                                        that were read from the file
//                 num (int *) : a pointer that will hold the length of the array
//                 filename (char []) : name of the file to be read from
//
//  Return values:  0 : file was opened and read succesfully
//                 -1 : file failed to open
//
****************************************************************/

int readfile(struct pokemon pokearray[], int *num, char filename[])
{
    FILE *fptr;
    char name[30];
    int level, loopTracker, maxLen;
    struct pokemon addPokemon;

    fptr = fopen(filename, "r");
    loopTracker = 0;
    maxLen = *num;

    if (fptr == NULL)
    {
        return -1;
    }

    while ((fscanf(fptr, "%d", &level) != EOF) && (loopTracker < maxLen))
    {
        printf("%s%d\n", "Reading data of pokemon number ", loopTracker);

        fgets(name, 100, fptr);
        fgets(name, 100, fptr);

        printf("Pokemon level: ");
        printf("%d\n", level);
        addPokemon.level = level;

        printf("Pokemon name: ");
        printf("%s", name);
        strcpy(addPokemon.name, name);

        pokearray[loopTracker] = addPokemon;

        loopTracker++;
    }
    fclose(fptr);

    *num = loopTracker;
    return 0;
}
