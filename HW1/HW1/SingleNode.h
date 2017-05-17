#pragma once
#include<iostream>
class singleNode {

public:
	int value;
	singleNode* next;
	singleNode(int a, singleNode* b) {
		this->value = a;
		next = b;
	}
	singleNode(int a) { this->value = a;
	this->next = NULL;
	}

};