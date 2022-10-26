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
#include <string.h>
#include "record.h"

extern int debugmode;

void getaddressfromfile(char [], int, FILE*);

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

void addRecord(struct record **database, int accountNumber, char name[ ], char address[ ])
{
    struct record * temp, *tempNext, *tempNextNext, *uacc, *start;

    int tempNextAccNum;

    start = *database;

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

    uacc->accountno = accountNumber;
    strcpy(uacc->name, name);
    strcpy(uacc->address, address);

    /*if (database == NULL)
    {
        uacc->next = NULL;
        start = uacc;
    }
    else {
        temp = start;
        tempNext = start->next;
        tempNextAccNum = start->accountno;

        if ( accountNumber > tempNextAccNum )
        {
            uacc->next = temp;
            start = uacc;
        }
        else if ( tempNext == NULL)
        {
            start->next = uacc;
            uacc->next = NULL;
        }
        else 
        {
            tempNextNext = tempNext->next;
            tempNextAccNum = tempNext->accountno;

            while (accountNumber < tempNextAccNum && tempNextNext != NULL)
            {
                temp = temp->next;
                tempNext = tempNext->next;
                tempNextNext = tempNextNext->next;
                tempNextAccNum = tempNext->accountno;
            }

            if (accountNumber > tempNextAccNum)
            {
                temp->next = uacc;
                uacc->next = tempNext;
            }
            else 
            {
                tempNext->next = uacc;
                uacc->next = NULL;
            }
        }
    }*/

}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all records in the database
//
//  Parameters:    database (struct record *) : a pointer to a database
//
//  Return values:  void
//
****************************************************************/

void printAllRecords(struct record * database)
{
    struct record * temp;
    temp = database;

    if (debugmode == 1)
    {
        printf("Name of called function: printAllRecords\n");
        printf("Paramaters: struct record * database\n\n");
    }

    while (temp != NULL) 
    {
        printf("%d\n%s\n%s\n\n", temp->accountno, temp->name, temp->address);
        temp = temp->next;
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds record that matchs specified account number
//
//  Parameters:    database (struct record *) : a pointer to a database
//                 accountNumber (int) : the account number of the 
//                                       record to be found
//
//  Return values:  0 : record was succesfully found
//                  -1 : record was not succesfully found
//
****************************************************************/

int findRecord(struct record * database, int accountNumber)
{
    struct record * temp;
    int returnVal;

    temp = database;

    if (debugmode == 1)
    {
        printf("Name of called function: findRecord\n");
        printf("Paramaters: struct record * database and int accountNumber, "
        "with accountNumber value: ");
        printf("%d\n\n", accountNumber);
    }

    while (temp != NULL && temp->accountno != accountNumber)
    {
        temp = temp->next;
    }

    if (temp->accountno == accountNumber)
    {
        returnVal = 0;
        while (temp->accountno == accountNumber)
        {
            printf("%d\n%s\n%s\n\n", temp->accountno, temp->name, temp->address);
            temp = temp->next;
        }
    }
    else 
    {
        returnVal = -1;
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   deletes the records with the specified account number
//
//  Parameters:    database (struct record *) : a pointer to a database
//                 accountNumber (int) : an account number 
//
//  Return values:  0 : record was succesfully deleted
//                  -1 : record was not succesfully deleted
//
****************************************************************/

int deleteRecord(struct record * database, int accountNumber)
{
    struct record * temp, *tempNext, *tempNextNext;
    int tempNextAccNum, returnVal;

    if (debugmode == 1)
    {
        printf("Name of called function: deleteRecord\n");
        printf("Paramaters: struct record * database and int accountNumber, "
        "with accountNumber value: ");
        printf("%d\n\n", accountNumber);
    }

    returnVal = -1;

    if (database != NULL)
    {
        temp = database;
        tempNext = database->next;
        tempNextAccNum = database->accountno;

        if (tempNextAccNum == accountNumber)
        {
            if (tempNext == NULL)
            {
                database = NULL;
                returnVal = 0;
            }
            else 
            {
                while (tempNextAccNum == accountNumber && temp != NULL)
                {
                    temp = temp->next;
                    tempNextAccNum = temp->accountno;
                }
                database = temp;
                returnVal = 0;
            }
        }
        else 
        {
            tempNextAccNum = tempNext->accountno;
            while (accountNumber != tempNextAccNum && tempNext != NULL)
            {
                temp = temp->next;
                tempNext = tempNext->next;
                if (tempNext != NULL)
                {
                    tempNextNext = tempNextNext->next;
                    tempNextAccNum = tempNext->accountno;
                }
                else 
                {
                    tempNextNext = NULL;
                }
            }
            if ( tempNext != NULL )
            {
                while (tempNextAccNum == accountNumber && tempNext != NULL)
                {
                    tempNext = tempNext->next;
                }
                temp->next = tempNext;
                returnVal = 0;
            }
        }
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    database (struct record **) : a pointer to a database
//                 filename (char []) : name of the file to be writen to
//
//  Return values:  0 : file was opened and read succesfully
//                 -1 : file failed to open
//
****************************************************************/

int writefile(struct record * database, char filename[])
{
    FILE *fptr;
    struct record *writeTarget, *next;
    writeTarget = database;

    fptr = fopen(filename, "w+");

    if (fptr == NULL)
    {
        return -1;
    }

    while (writeTarget != NULL && next != NULL)
    {
        next = writeTarget->next;

        fprintf(fptr, "%d\n", writeTarget->accountno);
        fprintf(fptr, "%s\n", writeTarget->name);
        fprintf(fptr, "%s%s\n", writeTarget->address, "/f");

        writeTarget = next;
    }
    fclose(fptr);

    return 0;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    database (struct record **) : a pointer to a database
//                 filename (char []) : name of the file to be read
//
//  Return values:  0 : file was opened and read succesfully
//                 -1 : file failed to open
//
****************************************************************/

int readfile(struct record ** database, char filename[])
{
    struct record *current, *previous;
    FILE *fptr;
    int accountNumber;
    char name[30], address[60];
    current = *database;
    previous = NULL;

    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        return -1;
    }

    while ((fscanf(fptr, "%d", &accountNumber) != EOF))
    {
        fgets(name, 30, fptr);
        getaddressfromfile(address, 60, fptr);

        current->accountno = accountNumber;
        strcpy(current->name, name);
        strcpy(current->address, address);

        if (previous != NULL)
        {
            previous->next = current;
        }
        
        previous = current;
    }
    fclose(fptr);

    return 0;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    database (struct record **) : a pointer to a database
//
//  Return values:  none
//
****************************************************************/

void cleanup(struct record ** database)
{
    database = NULL;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    database (struct record **) : a pointer to a database
//
//  Return values:  none
//
****************************************************************/


void getaddressfromfile(char addressArr[], int maxLen, FILE* fptr)
{
    int currentLen = 0, whileLoop = 1;

    while(currentLen < maxLen && whileLoop == 1)
    {
        addressArr[currentLen] = fgetc(fptr);

        if(currentLen > 0 && addressArr[currentLen - 1] == 'f' && addressArr[currentLen - 2] == '/'){
            addressArr[currentLen - 1] = ' ';
            addressArr[currentLen - 2] = ' ';
            whileLoop = 0;
        }

        currentLen++;
    }

}
