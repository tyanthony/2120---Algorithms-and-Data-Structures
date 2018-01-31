/*
	Tyler Anthony
	CPSC 2120-001
	Make-up Assignment
	May 1, 2016
*/

// Driver.cpp

#include "PosIntSequence.h"
#include <iostream>

int main()
{
	int size;
	cout << "Enter a size for the array: ";
	cin >> size;
	PosIntSequence *P = new PosIntSequence(size);
	P->append(4);
	P->append(1);
	P->append(2);
	P->append(3);
	P->remove(1);
	P->append(1);

	cout << "Enter a larger size for the array: ";
	cin >> size;
	// size = -1;
	P->increaseCapacity(size);
	for (int i = 0; i < size; i++){
		P->append(i);
	}

	size = P->getSize();
	cout << "\nSize of array: " << size << endl;

	P->rawDump();

	cout << "\nData sequence\n" << P << endl;

	return 0;
}
