/*****************************************************************
//
//  NAME:        David Pavlicek
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 16th, 2022
//
//  FILE:        database.c
//
//  DESCRIPTION:
//   This file contains the function definitions for the llist class.
//
//  REFERENCES:
//   Textbook sections 
//
****************************************************************/

#include "record.h"
#include <fstream>

class llist
{
private:
    record* start;
    char filename[20];
    int readfile();
    int writefile();
    void cleanup();
    void getaddressfromfile(char[], int, std::ifstream&);

public:
    llist();
    llist(char[]);
    ~llist();
    void addRecord(int, char[], char[]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
};
