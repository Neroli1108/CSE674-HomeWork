#pragma once
#include<iostream>

class KdTreeNode
{
public:
	KdTreeNode();
	KdTreeNode(int xkey,int ykey,int data);
	~KdTreeNode();
	int Xkey;
	int Ykey;
	int data;
	int height();
	KdTreeNode* leftNode;
	KdTreeNode* rightNode;

private:

};




class KdTree
{
public:
	KdTree();
	~KdTree();
	KdTreeNode* root;
	void insert(int, int, int);
	void insert(int, int, int,KdTreeNode*,int);
	KdTreeNode* deleteNode(int,int,int,KdTreeNode*);
	void deleteNode(int xkey, int ykey);
	KdTreeNode* search(int, int, int,KdTreeNode*);
	KdTreeNode* search(int, int);
	int Height();
	void bst_print_dot(KdTreeNode* tree, FILE* stream);
	void clear();
	void update();
private:
	void bst_print_dot_null(int xkey, int ykey, int data, int nullcount, FILE* stream);
	void bst_print_dot_aux(KdTreeNode* node, FILE* stream);
};

