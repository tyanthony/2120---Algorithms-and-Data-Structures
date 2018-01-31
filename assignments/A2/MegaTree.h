/*  
	Tyler Anthony
	CPSC 2120
	Assignment 2
	March 6, 2016
*/

// MegaTree.h

#ifndef MEGATREE_H
#define MEGATREE_H

#include <iostream>
#include <cmath>
#include <string>
#include "MegaNode.h"

using namespace std;

class MegaTree
{
	private:
		MegaNode *root;
		int count;
	public:
		MegaTree();
		void insert( string name, double vals[] );
		void preorder();
		~MegaTree();
		
		// helpers
		void preorder(MegaNode *n);
		void insertNode(MegaNode * curr, MegaNode * newNode);
		void deleteTree(MegaNode *curr);
		// MegaNode *search(double vals[]);
};

#endif 
