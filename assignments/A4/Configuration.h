/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Configuration.h
// manipulates a board, and places tiles. All tiles are 1 square wide and a
// specified length

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include "Square.h"
#include "Placement.h"

using namespace std;

class Configuration
{
	protected:
		int rows, cols;
		Square **board;
		int countOfTiles;
		list<Placement> tilesOnBoard;

		// helpers
		int tilePlaced;
		list<Placement> P;

	public:
		Configuration(int rr, int cc);
		Configuration(string filename);
		virtual ~Configuration();
		list<Placement> getPossiblePlacements(int tileLength);
		bool placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength);
		void forbid(int r, int c);
		virtual void dumpToScreen() const;

		// helpers
		int numberOfPlacements(list<Placement> p);
		char convert(int);

};

#endif
