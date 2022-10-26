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
//  FILE:        database.h
//
//  DESCRIPTION:
//   Holds the function prototypes for the database functions
//
//  REFERENCES:
//   Homework 3B website, textbook section 4.5
//
****************************************************************/

#include "record.h"

void addRecord(struct record **, int, char[], char[]);
void printAllRecords(struct record *);
int findRecord(struct record *, int);
int deleteRecord(struct record **, int);
int writefile(struct record *, char[]);
int readfile(struct record **, char[]);
void cleanup(struct record **);
