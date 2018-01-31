/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Square.h

/*
	This class represents a square on the board.  It should remember the
	state of a square (open, covered, or forbidden). If the square is covered,
	it should remember the number of the tile that covered it. It should have a
	class method to set/reset the characters for displaying the state
	(default is a period for open and hashtag for forbidden).
*/

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdio.h>

using namespace std;

class Square
{
	private:
		int coveredBy;
		char state;
		static char open, forbidden;

	public:
		Square();
		static void setChars(char o, char f);
		void set(int, char);
		void reset();

		// helpers
		char getState();
		int getCoveredBy();
		char getForbidden();
		char getOpen();
};

#endif
