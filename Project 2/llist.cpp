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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This file contains the function definitions for the llist class.
//
//  REFERENCES:
//   Textbook sections 
//
****************************************************************/

#include "llist.h"
#include <iostream>
#include <fstream>

using namespace std;

extern int debugmode;

int llist::readfile()
{

}

int llist::writefile()
{

}

void llist::cleanup()
{

}

void getaddressfromfile(char addressArr[], int maxLen, std::ifstream& file)
{

}

llist::llist()
{
    start = NULL;
    strcpy(filename, "no file");
}

llist::llist(char file[])
{
    start = NULL;
    strcpy(filename, file);
    readfile();
}

llist::~llist()
{
    llist::cleanup();
}

void llist::addRecord(int, char[], char[])
{

}

int llist::findRecord(int)
{

}

void llist::printAllRecords()
{

}

int llist::deleteRecord(int)
{

}



