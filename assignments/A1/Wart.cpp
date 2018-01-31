// Tyler Anthony - Assignment 1 - 1/31/2016
// Wart.cpp

#include "Wart.h"

Wart::Wart(string code) : s(code)
{}

void Wart::encode(int width)
{
	int slength = s.length();	// length of the string
	//int smod = s.length() % width;  // mod of the length of the string and the width
	// add needed characters to the end of the string to make it a factor of the width
	if (s.length() % width != 0){
		for (int i=0; i < ((slength % width) - 1); i++){
			// add spaces
			s += " ";
		}
		// add period at the end
		s += ".";
	}

	// encoding
	int height = slength / width;	// height of the rectangle
	char array[height][width];
	int count = 0;
	
	// put the string s into the array
	for (int i=0; i<height; i++){
		for (int j=0; j<width; j++){
			array[i][j] = s.at(count);
			count++;
		}
	}
	
	count = 0;
	// store the array back into the string column-wise
	for (int i=0; i<width; i++){
		for (int j=0; j<height; j++){
			s.at(count) = array[j][i];
			count++;
		}
	}
	
	return;
}

ostream & operator<< (ostream & out, const Wart & w)
{
	out << w.s;
	return out;
}

void Wart::decode(Digraph &dig)
{
	/* Say the current string has length m. Then try all
	possible widths from 1 up to m inclusive, but only those that are divisors of m. For each
	possible width, determine the score the Digraph gives. After considering all possibilities,
	set the string to the decoding that gives the highest score.
	*/
	int score = 0;
	int highestScore = 0;
	string stored;
	int m = s.length();
	for (int i=1; i<=m; i++){
		if (m%i == 0){
			// do the decoding (opposite of encode)
			int height = m / i;
			char array[height][i];
			int count = 0;
			for (int j=0; j<height; j++){
				for (int k=0; k<i; k++){
					array[j][k] = s.at(count);
					count++;
				}
			}
			count = 0;
			for (int j=0; j<height; j++){
				for (int k=0; j<i; k++){
					s.at(count) = array[j][k];
					count++;
				}
			}
			
			score = dig.getScore(s);
			
			// check to see if its the highest score
			if (score > highestScore){
				highestScore = score;
				// save string to print out
				stored = s;				
			}
			
		}
	}
	s = stored;
	return;
}

