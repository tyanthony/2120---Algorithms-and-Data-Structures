// Tyler Anthony - Assignment 1 - 1/31/2016
// Digraph.h

#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class Digraph
{
	private:
		double A[26][26];
	public:
		Digraph();
		Digraph(string filename);
		double getScore(char , char );
		double getScore(string & );
};

#endif
