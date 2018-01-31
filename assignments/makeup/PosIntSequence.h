/*
	Tyler Anthony
	CPSC 2120-001
	Make-up Assignment
	May 1, 2016
*/

// PosIntSequence.h

#ifndef POSINTSEQUENCE_H
#define POSINTSEQUENCE_H

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class PosIntSequence
{
	private:
		int capacity;
		int *array;

		// helper
		int count;

	public:
		static const int INVALID = -1;
		static const int UNUSED = -2;

		PosIntSequence(int value);
		~PosIntSequence();
		void append(int element);
		void remove(int element);
		void increaseCapacity(int moreCapacity);
		int getSize();
		void rawDump();

		friend ostream &operator<< (ostream &out, const PosIntSequence *p);
};

#endif
