/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Square.cpp

#include "Square.h"

// initialize static variables
char Square::open = '.';
char Square::forbidden = '#';

Square::Square() : coveredBy(0), state('.')
{}

void Square::setChars(char o, char f)
{
	open = o;
	forbidden = f;
}

void Square::set(int tileNumber, char stateOf)
{
	coveredBy = tileNumber;
	state = stateOf;
}

void Square::reset()
{
	state = '.';
}

// HELPERS
char Square::getState()
{
	return state;
}

int Square::getCoveredBy()
{
	return coveredBy;
}

char Square::getForbidden()
{
	return forbidden;
}

char Square::getOpen()
{
	return open;
}
