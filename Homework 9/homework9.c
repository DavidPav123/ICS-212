/*****************************************************************
//
//  NAME:        David Palicek
//
//  HOMEWORK:    9
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

#include <jni.h>
#include "homework9.h"   

JNIEXPORT jint JNICALL Java_homework9_is_1multiple4 (JNIEnv * file, jclass c, jint num) {
    int isMultiple;

    if ((num % 4) == 0)
    {
        isMultiple = 1;
    }
    else
    {
        isMultiple = 0;
    }

    return isMultiple;
}
