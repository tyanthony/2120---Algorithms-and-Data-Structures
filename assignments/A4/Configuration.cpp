/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Configuration.cpp

#include "Configuration.h"

Configuration::Configuration(int rr, int cc) : rows(rr), cols(cc), countOfTiles(0), tilePlaced(1)
{
	board = new Square*[rr];
	for (int i = 0; i < rr; i++){
		board[i] = new Square[cc];
	}
}

Configuration::Configuration(string filename) : tilePlaced(1)
{
	char open, forbidden;

	// read in the file
	ifstream inputfile;
	inputfile.open(filename);

	// read characters into variables and temp variables
	inputfile >> rows;
	inputfile >> cols;
	inputfile >> open;
	inputfile >> forbidden;

	// set the static variables
	Square s;
	s.setChars(open, forbidden);

	// allocate space for the new board
	board = new Square*[rows];
	for (int i = 0; i < rows; i++){
		board[i] = new Square[cols];
	}

	// read in the rest of the file into the correct locations on the board
	char temp;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			inputfile >> temp;
			if (temp == forbidden)
				board[i][j].set(-1, temp);
			else
				board[i][j].set(0, temp);

		}
	}

	inputfile.close();
}

/*
	Function placeTileAt tries to place a tile: it is supplied the upper-left row and column (numbered
	from 1), whether the tile is to be placed horizontal or not, and the length of the tile.
	If the placement is not possible, then it should do nothing. Otherwise it should change the
	state of all specified squares appropriately. The function returns whether the placement was
	successful or not.
*/
bool Configuration::placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength)
{
	int r = rStart - 1;	// r used in the array
	int c = cStart - 1;	// c used in the array

	Square s;
	char o = s.getOpen();

	// make sure the tileLength is suitable
	if (tileLength <= 0){
		cout << "Tiles cannot have length less than or equal to 0" << endl;
		return false;
	}

	// check to see if the tile can be placed
	if ( r <= rows-1 && c <= cols-1){
		// if tile to be place horizontally
		if (isHorizontal){
			// check to see if there are enough available spots on board
			int check = 0;
			for (int i = c; i < c+tileLength; i++){
				if ( i < cols && board[r][i].getState() == o ){
					check++;
				}
			}
			// board will have enough space at location, so place the tile
			if ( check == tileLength){
				for (int i = c; i < c+tileLength; i++){
					board[r][i].set(tilePlaced, 'x');
					tilesOnBoard.emplace_back(r, i, true, tileLength);
					countOfTiles++;
				}
				tilePlaced++;
				return true;
			}
			else{
				cout << "At least one required square is covered/forbidden horizontally" << endl;
				return false;
			}
		}
		// tile will be placed vertically
		else{
			// check to see if there are enough available spots on board
			int check = 0;
			for (int i = r; i < r+tileLength; i++){
				if ( i < rows && board[i][c].getState() == o ){
					check++;
				}
			}
			// board will have enough space at location, so place the tile
			if ( check == tileLength){
				for (int i = r; i < r+tileLength; i++){
					board[i][c].set(tilePlaced, 'x');
					tilesOnBoard.emplace_back(i, c, false, tileLength);
					countOfTiles++;
				}
				tilePlaced++;
				return true;
			}
			else{
				cout << "At least one required square is covered/forbidden vertically" << endl;
				return false;
			}
		}
	}
	else{
		cout << "(" << rStart << "," << cStart << ")" << " is out of bounds" << endl;
		return false;
	}

}

void Configuration::forbid(int r, int c)
{
	Square f;
	char forbidden = f.getForbidden();
	char o = f.getOpen();
	if (r < rows && c < cols && board[r][c].getState() == o)
		board[r-1][c-1].set(-1, forbidden);
}

void Configuration::dumpToScreen() const
{
	cout << endl;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (board[i][j].getState() == 'x'){
				//if greater than 9 then convert to ASCII letters
				if (board[i][j].getCoveredBy() >= 10)
					cout << (char)(board[i][j].getCoveredBy()+55);
				else{
					cout << board[i][j].getCoveredBy();
				}
			}
			else if (board[i][j].getCoveredBy() == -1){
				cout << board[i][j].getForbidden();
			}
			else{
				cout << board[i][j].getOpen();
			}
		}
		cout << endl;
	}
}

list<Placement> Configuration::getPossiblePlacements(int tileLength)
{
	// list<Placement> P;
	int count = 0;

	Square s;
	char o = s.getOpen();

	// tileLength of 1, then horizontal
	if (tileLength == 1){
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (board[i][j].getCoveredBy() == 0){
					P.emplace_back(i+1, j+1, true, tileLength);
				}
			}
		}
	}
	else{
		int r = 0;
		int c = 0;
		while ( r < rows && c < cols){
			// check board horizontally for open placements
			for (int i = r; i < rows; i++){	 // rows
				for (int j = c; j < cols; j++){	 // columns
					for (int k = j; k < j+tileLength; k++){
						if (k < cols && board[i][k].getState() == o){
							count++;
						}
					}
					if (count == tileLength){
						P.emplace_back(i+1, j+1, true, tileLength);
					}
					count = 0;
				}

				r++;
			}
			c++;
		} // end while
		r = 0;
		c = 0;
		count = 0;
		while (r < rows && c < cols){
			// check board for vertical placements
			for (int i = r; i < rows; i++){		//rows
				for (int j = c; j < cols; j++){		//columns
					for (int k = i; k < i+tileLength; k++){
						if (k < rows && board[k][j].getState() == o){
							count++;
						}
					}
					if (count == tileLength){
						P.emplace_back(i+1, j+1, false, tileLength);
					}
					count = 0;
				}
				r++;
			}
			c++;
		} // end while
	}

	return P;
}

Configuration::~Configuration()
{
	delete board;
}

// HELPERS
int Configuration::numberOfPlacements(list<Placement> p)
{
	return p.size();
}

char Configuration::convert(int c)
{
	return (char)c+65;
}
