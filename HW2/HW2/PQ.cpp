//////////////////////////////////////////////////////////
//File: PQ.cpp											//
//Function: The implentation of the PQ.h				//
//Author: Yunding Li									//
//Date: 10/23/2016										//
//////////////////////////////////////////////////////////


#include<iostream>
#include"PQ.h"



int PQ::height() {

	return MH.height();
}

void PQ::insert(int key, int val) { //insert a new node
	MH.insert(PQNode(key, val));
}

std::vector<PQNode> PQ::All_Minimum() { //return all minimum
	if (height() == 0)
	{
		return MH.heap;
	}
	return MH.getMin();
}

std::vector<PQNode>PQ::Extra_all_min() { // remove all minimum
	if (height() == 0)
	{
		return MH.heap;
	}
	else
	return MH.removeMin();
}

void PQ::decrease_key(int index,int val) { // decrease the key
	if (height() == 1)
	{
		return;
	}

	MH.decreaseVal(index , val);
}

void PQ::Clear() { //clear priority queue

	MH.heap.clear();
}

int PQ::size() {//priority queue size

	return MH.heap.size();
}


void PQ::print() {  //print all priority queue

	for (size_t j = 0; j < this->size(); j++)
	{
		std::cout << "Key: " << MH.heap[j].key << " Value: " << MH.heap[j].val<< std::endl;
	}

}



