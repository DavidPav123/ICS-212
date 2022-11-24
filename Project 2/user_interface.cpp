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
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void getaddress(char[], int);

#ifdef DEBUG
    int debugmode = 1;
#else
    int debugmode = 0;
#endif

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
    int accountNum, whileLoop, accountLoop;
    std::string tempString;
    char name[30], address[60], usrInput[10];
    whileLoop = 1;

    llist* database = new llist();

    cout << "The following program will allow for adding, removing, finding, and printing of record from a bank database." << endl;

    while (whileLoop == 1)
    {
        cout << "Please enter one of the following commands:" << endl;
        cout << "add: adds a record to the database" << endl;
        cout << "print: prints all records in the database" << endl;
        cout << "find: finds a record in the database" << endl;
        cout << "delete: deletes a record from the database" << endl;
        cout << "exit: exits the program" << endl << endl;
        cout << "Option Selection:" << endl;

        accountLoop = 1;
        cin >> usrInput;

        if (strncmp(usrInput, "add", strlen(usrInput)) == 0 && strlen(usrInput) > 0)
        {
            cout << "Enter account number:" << endl;
            while (accountLoop == 1)
            {
                if (!(cin >> accountNum))
                {
                    while (getchar() != '\n');
                    cout << "Input was not a number. Please enter a positive Integer." << endl << endl;
                }
                else
                {
                    if (accountNum < 0)
                    {
                        cout << "Input was not a positive number. Please enter a positive Integer." << endl << endl;
                    }
                    else
                    {
                        while (getchar() != '\n');
                        accountLoop = 0;
                    }
                }
            }

            cout << "Enter name:" << endl;
            std::getline(std::cin, tempString);
            tempString.push_back('\n');
            strcpy(name, tempString.c_str());

            getaddress(address, 60);

            database->addRecord(accountNum, name, address);
        }
        else if (strncmp(usrInput, "printall", strlen(usrInput)) == 0 && strlen(usrInput) > 0)
        {
            database->printAllRecords();
        }
        else if (strncmp(usrInput, "find", strlen(usrInput)) == 0 && strlen(usrInput) > 0)
        {
            cout << "Enter account number:" << endl;
            while (accountLoop == 1)
            {
                if (!(cin >> accountNum))
                {
                    while (getchar() != '\n');
                    cout << "Input was not a number. Please enter a positive Integer." << endl << endl;
                }
                else
                {
                    if (accountNum < 0)
                    {
                        cout << "Input was not a positive number. Please enter a positive Integer." << endl << endl;
                    }
                    else
                    {
                        while (getchar() != '\n');
                        accountLoop = 0;
                    }
                }
            }

            if (database->findRecord(accountNum) == -1)
            {
                cout << endl << "Record not found" << endl;
            }
        }
        else if (strncmp(usrInput, "delete ", strlen(usrInput)) == 0 && strlen(usrInput) > 0)
        {
            cout << "Enter account number:" << endl;
            while (accountLoop == 1)
            {
                if (!(cin >> accountNum))
                {
                    while (getchar() != '\n');
                    cout << "Input was not a number. Please enter a positive Integer." << endl << endl;
                }
                else
                {
                    if (accountNum < 0)
                    {
                        cout << "Input was not a positive number. Please enter a positive Integer." << endl << endl;
                    }
                    else
                    {
                        while (getchar() != '\n');
                        accountLoop = 0;
                    }
                }
            }
            if (database->deleteRecord(accountNum) == -1)
            {
                cout << endl << "Record not found" << endl;
            }
            else
            {
                cout << endl << "Record succesfully deleted" << endl << endl;
            }
        }
        else if (strncmp(usrInput, "exit", strlen(usrInput)) == 0 && strlen(usrInput) > 0)
        {
            database->~llist();
            whileLoop = 0;
        }
        else
        {
            cout << "Unknow option, please enter a valid option" << endl << endl;
        }
    }
    return 0;
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   Accepts users input of their address unil they
//                 enter the terminating character /f
//
//  Parameters:    adressArr (char *) : stores a pointer to the array the address is store in
//                 maxLen (int) : store the maximum number characters a user can enter
//
//  Return values:  void
//
****************************************************************/

void getaddress(char addressArr[], int maxLen)
{
    char tempArr[100];
    int currentLen = 0, whileLoop = 1;

    if (debugmode == 1)
    {
        cout << "Name of called function: getaddress" << endl;
        cout << "Parameters: char * addressArr and int maxLen, with maxLen value of " << maxLen << endl;
    }

    cout << "Enter your address, when done enter /f:" << endl;

    while (currentLen < maxLen && whileLoop == 1)
    {
        tempArr[currentLen] = getchar();

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
