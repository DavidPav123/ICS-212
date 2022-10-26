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
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//   Holds the code for allowing a user to interact with the database 
//
//  REFERENCES:
//   Textbook sections 7.4, 7.7, B1.4, B3
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"

void getaddress (char [], int);

int debugmode = 0;


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
//  Return values: 0 : program was called with exit command and exited succesfully
//                 -1 : program was called with invalid arguments
//
****************************************************************/

int main(int argc, char* argv[])
{
    struct record * start = NULL;
    int accountNum, whileLoop = 1, accountLoop, checkReturn;
    char name[30], address[60], input;
    struct record first;

    if(argc == 2)
    {
        if(strcmp(argv[1], "debug") != 0)
        {
            printf("Invalid input\n");
            return -1;
        }
        else
        {
            debugmode = 1;
        }
    }
    else if (argc > 2)
    {
        printf("Invalid input\n");
        return -1;
    }

    start = &first;
    readfile(&start, "record.txt");

    printf("The following program will allow for adding, removing, finding, and printing of record from a bank database.\n\n");
    
    while(whileLoop == 1)
    {
        printf("Please enter one of the following menu options:\n");
        printf("add: adds a record to the databse\n");
        printf("printall: prints all records in the database\n");
        printf("find: finds a record in the database\n");
        printf("delete: deletes a record from the database\n");
        printf("exit: exits the program\n\n");
        printf("Option Selection:\n");

        accountLoop = 1;
        fgets(&input, 10, stdin);

        if(strncmp(&input,"add",strlen(&input) - 1) == 0 && strlen(&input) > 0)
        {
            getaddress(address, 60);

            printf("Enter account number:\n");
            while(accountLoop == 1)
            {
                checkReturn = scanf("%d", &accountNum);

                if (checkReturn != 1)
                {
                    while (getchar() != '\n');
                    printf("Input was not a number. Please enter a positive Integer.\n\n");
                }
                else
                {
                    if (accountNum < 0)
                    {
                        printf("Input was not positive. Please enter a positive Integer.\n\n");
                    }
                    else 
                    {
                        while (getchar() != '\n');
                        accountLoop = 0;    
                    }
                }
            }
        
            printf("Enter name:\n");
            fgets(name, 30, stdin);

            addRecord(&start, accountNum, name, address);
        }
        else if(strncmp(&input,"printall",strlen(&input) - 1) == 0 && strlen(&input) > 0)
        {
            printAllRecords(start);
        }
        else if(strncmp(&input,"find",strlen(&input) - 1) == 0 && strlen(&input) > 0)
        {
            printf("Enter account number:\n");
            while(accountLoop == 1)
            {
                checkReturn = scanf("%d", &accountNum);

                if (checkReturn != 1)
                {
                    while (getchar() != '\n');
                    printf("Input was not a number. Please enter a positive Integer.\n\n");
                }
                else
                {
                    if (accountNum < 0)
                    {
                        printf("Input was not positive. Please enter a positive Integer.\n\n");
                    }
                    else 
                    {
                        while (getchar() != '\n');
                        accountLoop = 0;    
                    }
                }
            }

            findRecord(start, accountNum);
        }
        else if(strncmp(&input,"delete ",strlen(&input) - 1) == 0 && strlen(&input) > 0)
        {
            printf("Enter account number:\n");
            while(accountLoop == 1)
            {
                checkReturn = scanf("%d", &accountNum);

                if (checkReturn != 1)
                {
                    while (getchar() != '\n');
                    printf("Input was not a number. Please enter a positive Integer.\n\n");
                }
                else
                {
                    if (accountNum < 0)
                    {
                        printf("Input was not positive. Please enter a positive Integer.\n\n");
                    }
                    else 
                    {
                        while (getchar() != '\n');
                        accountLoop = 0;    
                    }
                }
            }

            deleteRecord(&start, accountNum);
        }
        else if(strncmp(&input,"exit",strlen(&input) - 1) == 0 && strlen(&input) > 0)
        {
            writefile(start, "records.txt");
            cleanup(&start);
            whileLoop = 0;
        }
        else 
        {
            printf("Unknow option, please enter a valid option\n\n");
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

void getaddress(char addressArr [], int maxLen) 
{
    int currentLen = 0, whileLoop = 1;

    if(debugmode == 1)
    {
        printf("Name of called function: getaddress\n");
        printf("Paramaters: char * addressArr and int maxLen, with maxLen value of ");
        printf("%d\n\n", maxLen);
    }

    printf("Enter your address, when done enter /f:\n");

    while(currentLen < maxLen && whileLoop == 1)
    {
        addressArr[currentLen] = fgetc(stdin);

        if(currentLen > 0 && addressArr[currentLen - 1] == 'f' && addressArr[currentLen - 2] == '/')
        {
            addressArr[currentLen - 1] = ' ';
            addressArr[currentLen - 2] = ' ';
            whileLoop = 0;
        }

        currentLen++;
    }
}
