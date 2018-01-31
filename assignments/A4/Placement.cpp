/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Placement.cpp

#include "Placement.h"

Placement::Placement(int r, int c, bool horizontal, int length) : row(r), col(c), tileLength(length), isHorizontal(horizontal)
{}

//helpers
int Placement::getRow()
{
	return row;
}

int Placement::getCol()
{
	return col;
}

bool Placement::getHorizontal()
{
	return isHorizontal;
}

ostream &operator<< (ostream &out, const Placement &tile)
{
	if (tile.isHorizontal)
		out << "uplft=(" << tile.row << "," << tile.col << ") " << "horz len=" << tile.tileLength;
	else
		out << "uplft=(" << tile.row << "," << tile.col << ") " << "vert len=" << tile.tileLength;
	return out;
}
