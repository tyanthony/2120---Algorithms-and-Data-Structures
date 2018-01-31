/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Placement.h

#ifndef PLACEMENT_H
#define PLACEMENT_H
#include <iostream>
#include <stdio.h>

using namespace std;

class Placement
{
	private:
		int row, col, tileLength;
		bool isHorizontal;

	public:
		Placement(int r, int c, bool isHorizontal, int tileLength);

		//helpers
		int getRow();
		int getCol();
		bool getHorizontal();

		friend ostream &operator<< (ostream &out, const Placement &tile);

};

#endif
