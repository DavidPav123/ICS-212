/*****************************************************************
//
//  NAME:        David Pavlicek
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        January 1, 2021
//
//  FILE:        homework1.c
//
//  DESCRIPTION:
//          Prints out "Hello world !!!" twice using if statments nested in a 
//          for loop and then demonstrates while loops and do-while loops 
//          by printing out "While loop!" and "Do-while loop!" respectively
//          three times each
//
****************************************************************/

#include <stdio.h>

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Main function that holds the code that exectues once the program is run
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    int num;
    int i;

    for (i = 0; i < 6; i = i + 1)
    {
      if (i < 2)
        printf("Hello\n");
      else if (i < 4)
        printf("World\n");
      else
        printf("!!!\n");
    }

    num = 0;
    while (num < 3)
    {
      printf("While loop!\n");
      num = num + 1;
    }

    num = 0;
    do
    {
      printf("Do-while loop!\n");
      num = num + 1;
    }
    while (num < 3);
  

    return 0;
}