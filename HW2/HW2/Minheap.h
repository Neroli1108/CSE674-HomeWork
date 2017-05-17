///////////////////////////////////////////////
//File: Minheap.h                            //
//Function: The header file of the Min-Heap  // 
//Author: Yunding Li                         //
//Date: 10/23/2016							 //
///////////////////////////////////////////////
#pragma once
#include<vector>
#include<iostream>
#include"PQNode.h"

class MinHeap
{
public:
	MinHeap() {};
	MinHeap(const std::vector<PQNode>& vector) { heapify(); };
	~MinHeap() {};
	void insert(PQNode);
	std::vector<PQNode> getMin(); //get the minimum node
	std::vector<PQNode> removeMin(); //remove all minimum nodes
	void decreaseVal(int,int);  //decrease the key 
	int height();   //return the size of the vector 

	std::vector<PQNode> heap;
	void heapDown(int);
	void heapUp(int);
	void heapify();

};


