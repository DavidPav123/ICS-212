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
#include <string.h>
#include <cstdlib> 

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
    int returnVal, accountNumber;
    char name[30], address[60];
    ifstream File("filename.txt", std::ifstream::in);

    if (File.is_open())
    {
        while (File.good())
        {
            File >> accountNumber;
            File >> name;
            File >> address;
            addRecord(accountNumber, name, address);
        }
        returnVal = 0;
    }
    else
    {
        returnVal = -1;
    }
    File.close();

    return returnVal;
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
    ofstream File("filename.txt", std::ifstream::out);
    struct record* writeTarget, * next;
    int returnVal;
    writeTarget = start;

    if (File.is_open())
    {
        while (writeTarget != NULL && next != NULL)
        {
            next = writeTarget->next;

            File << writeTarget->accountno << endl;
            File << writeTarget->name << endl;
            File << writeTarget->address << "/f" << endl;

            writeTarget = next;
        }
        returnVal = 0;
    }
    else
    {
        returnVal = -1;
    }
    File.close();

    return returnVal;
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
    struct record* cleanupTarget, * next;
    cleanupTarget = start;

    while (cleanupTarget != NULL && next != NULL)
    {
        next = cleanupTarget->next;
        delete cleanupTarget;
        cleanupTarget = next;
    }

    start = NULL;
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

void getaddressfromfile(char addressArr[], int maxLen, std::ifstream& File)
{
    char tempArr[100];
    int currentLen = 0, whileLoop = 1;

    while (currentLen < maxLen && whileLoop == 1)
    {
        File.get(tempArr[currentLen]);

        if (currentLen > 0 && tempArr[currentLen - 1] == 'f' && tempArr[currentLen - 2] == '/')
        {
            tempArr[currentLen - 1] = ' ';
            tempArr[currentLen - 2] = '\0';
            whileLoop = 0;
        }

        currentLen++;
    }
    strcpy(addressArr, tempArr);
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
    writefile();
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

void llist::addRecord(int accountNumber, char name[], char address[])
{
    struct record* temp, * tempNext, * tempNextNext, * uacc;
    int tempNextAccNum;

    uacc = (struct record*)malloc(sizeof(struct record));

    if (debugmode == 1)
    {
        cout << "Name of called function: addRecord" << endl;
        cout << "Paramaters: struct record * database, int accountNumber, "
            "char * name, and char * address, with values:" << endl;
        cout << "accountNumber: ";
        cout << accountNumber << endl;
        cout << "name: ";
        cout << name;
        cout << "address: " << endl;
        cout << address << endl << endl;
    }

    uacc->accountno = accountNumber;
    strcpy(uacc->name, name);
    strcpy(uacc->address, address);

    if (start == NULL)
    {
        uacc->next = NULL;
        start = uacc;
    }
    else
    {
        temp = start;
        tempNext = temp->next;
        tempNextAccNum = temp->accountno;

        if (accountNumber > tempNextAccNum)
        {
            uacc->next = temp;
            start = uacc;
        }
        else if (tempNext == NULL)
        {
            temp->next = uacc;
            uacc->next = NULL;
        }
        else
        {
            tempNextNext = tempNext->next;
            tempNextAccNum = tempNext->accountno;

            while (tempNextNext != NULL && accountNumber > tempNextAccNum)
            {
                temp = tempNext;
                tempNext = tempNextNext;
                tempNextNext = tempNextNext->next;
                tempNextAccNum = tempNext->accountno;
            }

            if (tempNextNext == NULL && accountNumber > tempNextAccNum)
            {
                tempNext->next = uacc;
                uacc->next = NULL;
            }
            else
            {
                temp->next = uacc;
                uacc->next = tempNext;
            }
        }
    }
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

int llist::findRecord(int accountNumber)
{
    struct record* temp;
    int returnVal, tempNextAccNum;

    temp = start;

    if (debugmode == 1)
    {
        cout << "Name of called function: findRecord" << endl;
        cout << "Parameters: struct record * database and int accountNumber, "
            "with accountNumber value: " << accountNumber << endl << endl;
    }

    if (start != NULL)
    {
        tempNextAccNum = temp->accountno;
        while (temp != NULL && tempNextAccNum != accountNumber)
        {
            temp = temp->next;
            if (temp != NULL)
            {
                tempNextAccNum = temp->accountno;
            }
        }
        if (tempNextAccNum == accountNumber)
        {
            returnVal = 0;
            while (temp != NULL && tempNextAccNum == accountNumber)
            {
                cout << endl << temp->accountno << endl << temp->name << endl << temp->address << endl;
                temp = temp->next;
                if (temp != NULL)
                {
                    tempNextAccNum = temp->accountno;
                }
            }
        }
        else
        {
            returnVal = -1;
        }
    }

    return returnVal;
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
    struct record* temp;
    temp = start;

    if (debugmode == 1)
    {
        cout << "Name of called function: printAllRecords" << endl;
        cout << "Paramaters: none" << endl;
    }

    while (temp != NULL)
    {
        cout << temp->accountno << temp->name << temp->address << endl;
        temp = temp->next;
    }
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

int llist::deleteRecord(int accountNumber)
{
    struct record* temp, * tempNext;
    int tempNextAccNum, returnVal;

    if (debugmode == 1)
    {
        cout << "Name of called function: deleteRecord" << endl;
        cout << "Paramaters: struct record * database and int accountNumber, "
            "with accountNumber value: " << accountNumber << endl << endl;
    }

    returnVal = -1;
    if (start != NULL)
    {

        temp = start;
        tempNext = temp->next;
        tempNextAccNum = temp->accountno;

        if (tempNextAccNum == accountNumber)
        {
            if (tempNext == NULL)
            {
                start = NULL;
                returnVal = 0;
            }
            else
            {
                while (temp != NULL && tempNextAccNum == accountNumber)
                {
                    temp = temp->next;
                    if (temp != NULL)
                    {
                        tempNextAccNum = temp->accountno;
                    }
                }
                start = temp;
                returnVal = 0;
            }
        }
        else
        {
            tempNextAccNum = tempNext->accountno;
            while (tempNext != NULL && accountNumber != tempNextAccNum)
            {
                temp = temp->next;
                tempNext = tempNext->next;
                if (tempNext != NULL)
                {
                    tempNextAccNum = tempNext->accountno;
                }
            }
            if (tempNext != NULL)
            {
                while (tempNext != NULL && tempNextAccNum == accountNumber)
                {
                    tempNext = tempNext->next;
                    if (tempNext != NULL)
                    {
                        tempNextAccNum = tempNext->accountno;
                    }
                }
                temp->next = tempNext;
                returnVal = 0;
            }
        }
    }

    return returnVal;
}
