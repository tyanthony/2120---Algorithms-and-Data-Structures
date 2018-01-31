/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Filler.h

#ifndef FILLER_H
#define FILLER_H

#include <list>
#include <iostream>
#include <string>
#include "Square.h"
#include "Configuration.h"

using namespace std;

class Filler : public Configuration
{
    public:
        Filler(string fileName);
        //~Filler();
        void greedyFill(int tileLength);
        void betterFill(int tileLength);
        void dumpToScreen() const;

};

#endif
