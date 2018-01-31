// Tyler Anthony - Assignment 1 - 1/31/2016
// Wart.h

#ifndef WART_H
#define WART_H

#include <iostream>
#include <cmath>
#include <string>
#include "Digraph.h"

using namespace std;

class Wart
{
	private:
		string s;
	public:
		Wart(string s);
		void encode(int width);
		void decode(Digraph &dig);
		friend ostream &operator<< (ostream &, const Wart &);
};

#endif
