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
//  DATE:        November 24th, 2022
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   This file contains the class definitions for the llist class.
//
//  REFERENCES:
//   Textbook sections: 4, 16 
//   Websites:  https://www.cplusplus.com/reference/fstream/ifstream/ifstream/ and https://www.cplusplus.com/reference/fstream/ofstream/ofstream/
//
****************************************************************/

#ifndef LLIST_H
#define LLIST_H

#include <fstream>
#include "record.h"

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

#endif
