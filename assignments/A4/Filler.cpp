/*
	Tyler Anthony
	CPSC 2120-001
	Assignment 4
	April 17, 2016
*/

// Filler.cpp

#include "Filler.h"

Filler::Filler(string fileName) : Configuration(fileName)
{
    char open, forbidden;

    // read in the file
    ifstream inputfile;
    inputfile.open(fileName);

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
(1) Working top to bottom,
        within each row working left to right,
            place horizontal tile starting here if possible.
(2) Working left to right,
        within each column working top to bottom,
            place vertical tile starting here if possible
*/
void Filler::greedyFill(int tileLength)
{
    Square s;
    char o = s.getOpen();
    char f = s.getForbidden();
    s.setChars(o, f);
    int count = 0;
    // horizontal placement
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            for (int k = j; k < j+tileLength; k++){
                if (k < cols && board[i][k].getState() == o){
                    count++;
                }
            }
            if (count == tileLength){
                for (int k = j; k < j+tileLength; k++){
                    board[i][k].set(tilePlaced, 'x');
                    countOfTiles++;
                }
                tilePlaced++;
            }
            count = 0;
        }
    }
    count = 0;
    // vertical placement
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            for (int k = i; k < i+tileLength; k++){
                if (k < rows && board[k][j].getState() == o){
                    count++;
                }
            }
            if (count == tileLength){
                for (int k = i; k < i+tileLength; k++){
                    board[k][j].set(tilePlaced, 'x');
                    countOfTiles++;
                }
                tilePlaced++;
            }
            count = 0;
        }
    }
}

void Filler::betterFill(int tileLength)
{
    list<Placement> canDo = getPossiblePlacements(tileLength);
    for (Placement p : canDo){
        placeTileAt(p.getRow(), p.getCol(), p.getHorizontal(), tileLength);
        countOfTiles++;
    }
    greedyFill(tileLength);
}

void Filler::dumpToScreen() const
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
