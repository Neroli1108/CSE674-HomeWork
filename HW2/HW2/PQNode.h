/////////////////////////////////////////////////
//File: PQNode                                 // 
//Function: The node of the priority queue     //
//Author: Yunding Li						   //
//Date: 10/23/2016							   //					
/////////////////////////////////////////////////

#pragma once
#include<iostream>

class PQNode {
	
public:
	int val;
	int key;
	PQNode() {};
	PQNode(int key, int val):key(key),val(val) {};
};