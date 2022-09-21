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
//  DATE:        September 3, 2112
//
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//   List references used here 
//
****************************************************************/

#include <stdio.h>
#include "database.h"

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
    struct record * start = NULL;
    char input;
    int option, accountNum, whileLoop;

    whileLoop = 1;

    printf("Here is the introduction text");
    printf("Here is the desription text");

    while(whileLoop == 1)
    {

        scanf("%c", &input);
        printf("%c",input);

        if ( option == 1) 
        {
            //addRecord();
        }
        else if (option == 2) 
        {
            printAllRecords(start);
        }
        else if (option == 3) 
        {
            scanf("%d", &accountNum);

            findRecord(start, accountNum);
        }
        else if ( option == 4 ) 
        {
            scanf("%d", &accountNum);

            deleteRecord(start, accountNum);
        }
        else if (option == 5) 
        {
            whileLoop = 0;
        }
        else 
        {
            printf("Unknow option, please enter a valid option");
        }
    }
}