#include<iostream>
#include"Operation.h"


singleNode* operation::sort(singleNode*head) {
	if (head == NULL || head->next == NULL)return head;
	singleNode *p = head->next, *pstart = new singleNode(0), *pend = head;
	pstart->next = head; //为了操作方便，添加一个头结点
	singleNode* save = new singleNode(0);
	singleNode* res = new singleNode(0);
	int count = 1;
	int ope = 0;
	while (p != NULL)
	{
		ope++;
		while (count<4&&p!=NULL) {
			singleNode *tmp = pstart->next, *pre = pstart;
			while (tmp != p && p->value >= tmp->value) //找到插入位置
			{
				tmp = tmp->next; pre = pre->next;
			}
			if (tmp == p) { pend = p; }
			else
			{
				pend->next = p->next;
				p->next = tmp;
				pre->next = p;

			}
			p = pend->next;
			count++;
		}
		if (ope == 1)
		{
			head = pstart->next;
			save->next = head;
			res->next = head;
		}
		if (ope>1)
		{
			singleNode* pre = head->next->next->next;
			head = head->next->next->next->next;
			head = pstart->next;
			pre->next = head;
		}
		if (p == NULL)
		{
			break;
		}
		save = pstart->next->next->next->next->next;
		pstart->next = save;
		pend = pstart->next; // new
		p = pstart->next->next;
		
		count = 1;
	}
	delete pstart;
	return res->next;
}

singleNode* operation::reverse(singleNode*head) {
	singleNode* pre;
	singleNode* cur = head;
	singleNode* next = head->next;
	cur->next = NULL;
	pre = cur;
	cur = next;
	next = next->next;
	cur->next = pre;
	while (next!=NULL)
	{
		
		pre = cur;
		cur = next;
		next = next->next;
		cur->next = pre;

	}
	return cur;
}

singleNode* operation::shuffle(singleNode*head) {
	singleNode* cur = head;
	singleNode* next = head->next;
	if (next == NULL)
		return head;
	int number = 1;
	while (next!=NULL)
	{
		number++;
		next = next->next;
	}

	number = ceil(number/2);
	singleNode* head1,*head2;
	head1 = head;
	while (number!=0)
	{
		if (number == 1)
		{
			next = head;
		}
		head = head->next;
		number--;
		if (number == 0)
		{
			next->next = NULL;
		}
		

	}
	head2 = head;
	singleNode* res = new singleNode(0);
	res->next = head2;
	cur = res->next;
	head2 = head2->next;
	while (head1!=NULL&&head2!=NULL)
	{
		cur->next = head1;
		head1 = head1->next;
		cur = cur->next;
		cur->next = head2;
		head2 = head2->next;
		cur = cur->next;
	}
	if (head1 == NULL)
	{
		
			cur->next = head2;
		
	}
	else if (head2 == NULL)
	{
		
			cur->next = head1;
		
	}
	
	return res->next;

}

void operation::outputForShuffle(singleNode*head) {
	singleNode* cur = head;
	singleNode* next = head->next;
	int count = 1;
	int number = 1;
	std::cout << "***** Before the operation *****" <<std::endl;
	while (next != NULL)
	{
		number++;
		next = next->next;
	}

	number = ceil(number / 2)+1;

	next = head->next;

	std::cout << "** First Half **" << "\n";

	while (number!=1)
	{
		while (count<4 && next != NULL&&number != 1)
		{
			std::cout << cur->value << "->";
			cur = next;
			next = next->next;
			count++;
			number--;

		}
		if (number == 1)
		{
			break;
		}
		count = 1;
		std::cout << cur->value << "\n";
		number--;
		cur = next;
		if (cur == NULL)
		{
			break;
		}

		next = next->next;

		if (next == NULL)
		{
			std::cout << cur->value << "\n";
			number--;
		}
		

	}

	std::cout << cur->value << "\n";

	cur = next;
	next = next->next;
	count = 1;
	std::cout << "** Second Half **" << "\n";
	while (next != NULL)
	{
		while (count<4 && next != NULL)
		{
			std::cout << cur->value << "->";
			cur = next;
			next = next->next;
			count++;

		}

		count = 1;
		std::cout << cur->value << "\n";
		cur = next;
		if (cur == NULL)
		{
			break;
		}

		next = next->next;

		if (next == NULL)
		{
			std::cout << cur->value << "\n";
		}


	}

	std::cout << "***** After the operation *****" << std::endl;
	head=operation::shuffle(head);
	operation::output(head);
}

void operation::output(singleNode*head){


	singleNode* cur = head;
	singleNode* next = head->next;
	int count = 1;

	while (next!=NULL)
	{
		while (count<4&&next!=NULL)
		{
			std::cout << cur->value << "->";
			cur = next;
			next = next->next;
			count++;

		}
		
		count = 1;
		std::cout << cur->value<<"\n";
		cur = next;
		if (cur==NULL)
		{
			break;
		}
	
		next = next->next;

		if (next == NULL)
		{
			std::cout << cur->value << "\n";
		}
	
		
	}
	

}


