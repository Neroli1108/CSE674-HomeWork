#pragma once
#include<iostream>

class doubleNode {
public:
	int value;
	doubleNode* prev;
	doubleNode* next;
	doubleNode(int a, doubleNode* b,doubleNode*c) {
		this->value = a;
		this->prev = b;
		this->next = c;
	}
	doubleNode(int a, doubleNode* b) {
		this->value = a;
		this->next = b;
		b->prev = this;
	    
	}
	doubleNode(int a) {
		this->value = a;
		this->next = NULL;
	}
};