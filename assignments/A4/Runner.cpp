/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Runner.cpp

#include "Configuration.h"
#include "Square.h"
#include <sstream>

int main()
{
	int rows, cols;
	cout << endl << "Enter number of rows and cols for board: ";
	cin >> rows >> cols;
	Configuration *game = new Configuration(rows, cols);

	int r, c;
	cout << "Enter forbidden square: ";
	cin >> r >> c;
	game->forbid(r, c);

	int length;
	bool isHorizontal;
	cout << "Enter tile info: ";
	cin >> r >> c >> boolalpha >> isHorizontal >> length;
	game->placeTileAt(r, c, isHorizontal, length);

	cout << "Enter tile info: ";
	cin >> r >> c >> boolalpha >> isHorizontal >> length;
	game->placeTileAt(r, c, isHorizontal, length);

	cout << "Enter tile info: ";
	cin >> r >> c >> boolalpha >> isHorizontal >> length;
	game->placeTileAt(r, c, isHorizontal, length);

	cout << endl;
	game->dumpToScreen();
	cout << endl;

	return 0;
}
