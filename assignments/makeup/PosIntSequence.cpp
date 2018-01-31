/*
	Tyler Anthony
	CPSC 2120-001
	Make-up Assignment
	May 1, 2016
*/

// PosIntSequence.cpp

#include "PosIntSequence.h"

PosIntSequence::PosIntSequence(int value) : capacity(value), count(0)
{
	array = new int[value];
	for (int i = 0; i < value; i++){
		array[i] = UNUSED;
	}
}

PosIntSequence::~PosIntSequence()
{
	delete[] array;
}

void PosIntSequence::append(int element)
{
	if (element < 0){
		cout << "The element is negative" << endl;
		return;
	}
	else if (count == capacity){
		cout << "The array is full" << endl;
		return;
	}
	else{
		array[count] = element;
		count++;
	}

}

void PosIntSequence::remove(int element)
{
	int out = -5;
	for (int i = 0; i < capacity; i++){
		if (array[i] == element){
			out = array[i];
			array[i] = INVALID;
			return;
		}
	}
	if (out == -5){
		cout << "The value is not in the array" << endl;
	}
}

void PosIntSequence::increaseCapacity(int moreCapacity)
{
	if (moreCapacity < 0){
		cout << "moreCapacity must be positive" << endl;
		return;
	}

	// temporary array with only the valid elements
	int *temp = new int[moreCapacity];

	// get the valid elements of array
	int c = 0; // variable used to put the valid values into the first spots of the new array
	for (int i = 0; i < capacity; i++){
		if (array[i] != UNUSED && array[i] != INVALID){
			temp[c++] = array[i];
		}
	}
	//fill in the rest of the array as UNUSED
	for (int i = c; i < moreCapacity; i++){
		temp[i] = UNUSED;
	}

	// set the capacity to the new size
	capacity = moreCapacity;

	delete[] array;
	array = temp;
}

int PosIntSequence::getSize()
{
	int size = 0;
	for (int i = 0; i < capacity; i++){
		if (array[i] != UNUSED && array[i] != INVALID){
			size++;
		}
	}
	return size;
}

void PosIntSequence::rawDump()
{
	cout << "\nVARIABLES" << endl;
	cout << "capacity: " << capacity << endl;
	cout << "helper variable count: " << count << endl;
	cout << "The full array is: [ ";
	for (int i = 0; i < capacity; i++){
		cout << array[i] << ", ";
	}
	cout << "]" << endl;
}

ostream &operator<< (ostream &out, const PosIntSequence *p)
{
	for (int i = 0; i < p->capacity; i++){
		if (p->array[i] >= 0){
			out << p->array[i] << " ";
		}
	}
	return out;
}
