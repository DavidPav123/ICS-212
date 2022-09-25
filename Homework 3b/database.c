/*****************************************************************
//
//  NAME:        David Pavlicek
//
//  HOMEWORK:    3B
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 24th, 2022
//
//  FILE:        database.c
//
//  DESCRIPTION:
//   Holds the function definitions for the database functions
//   called by the user interface
//
//  REFERENCES:
//   Textbook section 4.5
//
****************************************************************/

#include <stdio.h>
#include "record.h"

extern int debugmode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a record to the databse
//
//  Parameters:    database (struct record **): a pointer to a database record pointer
//                 accountNumber (int) : an integer holding an account number
//                 address (char *) : a pointer to a character array holding an address
//                 name (char *) : a pointer to a character array holding an account name
//
//  Return values:  void
//
****************************************************************/

void addRecord(struct record * database, int accountNumber, char * name, char * address)
{
    if (debugmode == 1)
    {
        printf("Name of called function: addRecord\n");
        printf("Paramaters: struct record * database, int accountNumber, "
        "char * name, and char * address, with values:\n");
        printf("accountNumber: ");
        printf("%d\n", accountNumber);
        printf("name: ");
        printf("%s\n", name);
        printf("address: ");
        printf("%s\n\n", address);
    }
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   prints all records in the database
//
//  Parameters:    database (struct record *) : a pointer to a database
//
//  Return values:  void
//
****************************************************************/

void printAllRecords(struct record * database)
{
    if (debugmode == 1)
    {
        printf("Name of called function: printAllRecords\n");
        printf("Paramaters: struct record * database\n\n");
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds record that matchs specified account number
//
//  Parameters:    database (struct record *) : a pointer to a database
//                 accountNumber (int) : an account number 
//
//  Return values:  1 : function ran
//
****************************************************************/

int findRecord(struct record * database, int accountNumber)
{
    if (debugmode == 1)
    {
        printf("Name of called function: findRecord\n");
        printf("Paramaters: struct record * database and int accountNumber, "
        "with accountNumber value: ");
        printf("%d\n\n", accountNumber);
    }

    return 1;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    database (struct record *) : a pointer to a database
//                 accountNumber (int) : an account number 
//
//  Return values:  1 : function ran
//
****************************************************************/

int deleteRecord(struct record * database, int accountNumber)
{
    if (debugmode == 1)
    {
        printf("Name of called function: deleteRecord\n");
        printf("Paramaters: struct record * database and int accountNumber, "
        "with accountNumber value: ");
        printf("%d\n\n", accountNumber);
    }
    return 1;
}
