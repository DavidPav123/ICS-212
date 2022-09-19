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
//  FILE:        record.h
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//               homework 3B website
//
****************************************************************/

struct record
{
    int                accountno;
    char               name[30];
    char               address[60];
    struct record*     next;
};