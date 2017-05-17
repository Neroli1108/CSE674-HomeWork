//////////////////////////////////////////////////////
//File: Minheap.cpp									//
//Function: The implementation of the Minheap.cpp	//
//Author: Yunding Li								//
//Date: 10/23/2016									//
//////////////////////////////////////////////////////

#include<iostream>
#include"Minheap.h"


int MinHeap::height() {

	return heap.size();  //return the min size
}

void MinHeap::heapify() {    //heapify the heap
	int length = this->heap.size();
	for (int i = length - 1; i >= 0; --i)
	{
		heapDown(i);
	}
}

void MinHeap::heapDown(int index) {   //make sure the parent is smaller than shildren
	int length = this->heap.size();
	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;
	if (leftChildIndex>=length) // index is  a leaf
	{
		return;
	}
	int minIndex = index;
	if (heap[index].key>heap[leftChildIndex].key)
	{
		minIndex = leftChildIndex;  //if the left children smaller than parent 
	}
	if ((rightChildIndex < length) && (heap[minIndex].key > heap[rightChildIndex].key))
	{
		minIndex = rightChildIndex;  //if the right children smaller than parent
	}
	if (minIndex != index)
	{
		//need to swap
		PQNode temp = heap[index];
		heap[index] = heap[minIndex];
		heap[minIndex] = temp;
		heapDown(minIndex);
	}
}

void MinHeap::heapUp(int index)  //make sure all children is bigger than parent
{
	if (index == 0)
		return;

	int parentIndex = (index - 1) / 2;
	if (heap[parentIndex].key > heap[index].key)
	{
		PQNode temp = heap[parentIndex];
		heap[parentIndex] = heap[index];
		heap[index] = temp;
		heapUp(parentIndex);
	}

}

void MinHeap::insert(PQNode a)
	{
		int length = heap.size();    //insert a new node
		heap.push_back(a);

		heapUp(length);
	}

std::vector<PQNode> MinHeap::getMin() {  //get all smallest node
	std::vector<PQNode> res;
	int stand = heap[0].key;
	for (int i = 0; i < heap.size(); i++)
	{
		if ( stand == heap[i].key)
		{
			res.push_back(heap[i]);
		}
	}
	return res;
}

std::vector<PQNode> MinHeap::removeMin() {
	int stand = heap[0].key;
	std::vector<PQNode> res = getMin();

	if (heap.size() == 1)
	{
		heap.clear();
		return res;
	}

	while (stand == heap.begin()->key)
	{
		heap.erase(heap.begin());
		MinHeap::heapify();
	}

	this->heapify();
	return res;
}

void MinHeap::decreaseVal(int index, int decreVal) {
	
	if (heap[index].key - decreVal<0)
	{
		heap[index].key = 1;
	}
	else
	{
		heap[index].key = heap[index].key - decreVal;
	}
	MinHeap::heapUp(index);
}

