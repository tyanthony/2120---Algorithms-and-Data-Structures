/*  
	Tyler Anthony
	CPSC 2120
	Assignment 2
	March 6, 2016
*/

// Driver.cpp

#include "MegaTree.h"

int main()
{
	int numPoints;
	// ask user for number of points
	cout << "How many points? ";
	cin >> numPoints;
	
	MegaTree *tree = new MegaTree;
	
	double values[2];
	// ask user for points in the plane
	// add them to the 2D MegaTree using a blank name
	for (int i = 0; i<numPoints; i++) {
		// prompt user for values and store in x an y
		cout << "Enter x and y values: ";
		cin >> values[0] >> values[1];
		
		// add to the 2D MegaTree
		tree->insert("blank", values);
	}
	
	// print out the structure of the tree
	tree->preorder();

	return 0;
}
