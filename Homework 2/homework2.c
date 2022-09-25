/*****************************************************************
//
//  NAME:        David Palicek
//
//  HOMEWORK:    2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 9th, 2022
//
//  FILE:        homework2.c
//
//  DESCRIPTION:
//   This program asks for a user to enter a poitive integer
//   It then prints out a table of numbers from 0 to in input integer
//   It will also print out if each printed number is a multiple of 4
//
//  REFERENCES:
//      The C Programming Language sections: 1.5, 2.11, 3.5, 7.2, 7.4
//
****************************************************************/

#include <stdio.h>

int user_interface();
int is_multiple5(int);
void print_table(int);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Main function that makes calls to the userinterface function
//                 and the table printing function 
//
//  Parameters:    argc (int) : stores the number of arguments passed when the program was run 
//                 argv (char) : an array of pointers that point to strings that 
//                               reprsent the passed in arguments
//
//  Return values:  0 : success
//                 
//
****************************************************************/

int main(int argc, char* argv[])
{
    print_table(user_interface());
}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   A userinterface function
//                 This function obtains the max value to print
//
//  Parameters:    none
//
//  Return values:  returns the value inputted by the user
//                 
//
****************************************************************/

int user_interface()
{
    int input;

    printf("This program will ask for a maximum poitive integer\n"
    "It will then print out all of the numbers from 0 up to and including the input number\n"
    "It will also print if each number is a multiple of 4.\n\nEnter maximum number to show: ");

    while (1 == 1)
    {
        if (scanf(" %d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("Input was not a number. Please enter a positive Integer.\n\n"
            "Enter maximum number to show: ");
        }
        else
        {
            if (input < 0)
            {
                printf("Input was not positive. Please enter a positive Integer."
                "\n\nEnter maximum number to show: ");
            }
            else
            {
                return input;
            }
        }
    }
}

/*****************************************************************
//
//  Function name: is_multiple
//
//  DESCRIPTION:   Checks if the given number is a multiple of 4
//                
//
//  Parameters:    input (int) : contains the number which will 
//                               checked 
//                               
//
//  Return values:  0 : number is not a multiple of 4
//                  1 : number is a multiple of 4
//
****************************************************************/

int is_multiple(int input)
{
    int isMultiple;

    if ((input % 4) == 0)
    {
        isMultiple = 1;
    }
    else
    {
        isMultiple = 0;
    }

    return isMultiple;
}

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   Prints a formatted table to from 0 up to and 
//                 including the number inputted also prints if 
//                 each number is a multiple of 4 
//
//  Parameters:    maxNum (int) : contains the maximum number for  
//                                the table to print out
//                               
//
//  Return values:  none
//
****************************************************************/

void print_table(int maxNum)
{
    int i;

    printf("%10s %s\n", "Number", "Multiple of 4?");

    for (i = 0; i <= maxNum; i++)
    {
        printf("%10d %s\n", i, is_multiple(i) == 1 ? "Yes":"No");
    }
}
