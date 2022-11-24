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
//  FILE:        record.h
//
//  DESCRIPTION:
//   Holds the defintion for the record struct
//
//  REFERENCES:
//   Homework 3B website
//
****************************************************************/
#ifndef RECORD_H
#define RECORD_H

struct record
{
    int                accountno;
    char               name[30];
    char               address[60];
    struct record*     next;
};

#endif
