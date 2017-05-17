#include<iostream>
#include<algorithm>
#include<fstream>
#include"BST.h"
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<vector>


BstNode::BstNode(int a, int b) :key(a), data(b)
{
}
BstNode::BstNode() : key(0), data(0)
{
}

BstNode::~BstNode()
{
}

int BstNode::height() {


	int l = LeftNode ? LeftNode->height() : 0;  // height of left child, if any
	int r = RightNode ? RightNode->height() : 0; // idem for right child
	return 1 + std::max(l, r);

}


BST::BST()
{
	root == NULL;
}

BST::~BST()
{
}

void BST::insert(int key,int data, BstNode* node) {

	if (node->key>=key)
	{
		if (node->LeftNode ==NULL)
		{
			node->LeftNode = new BstNode(key, data);
		}
		else
		{
			insert(key, data, node->LeftNode);
		}
	}
	else 
	{
		if (node->RightNode == NULL)
		{
			node->RightNode = new BstNode(key, data);
		}
		else
		{
			insert(key, data, node->RightNode);
		}
	}

}


void BST::insert(int key,int data) {
	if (root == NULL)
	{
		root = new BstNode(key, data);
		
	}
	else
	{
		insert(key, data, root);
	}

	height++;
}


BstNode* BST::search(int key) {

	if (root == NULL)
	{
		return NULL;
	}
	else
	{
	  return search(key, root);
	}

}

BstNode* BST::search(int key, BstNode* node) {
	if (node != NULL)
	{
		if (node->key == key)
		{
			return node;
		}
		else if (node->key >= key)
		{
			return	search(key, node->LeftNode);
		}
		else
		{
			return search(key, node->RightNode);
		}
	}
	else
	{
		return NULL;
	}
	
}

BstNode* BST:: minValueNode(BstNode* node)
{
	BstNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current->LeftNode != NULL)
		current = current->LeftNode;

	return current;
}

BstNode* BST::deleteNode(int key,BstNode* node) {

	if (node == NULL)
	{
		return node;
	}

	if (key<node->key)
	{
		node->LeftNode = deleteNode(key, node->LeftNode);
	}
	else if (key>node->key)
	{
		node->RightNode = deleteNode(key, node->RightNode);
	}
	else
	{
		if (node->LeftNode == NULL)
		{
			BstNode* temp = node->RightNode;
			node->key = 0;
			node->data = 0;
			node->LeftNode = NULL;
			node->RightNode = NULL;
			node = NULL;
			return temp;
		}
		else if (node->RightNode == NULL)
		{
			BstNode* temp = node->LeftNode;
			node->key = 0;
			node->data = 0;
			node->LeftNode = NULL;
			node->RightNode = NULL;
			node = NULL;
			return temp;
		}

		BstNode* temp = minValueNode(node->RightNode);

		node->key = temp->key;
		node->data = temp->data;
		node->RightNode = deleteNode(temp->key, node->RightNode);
	}
	return node;
}


void BST::deleteNode(int key) {

	if (root == NULL)
	{
		return;
	}
	else
	{
		root = deleteNode(key, root);
	}

}


int BST::Height() {

	if (root==NULL)
	{
		return -1;
	}
	else
	{
		return root->height();
	}
	

}


void BST::clearAll() {
	root = NULL;
	root->LeftNode = NULL;
	root->RightNode = NULL;

}

//print functions

void BST:: bst_print_dot_null(int key,int data, int nullcount, FILE* stream)
{
	fprintf(stream, "    null%d [shape=point];\n", nullcount);
	fprintf(stream, "   \"%d,%d\"-> null%d;\n", key,data, nullcount);
}

void BST:: bst_print_dot_aux(BstNode* node, FILE* stream)
{
	static int nullcount = 0;

	if (node->LeftNode)
	{
		fprintf(stream, " \"%d,%d\" -> \"%d,%d\";\n", node->key,node->data, node->LeftNode->key,node->LeftNode->data);
		bst_print_dot_aux(node->LeftNode, stream);
	}
	else
		bst_print_dot_null(node->key,node->data, nullcount++, stream);

	if (node->RightNode)
	{
		fprintf(stream, "\"%d,%d\" ->\"%d,%d\";\n", node->key, node->data, node->RightNode->key, node->RightNode->data);
		bst_print_dot_aux(node->RightNode, stream);
	}
	else
		bst_print_dot_null(node->key,node->data, nullcount++, stream);
}

void BST::bst_print_dot(BstNode* tree, FILE* stream)
{
	fprintf(stream, "digraph BST {\n");
	fprintf(stream, "    node [fontname=\"Arial\"];\n");

	if (!tree)
		fprintf(stream, "\n");
	else if (!tree->RightNode && !tree->LeftNode)
		fprintf(stream, "\"%d,%d\";\n", tree->key,tree->data);
	else
		bst_print_dot_aux(tree, stream);

	fprintf(stream, "}\n");
}

