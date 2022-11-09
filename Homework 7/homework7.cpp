/*****************************************************************
//
//  NAME:        David Palicek
//
//  HOMEWORK:    7
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 5th, 2022
//
//  FILE:        homework7.cpp
//
//  DESCRIPTION:
//   This program asks for a user to enter a poitive integer
//   It then prints out a table of numbers from 0 to in input integer
//   It will also print out if each printed number is a multiple of 4
//
//  REFERENCES:
//      The C Programming Language sections: 1.5, 2.11, 3.5, 7.2, 7.4
//      The C++ Programming Language sections: 2.2.5, 7.7.2, 38.4.1.2
//      http://www.cplusplus.com/doc/tutorial/basic_io/#cin
//      http://www.cplusplus.com/reference/ios/ios/#functions
//
****************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int user_interface();
void is_multiple4(int, int&);
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

    cout << "This program will ask for a maximum poitive integer\n"
    "It will then print out all of the numbers from 0 up to and including the input number\n"
    "It will also print if each number is a multiple of 4."
    "\n\nEnter maximum number to show: " << endl;

    while (1 == 1)
    {
        cin >> input;
        if (!cin.good())
        {
            cin.clear();
            cin.ignore();
            cout << "Input was not a number. Please enter a positive Integer.\n\n"
            "Enter maximum number to show: ";
        }
        else
        {
            if (input < 0)
            {
                cout << "Input was not positive. Please enter a positive Integer."
                "\n\nEnter maximum number to show: ";
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
//  Function name: is_multiple4
//
//  DESCRIPTION:   Checks if the given number is a multiple of 4
//                
//
//  Parameters:    input (int) : contains the number which will 
//                               checked
//                 Modifier (int&) : a reference to an integer 
//                     that tells if the input is a multiple of 4   
//                               
//
//  Return values:  none
//
****************************************************************/

void is_multiple4(int input, int& Modifier)
{
    if ((input % 4) == 0)
    {
        Modifier = 1;
    }
    else
    {
        Modifier = 0;
    }
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
    int i, multipleYN;
    int& value = multipleYN;
    cout << std::setw(10) << "Number " << "Multiple of 4?" << endl;

    for (i = 0; i <= maxNum; i++)
    {
        is_multiple4(i, value);
        cout << std::setw(9) << i << (multipleYN == 1 ? " Yes":" No") << endl;
    }
}
