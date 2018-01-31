/*  
	Tyler Anthony
	CPSC 2120
	Assignment 2
	March 6, 2016
*/

// MegaTree.cpp

#include "MegaTree.h"

MegaTree::MegaTree() : root(nullptr), count(0)
{}

//  takes a name and a vector of k values and adds a suitable node to the tree.
void MegaTree::insert( string name, double vals[] )
{
	if ( root == nullptr ){
		root = new MegaNode(name, vals);
		count = 1;
		return;
	}
	insertNode( root, new MegaNode(name, vals) );
}

void MegaTree::insertNode(MegaNode *curr, MegaNode *newNode)
{
	// reset count to go to look at correct spot in array
	if (count > 2)
		count = 1;
	
	// recursively move through the tree
	if ( curr->vals[count-1] < newNode->vals[count-1] ){
		if (curr->left == nullptr){
			curr->left = newNode;
			count++;
		}
		else{
			insertNode(curr->left, newNode);
		}
	}
	else{
		if (curr->right == nullptr){
			curr->right = newNode;
			count++;
		}
		else{
			insertNode(curr->right, newNode);
		}
	}
}

/*
MegaNode *MegaTree::search( double vals[] )
{
	MegaNode *v = root;
	bool absent = false;
	while (!absent && vals!=v->vals){
		if (vals[0]<v->vals[0] && v->left!=nullptr)
			v = v->;eft;
		else if (vals[0]>v->vals[0] && v->right!=nullptr)
			v = v->right;
		else
			absent = true;
	}
	return v;
}
*/

// this utilizes a recursive procedure to print out the structure of the 
// tree up to and including depth 3
void MegaTree::preorder()
{
	if ( count == 0 ){
		cout << "preorder() count is 0" << endl;
	}
	else {
		preorder(root);
		cout << endl;
	}
}

void MegaTree::preorder(MegaNode * n)
{
	if ( n == nullptr )
		return;
	cout << "(" << n->vals[0] << "," << n->vals[1] << ")" << endl;
	if (root->left != nullptr){
		cout << "...L: ";
		preorder(n->left);
	}
	if (root->right != nullptr){
		cout << "...R: ";
		preorder(n->right);
	}
}

MegaTree::~MegaTree()
{
	deleteTree(root);
}

void MegaTree::deleteTree(MegaNode *curr)
{
	if (curr == nullptr)
		return;
	deleteTree(curr->left);
	deleteTree(curr->right);
	delete curr;
}