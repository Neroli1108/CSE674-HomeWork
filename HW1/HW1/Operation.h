#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"SingleNode.h"
#include"HW1\doubleNode.h"

class operation {
public:
	singleNode* sort(singleNode*head);
	void output(singleNode*head);
	singleNode* reverse(singleNode*head);
	void outputForShuffle(singleNode* head);
	doubleNode* sort(doubleNode*head);
	void output(doubleNode*head);
	doubleNode* reverse(doubleNode*head);
	void outputForShuffle(doubleNode* head);
	singleNode* constructSingleList(singleNode*head,int a);
	doubleNode* constructDoubleList(doubleNode*head, int a);
	void randomGenerate(int a, std::vector<int> &b);
	singleNode* shufflebyvector(singleNode* head);
	doubleNode* shufflebyvector(doubleNode* head);
	doubleNode* shuffle(doubleNode*head);

private:
	singleNode* shuffle(singleNode*head);
	//doubleNode* shuffle(doubleNode*head);
	
};