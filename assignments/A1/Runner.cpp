// Tyler Anthony - Assignment 1 - 1/31/2016
// Runner.cpp

#include "Digraph.h"
#include "Wart.h"

int main()
{
	// variables
	string filename;
	string sentence;
	
	cout << "Enter file name for digraph: ";
	// read in file name
	cin >> filename;
	
	// call Digraph (string filename)
	Digraph D(filename);
	
	cout << "Enter sentence terminated by <ENTER> : ";
	// read in sentence
	cin >> sentence;
	cout << "This gets a score of: " << D.getScore(sentence) << endl;
	
	// decode the string
	Wart W(sentence);
	W.decode(D);
	cout << "The decoded sentence is:" << endl; 
	cout << W << endl;
}