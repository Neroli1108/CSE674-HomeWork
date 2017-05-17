#pragma once
#include<iostream>



class BstNode
{
public:
	BstNode();
	~BstNode();
	BstNode(int a, int b);
	int key;
	int data;
	BstNode* LeftNode = NULL;
	BstNode* RightNode = NULL;
	int height();

};



class BST
{
public:
	BST();
	~BST();
	void insert(int key, int data);
	void insert(int key, int data, BstNode* node);
	int Height();
	BstNode* minValueNode(BstNode* node);
	void deleteNode(int key);
	BstNode* deleteNode(int key, BstNode*);
	BstNode* search(int key);
	BstNode* search(int key, BstNode* node);
	BstNode* root;
	void bst_print_dot(BstNode* tree, FILE* stream);
	void clearAll();
private:
	void bst_print_dot_aux(BstNode* node, FILE* stream);
	void bst_print_dot_null(int key, int data, int nullcount, FILE* stream);
	int height = 0;
	
};

