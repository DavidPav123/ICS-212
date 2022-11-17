/*****************************************************************
//
//  NAME:        David Pavlicek
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 16th, 2022
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This file contains the function definitions for the llist class.
//
//  REFERENCES:
//   Textbook sections
//
****************************************************************/

#include "llist.h"
#include <iostream>
#include <fstream>

using namespace std;

extern int debugmode;

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:  Reads the file and adds the records to the linked list
//
//  Parameters:    none
//
//  Return values:  0 : success
//                 -1 : failure
//
****************************************************************/

int llist::readfile()
{

}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:  Writes the linked list to a file
//
//  Parameters:    none
//
//  Return values:  0 : success
//                 -1 : failure
//
****************************************************************/

int llist::writefile()
{

}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:  Frees all memory allocated to the linked list
//
//  Parameters:    none
//
//  Return values:  void
//
****************************************************************/

void llist::cleanup()
{

}

/*****************************************************************
//
//  Function name: getaddressfromfile
//
//  DESCRIPTION:  Gets the address from the file
//
//  Parameters:    adressArr (char *) : stores a pointer to the array the address is store in
//                 maxLen (int) : store the maximum number characters a user can enter
//                 file (ifstream &) : stores a reference to the file being read from
//
//  Return values:  void
//
****************************************************************/

void getaddressfromfile(char addressArr[], int maxLen, std::ifstream& file)
{

}

/*****************************************************************
//
//  Function name: list
//
//  DESCRIPTION:   Default constructor for the llist class
//
//  Parameters:    none
//
//  Return values:  void
//
****************************************************************/

llist::llist()
{
    start = NULL;
}

/*****************************************************************
//
//  Function name: list
//
//  DESCRIPTION:   Constructor for the llist class
//
//  Parameters:    file (char []) : stores the name of the file to be read from
//
//  Return values:  void
//
****************************************************************/

llist::llist(char file[])
{
    start = NULL;
    strcpy(filename, file);
    readfile();
}

/*****************************************************************
//
//  Function name: ~list
//
//  DESCRIPTION:   Destructor for the llist class
//
//  Parameters:    none
//
//  Return values:  void
//
****************************************************************/

llist::~llist()
{
    cleanup();
}

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a record to the database
//
//  Parameters:    adressArr (char *) : stores a pointer to the 
//                                      array the address is store in
//                 maxLen (int) : store the maximum number 
//                                characters a user can enter
//
//  Return values:  void
//
****************************************************************/

void llist::addRecord(int maxLen, char[], char[])
{

}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds a record in the database
//
//  Parameters:    accountno (int) : stores the account number 
//                                   of the record to be found
//
//  Return values:  void
//
****************************************************************/

int llist::findRecord(int accountno)
{

}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all records in the database
//
//  Parameters:    none
//
//  Return values:  void
//
****************************************************************/

void llist::printAllRecords()
{

}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Deletes a record from the database
//
//  Parameters:    accountno (int) : stores the account number of 
//                                   the record to be deleted
//
//  Return values:  void
//
****************************************************************/

int llist::deleteRecord(int accountno)
{

}
