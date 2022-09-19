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
//  FILE:        database.h
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//              secton 4.4
//
****************************************************************/

void addRecord (struct record **, int, char [ ],char [ ]);

void printAllRecords(struct record *);

int findRecord (struct record *, int);

int deleteRecord(struct record **, int);