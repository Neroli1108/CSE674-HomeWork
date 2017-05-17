#include<iostream>
#include"../Operation.h"

int main() {

	int count = 1;
	operation ok;

	//construct the list
	std::vector<int> random;
	ok.randomGenerate(100, random);
	//sequence 1
	singleNode* s1root = new singleNode(1);
	doubleNode* d1root = new doubleNode(1);
	//sequence 2
	singleNode* s2root = new singleNode(1);
	doubleNode* d2root = new doubleNode(1);

	while (count!=100)
	{
		count++;
		d1root = ok.constructDoubleList(d1root, count);
		s1root = ok.constructSingleList(s1root, count);
	}

	count = 0;
	while (count!=99)
	{
		
		d2root = ok.constructDoubleList(d2root, random[count]);
		s2root = ok.constructSingleList(s2root, random[count]);
		count++;
	}

	std::cout << "***** Before the operation *****" << "\n";
	std::cout << "***** S1 singleList *****" << std::endl;
	ok.output(s1root);
	std::cout << "***** S1 doubleList *****" << std::endl;
	ok.output(d1root);
	std::cout << "***** S2 singleList *****" << std::endl;
	ok.output(s2root);
	std::cout << "***** S2 doubleList *****" << std::endl;
	ok.output(d2root);

	std::cout << "***** team of four operation *****" << "\n";
	std::cout << "***** S1 singleList *****" << std::endl;
	ok.output(ok.sort(s1root));
	std::cout << "***** S1 doubleList *****" << std::endl;
	ok.output(ok.sort(d1root));
	std::cout << "***** S2 singleList *****" << std::endl;
	ok.output(ok.sort(s2root));
	std::cout << "***** S2 doubleList *****" << std::endl;
	ok.output(ok.sort(d2root));


	std::cout << "***** the reverse operation *****" << "\n";
	std::cout << "***** S1 singleList *****" << std::endl;
	s1root= ok.reverse(s1root);
	ok.output(s1root);
	s1root = ok.reverse(s1root);
	std::cout << "***** S1 doubleList *****" << std::endl;
	d1root = ok.reverse(d1root);
	ok.output(d1root);
	d1root = ok.reverse(d1root);
	std::cout << "***** S2 singleList *****" << std::endl;
	s2root = ok.reverse(s2root);
	ok.output(s2root);
	s2root = ok.reverse(s2root);
	std::cout << "***** S2 doubleList *****" << std::endl;
	d2root = ok.reverse(d2root);
	ok.output(d2root);
	d2root = ok.reverse(d2root);

	std::cout << "***** the shuffle operation *****" << "\n";
	std::cout << "***** S1 singleList *****" << std::endl;
	ok.outputForShuffle(s1root);
	std::cout << "***** S1 doubleList *****" << std::endl;
	ok.outputForShuffle(d1root);
	std::cout << "***** S2 singleList *****" << std::endl;
	ok.outputForShuffle(s2root);
	std::cout << "***** S2 doubleList *****" << std::endl;
	ok.outputForShuffle(d2root);


	

	
	system("pause");

}