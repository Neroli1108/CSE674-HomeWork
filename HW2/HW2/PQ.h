///////////////////////////////////////////////////////////////////////
//File: PQ.h														 //	
//Function: the head file of the priority queue						 //								
//Author: Yunding Li												 //				
//Date: 10/23/2016													 //
///////////////////////////////////////////////////////////////////////

#pragma once
#include<iostream>
#include"Minheap.h"

class PQ {
private:
	MinHeap MH;
	
public:
	void insert(int, int);
	std::vector<PQNode> All_Minimum(); //return all Minimum
	std::vector<PQNode> Extra_all_min(); //remove all minimum
	void decrease_key(int, int); //decrese the key
	void Clear(); //clear all priority queue
	int size();  
	int height(); // return the height of the priority queue
	void print();
};