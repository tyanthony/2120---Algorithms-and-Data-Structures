// Tyler Anthony - Assignment 1 - 1/31/2016
// Digraph.cpp

#include "Digraph.h"

Digraph::Digraph()
{
	// set the proportion for the following to 0.1
	// th he in er an re nd at on nt
	// set all other digraphs as 0.0
	for (int i=0; i<26; i++){
		for (int j=0; j<26; j++){
			if ( (i==double('t')-97 && j==double('h')-97) || (i==double('h')-97 && j==double('e')-97) || (i==double('i')-97 && j==double('n')-97) || (i==double('e')-97 && j==double('r')-97) || (i==double('a')-97 && j==double('n')-97) || (i==double('r')-97 && j==double('e')-97) || (i==double('n')-97 && j==double('d')-97) || (i==double('a')-97 && j==double('t')-97) || (i==double('o')-97 && j==double('n')-97) || (i==double('n')-97 && j==double('t')-97) )
				A[i][j] = 0.1;
			else
				A[i][j] = 0.0;
		}
	}
}

Digraph::Digraph(string filename)
{
	ifstream myfile(filename);
	string word;
	int totalCount = 0;
	float highest = 0;
	
	// initialize the array to all zeros
	for (int i=0; i<26; i++)
		for (int j=0; j<26; j++)
			A[i][j] = 0;

	int length;
	// read the file word by word
	// account for non-letter characters
	while (myfile >> word){
		length = word.length();
		cout << word << endl;
		for (int i=0; i<length; i++){
		/*	if ((int)word.at(i)-97 < 0 || (int)word.at(i) > 25){
				word.erase(i, 1);
				cout << word << endl;
			} */
			word[i] = tolower(word[i]);
		}
		for (int i=0; i<length-1; i++){
			A[(int)word.at(i)-97][(int)word.at(i+1)-97]++;
			totalCount++;
		}
	}
	myfile.close();

	// go through the array and determine which digraph occurred the most
	for (int i=0; i<26; i++){
		for (int j=0; j<26; j++){
			A[i][j] = A[i][j] / totalCount;  // sets the proportion of each spot in the array
			if (A[i][j] > highest){
				highest = A[i][j];
			}
		}
	}
	
	// go through array again and print out the most occurring digraph and the proportion
	for (int i=0; i<26; i++){
		for (int j=0; j<26; j++){
			if (A[i][j] == highest){
				cout << "Most common was: " << (char)(i+97) << (char)(j+97) << " with a proportion of " << A[i][j] << endl;
				return;
			}
		}
	}
	
}

double Digraph::getScore(char a, char b)
{
	double score = 0.0;
	for (int i=0; i<26; i++)
		for (int j=0; j<26; j++)
			score = score + A[(int)a-97][(int)b-97] / 2;
	return score;
}

double Digraph::getScore(string &str)
{
	double score = 0.0;
	int length = str.length();
	for (int i=0; i<length-1; i++)
		score = score + getScore(str.at(i), str.at(i+1));
	return score;
}
