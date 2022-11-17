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
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//   Holds the code for allowing a user to interact with the database
//
//  REFERENCES:
//   Textbook sections
//
****************************************************************/
#include "llist.h"
#include <iostream>
#include <fstream>

using namespace std;

void getaddress(char[], int);

int debugmode = 0;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : number of command line arguments
//                 argv (char**) : array of command line arguments
//
//  Return values: 0 : success
//                -1 : failure
//
****************************************************************/

int main(int argc, char* argv[])
{
    int accountNum, whileLoop, accountLoop, checkReturn;
    char name[30], address[60], usrInput[10];
    struct record* start = NULL;
    whileLoop = 1;

    if (argc == 2)
    {
        if (strcmp(argv[1], "debug") != 0)
        {
            cout << "Invalid input" << endl;
            return -1;
        }
        else
        {
            debugmode = 1;
        }
    }
    else if (argc > 2)
    {
        cout << "Invalid input" << endl;
        return -1;
    }

    llist* database = new llist("database.txt");

    cout << "The following program will allow for adding, removing, finding, and printing of record from a bank database." << endl;

    while ( whileLoop == 1)
    {
        cout << "Please enter one of the following commands:" << endl;
        cout << "add: adds a record to the database" << endl;
        cout << "print: prints all records in the database" << endl;
        cout << "find: finds a record in the database" << endl;
        cout << "delete: deletes a record from the database" << endl;
        cout << "quit: quits the program" << endl;
        cout << "Option Selection:" << endl;
        
        accountLoop = 1;
        cin >> usrInput;

        if (strncmp(usrInput, "add", strlen(usrInput) - 1) == 0 && strlen(usrInput) > 0)
        {
            cout << "Please enter the account number: ";
            cin >> accountNum;
            cout << "Please enter the name: ";
            cin >> name;
            cout << "Please enter the address: ";
            getaddress(address, 60);
            database->addRecord(accountNum, name, address);
        }
        else if (strcmp(usrInput, "printall") == 0)
        {
            database->printAllRecords();
        }
        else if (strcmp(usrInput, "find") == 0)
        {
            cout << "Please enter the account number: ";
            cin >> accountNum;
            checkReturn = database->findRecord(accountNum);
            if (checkReturn == -1)
            {
                cout << "Record not found" << endl;
            }
        }
        else if (strcmp(usrInput, "delete") == 0)
        {
            cout << "Please enter the account number: ";
            cin >> accountNum;
            checkReturn = database->deleteRecord(accountNum);
            if (checkReturn == -1)
            {
                cout << "Record not found" << endl;
            }
        }
        else if (strcmp(usrInput, "quit") == 0)
        {
            whileLoop = 0;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}





