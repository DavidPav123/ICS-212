/*****************************************************************
//
//  NAME:        Ravi Narayan
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 3, 2112
//
//  FILE:        homework8.c
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//   List references used here
//
****************************************************************/

#include <stdio.h>
int readfile(const char[], unsigned char[]);
int writefile(const char[], const unsigned char[]);
void printheader(const unsigned char[]);
void makeheader(const unsigned char[], unsigned char[]);

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

int main(int argc, char *argv[]) 
{
    int returnVal;
    return returnVal;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/
int readfile(const char filename[], unsigned char dataArr[]) 
{
    int returnVal;
    FILE *fptr;

    fptr = fopen(filename, "rb");

    if (fptr == NULL)
    {
        returnVal = -1;
    }
    else {
        fread(dataArr, sizeof(&dataArr), 1, fptr);

        fclose(fptr);
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/
int writefile(const char filename[], const unsigned char dataArr[]) 
{
    int returnVal;
    FILE *fptr;

    fptr = fopen(filename, "wb+");

    if (fptr == NULL)
    {
        returnVal = -1;
    }
    else {
        fwrite(dataArr, sizeof(&dataArr), 1, fptr);

        fclose(fptr);
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/
void printheader(const unsigned char dataArr[]) 
{
    char header[2];
    header[0] = dataArr[1];
    header[1] = dataArr[0];


    printf("%d",header);
}

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/
void makeheader(const unsigned char dataArr[], unsigned char newArr[]) 
{

}