doubleNode* operation::sort(doubleNode*head) {
	if (head == NULL || head->next == NULL)return head;
	doubleNode *p = head->next, *pstart = new doubleNode(0), *pend = head;
	pstart->next = head; //为了操作方便，添加一个头结点
	doubleNode* save = new doubleNode(0);
	doubleNode* res = new doubleNode(0);
	int count = 1;
	int ope = 0;
	while (p != NULL)
	{
		ope++;
		while (count<4 && p != NULL) {
			doubleNode *tmp = pstart->next, *pre = pstart;
			while (tmp != p && p->value >= tmp->value) //找到插入位置
			{
				tmp = tmp->next; pre = pre->next;
			}
			if (tmp == p) { pend = p; }
			else
			{
				pend->next = p->next;
				if (p->next!=NULL)
				{
					p->next->prev = pend; //new
				}
				
				p->next = tmp;
				tmp->prev = p;
				pre->next = p;
				if (pre->value!=0)
				{
					p->prev = pre;
				}
				

			}
			p = pend->next;
			count++;
		}
		if (ope == 1)
		{
			head = pstart->next;
			save->next = head;
			res->next = head;
			head->prev = NULL;
		}
		if (ope>1)
		{
			doubleNode* pre = head->next->next->next;
			head = head->next->next->next->next;
			head = pstart->next;
			pre->next = head;
		}
		if (p == NULL)
		{
			break;
		}
		save = pstart->next->next->next->next->next;
		pstart->next = save;
		pend = pstart->next; // new
		p = pstart->next->next;

		count = 1;
	}
	delete pstart;
	return res->next;
}

doubleNode* operation::reverse(doubleNode*head) {

	doubleNode *temp = NULL;
	doubleNode *cur = head;

	/* swap next and prev for all nodes of
	doubly linked list */
	while (cur != NULL)
	{
		temp = cur->prev;
		cur->prev = cur->next;
		cur->next = temp;
		cur = cur->prev;
	}

	/* Before changing head, check for the cases like empty
	list and list with only one node */
	if (temp != NULL)
		head = temp->prev;

	return head;
}

doubleNode* operation::shuffle(doubleNode*head) {
	doubleNode* cur = head;
	doubleNode* next = head->next;
	if (next == NULL)
		return head;
	int number = 1;
	while (next != NULL)
	{
		number++;
		next = next->next;
	}

	number = ceil(number / 2);
	doubleNode* head1, *head2;
	head1 = head;
	while (number != 0)
	{
		if (number == 1)
		{
			next = head;
		}
		head = head->next;
		number--;
		if (number == 0)
		{
			next->next = NULL;
		}


	}
	head2 = head;
	doubleNode* res = new doubleNode(0);
	res->next = head2;
	cur = res->next;
	head2 = head2->next;
	while (head1 != NULL&&head2 != NULL)
	{
		cur->next = head1;
		head1->prev = cur;
		head1 = head1->next;
		cur = cur->next;
		cur->next = head2;
		head2->prev = cur;
		head2 = head2->next;
		cur = cur->next;
	}
	if (head1 == NULL)
	{

		cur->next = head2;
		head2->prev = cur;

	}
	else if (head2 == NULL)
	{

		cur->next = head1;
		head1->prev = cur;

	}
	res->next->prev = NULL;

	return res->next;

}

void operation::outputForShuffle(doubleNode*head) {
	doubleNode* cur = head;
	doubleNode* next = head->next;
	int count = 1;
	int number = 1;
	std::cout << "***** Before the operation *****" << std::endl;
	while (next != NULL)
	{
		number++;
		next = next->next;
	}

	number = ceil(number / 2) + 1;

	next = head->next;

	std::cout << "** First Half **" << "\n";

	while (number != 1)
	{
		while (count<4 && next != NULL&&number != 1)
		{
			std::cout << cur->value << "->";
			cur = next;
			next = next->next;
			count++;
			number--;

		}
		if (number == 1)
		{
			break;
		}
		count = 1;
		std::cout << cur->value << "\n";
		number--;
		cur = next;
		if (cur == NULL)
		{
			break;
		}

		next = next->next;

		if (next == NULL)
		{
			std::cout << cur->value << "\n";
			number--;
		}


	}

	std::cout << cur->value << "\n";

	cur = next;
	next = next->next;
	count = 1;
	std::cout << "** Second Half **" << "\n";
	while (next != NULL)
	{
		while (count<4 && next != NULL)
		{
			std::cout << cur->value << "->";
			cur = next;
			next = next->next;
			count++;

		}

		count = 1;
		std::cout << cur->value << "\n";
		cur = next;
		if (cur == NULL)
		{
			break;
		}

		next = next->next;

		if (next == NULL)
		{
			std::cout << cur->value << "\n";
		}


	}

	std::cout << "***** After the operation *****" << std::endl;
	head = operation::shufflebyvector(head);
	operation::output(head);
}

