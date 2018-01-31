/*  
	Tyler Anthony
	CPSC 2120
	Assignment 2
	March 6, 2016
*/

// MegaNode.h

#ifndef MEGANODE_H
#define MEGANODE_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct MegaNode
{
	string name;
	int dimension;
	double *vals;
	MegaNode *left, *right;
	
	// should I have this?
	MegaNode( string n, double values[]) : name(n), dimension(0), vals(values), left(nullptr), right(nullptr)
	{}
};

#endif 