singleNode* operation::shufflebyvector(singleNode* head) {
	std::vector<singleNode*> one;
	singleNode* cur = head;
	singleNode* next = head->next;
	while (next!=NULL)
	{
		one.push_back(cur);
		cur = next;
		next = next->next;
	}
	one.push_back(cur);

	random_shuffle(one.begin(),one.end());

	for (int i = 0; i < one.size()-1; i++)
	{
		one[i]->next = one[i+1];
	}
	one[one.size() - 1]->next = NULL;
	head = one[0];
	return head;
}


doubleNode* operation::shufflebyvector(doubleNode* head) {
	std::vector<doubleNode*> one;
	doubleNode* cur = head;
	doubleNode* next = head->next;
	while (next != NULL)
	{
		one.push_back(cur);
		cur = next;
		next = next->next;
	}
	one.push_back(cur);

	random_shuffle(one.begin(), one.end());
	one[0]->prev = NULL;
	one[0]->next = one[1];
	one[1]->prev = one[0];

	for (int i = 1; i < one.size() - 1; i++)
	{
		one[i]->next = one[i + 1];
		one[i + 1]->prev = one[i];
	}
	one[one.size() - 1]->next = NULL;
	head = one[0];
	return head;
}


void operation::output(doubleNode*head) {


	doubleNode* cur = head;
	doubleNode* next = head->next;
	int count = 1;

	while (next != NULL)
	{
		while (count<4 && next != NULL)
		{
			std::cout << cur->value << "->";
			cur = next;
			next = next->next;
			count++;

		}

		count = 1;
		std::cout << cur->value << "\n";
		cur = next;
		if (cur == NULL)
		{
			break;
		}

		next = next->next;

		if (next == NULL)
		{
			std::cout << cur->value << "\n";
		}


	}


}

singleNode* operation::constructSingleList(singleNode*head, int a) {

	singleNode* cur = head;
	singleNode* next = cur->next;

	while (next!=NULL)
	{
		cur = cur->next;
		next = next->next;
	}
	if (next == NULL)
	{
		next = new singleNode(a);
		cur->next = next;
	}
	return head;
}

doubleNode* operation::constructDoubleList(doubleNode*head, int a) {

	doubleNode* cur = head;
	doubleNode* next = cur->next;

	while (next != NULL)
	{
		cur = cur->next;
		next = next->next;
	}
	if (next == NULL)
	{
		next = new doubleNode(a);
		next->prev = cur;
		cur->next = next;
	}
	return head;
}




void operation::randomGenerate(int Num,std::vector<int> &temp)
{
	
	for (int i = 1; i < Num; ++i)
	{
		temp.push_back(i + 1);
	}

	random_shuffle(temp.begin(), temp.end());
 
}



int main() {
	//singleNode* root = new singleNode(2, new singleNode(3, new singleNode(1, new singleNode(6, new singleNode(8,new singleNode(5,new singleNode(7,new singleNode(13,new singleNode(0,new singleNode(3, new singleNode(2, new singleNode(1, new singleNode(6)))))))))))));
	operation ok;
	//root = ok.reverse(root);
	//std::cout << "before the shuffle operation:" << "\n";
	//ok.output(root);
	//root = ok.shuffle(root);
	//std::cout << "after the shuffle operation" << "\n";
	//ok.output(root);
	//ok.outputForShuffle(root);

	//doubleNode* root = new doubleNode(2, new doubleNode(3, new doubleNode(1, new doubleNode(6, new doubleNode(8)))));
	
	//std::vector<int> test;

	//ok.randomGenerate(10, test);

	//for (int i = 0; i < test.size(); i++)
	//{
	//	std::cout << test[i] << std::endl;
	//}
	int count = 1;
	std::vector<int> random;
	ok.randomGenerate(100, random);
	doubleNode* s2root = new doubleNode(1);

	while (count != 10)
	{

		count++;
		s2root = ok.constructDoubleList(s2root, random[count]);
		
	}

	ok.output(s2root);
	std::cout << "*******************************************************************" << std::endl;


	s2root = ok.shuffle(s2root);
	ok.output(s2root);


	//int count = 0;
	//doubleNode* root = new doubleNode(0);

	//while (count!=100)
	//{
	//	count++;
	//	root = ok.constructDoubleList(root, count);
	//}

	//ok.output(root);

	//ok.outputForShuffle(root);
	system("pause");
	
}