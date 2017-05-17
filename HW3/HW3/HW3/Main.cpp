#include<iostream>
#include<vector>
#include"2DTree.h"
#include"BST.h"
#include <time.h>
#include<cmath>
#include<map>
#include<algorithm>


int main() {
	/*std::map<int, int> list1;*/
	std::vector<int> key;
	BST t;
	std::cout << "************TEST CASE FOR THE SHOW FUNCTION******************" << std::endl;
	std::cout << "********************CASE1 TEST BINARY SEARCH TREE*********************************" << std::endl;
	key.push_back(0);
	/*list1[key[0]] = 0;*/
	key.push_back(1000);
	/*list1[key[1]] = 1;*/
	for (int i = 2; i < 16; i++)
	{
		key.push_back( floor((key[i - 1] + key[i - 2]) / 2));
	/*	list1[key[i]] = i;*/
		
	}

	for (int i = 0; i < key.size(); i++)
	{
		t.insert(key[i], i);
	}

	FILE* pfile;
	int err= fopen_s(&pfile, "t1.dot", "w+");
	if (err == 0)
	{
		printf("The file  was opened\n");
	}
	else
	{
		printf("The file  was not opened\n");
	}

	t.bst_print_dot(t.root,pfile);

	std::cout << "********************CASE2 TEST 2D TREE*********************************" << std::endl;
	/*std::map<int, int> list2;*/
	KdTree k;
	std::vector<int> key2;
	key2.push_back(0);
	/*list2[key2[0]] = 0;*/
	key2.push_back(500);
	/*list2[key2[1]] = 1;*/
	for (int i = 2; i < 16; i++)
	{
		key2.push_back(floor((key2[i - 1] + key2[i - 2]) / 2));
		/*list2[key2[i]] = i;*/
	}

	for (int i = 0; i < key2.size(); i++)
	{
		k.insert(key2[i], 500 - key2[i], i);
	}
	
	err = fopen_s(&pfile, "t2.dot", "w+");
	if (err == 0)
	{
		printf("The file  was opened\n");
	}
	else
	{
		printf("The file  was not opened\n");
	}

	k.bst_print_dot(k.root, pfile);

	std::cout << "************TEST CASE FOR THE Height Computations******************" << std::endl;
	std::cout << "********************CASE3 TEST BINARY SEARCH TREE*********************************" << std::endl;
	BST t2;
	srand(time(NULL));
	for (int i = 0; i < 201; i++)
	{
		if (i%20 == 0)
		{
			if (i == 0)
			{
				std::cout << " n = " << i << " Height of BST = " << t2.Height() << " lgn = " << "N.A" << " Sqrt = " << sqrt(i) << std::endl;
			}
			else
			{
				std::cout << " n = " << i << " Height of BST = " << t2.Height() << " lgn = " << log2(i) << " Sqrt = " << sqrt(i) << std::endl;
			}
			
		}
		t2.insert(rand() % 1000, rand() % 1000);
	}

	std::cout << "********************CASE4 TEST 2D TREE*********************************" << std::endl;
	KdTree k2;
	srand(time(NULL));
	for (int i = 0; i < 201; i++)
	{
		if (i % 20 == 0)
		{
			if (i == 0)
			{
				std::cout << " n = " << i << " Height of BST = " << k2.Height() << " lgn = " << "N.A" << " Sqrt = " << sqrt(i) << std::endl;
			}
			else
			{
				std::cout << " n = " << i << " Height of BST = " << k2.Height() << " lgn = " << log2(i) << " Sqrt = " << sqrt(i) << std::endl;
			}

		}
		k2.insert(rand() % 51, rand() % 51, i);
	}
	
	std::cout << "************TEST CASE FOR THE OPERATIONS INSERT AND DELETE******************" << std::endl;
	std::cout << "********************CASE5 TEST BINARY SEARCH TREE*********************************" << std::endl;
	BST t3;
	std::vector<int> a = {0,1000,500,750,625,687,656,671,663,667,665,666};
	std::map<int, int> b;
	for (int i = 0; i < a.size(); i++)
	{
		b[a[i]] = i;
	}

	std::random_shuffle(a.begin(), a.end());

	for (int i = 0; i < 10; i++)
	{
		t3.insert(a[i], b[a[i]]);
	}

	err = fopen_s(&pfile, "t5-a.dot", "w+");
	if (err == 0)
	{
		printf("The file  was opened\n");
	}
	else
	{
		printf("The file  was not opened\n");
	}

	t3.bst_print_dot(t3.root, pfile);

	t3.deleteNode(t3.root->key);
	
	err = fopen_s(&pfile, "t5-b.dot", "w+");
	if (err == 0)
	{
		printf("The file  was opened\n");
	}
	else
	{
		printf("The file  was not opened\n");
	}

	t3.bst_print_dot(t3.root, pfile);
	std::cout << "********************CASE6 TEST 2D TREE*********************************" << std::endl;
	std::vector<int> c = { 0,500,250,375,312,343,327,335,331,333,332};
	std::map<int, int> d;
	for (int i = 0; i < c.size(); i++)
	{
		d[c[i]] = i;
	}
	KdTree k3;
	
	std::random_shuffle(c.begin(), c.end());

	for (int i = 0; i < 10; i++)
	{
		k3.insert(c[i],500- c[i],d[c[i]]);
	}

	err = fopen_s(&pfile, "t6-a.dot", "w+");
	if (err == 0)
	{
		printf("The file  was opened\n");
	}
	else
	{
		printf("The file  was not opened\n");
	}

	k3.bst_print_dot(k3.root, pfile);

	k3.deleteNode(k3.root->Xkey,k3.root->Ykey);
	k3.update();

	err = fopen_s(&pfile, "t6-b.dot", "w+");
	if (err == 0)
	{
		printf("The file  was opened\n");
	}
	else
	{
		printf("The file  was not opened\n");
	}
	k3.bst_print_dot(k3.root, pfile);

	std::cout << "************TEST CASE FOR THE OPERATIONS INSERT AND DELETE AND SEARCH WHERE HAVE DUPLICATE KEY******************" << std::endl;
	std::cout << "********************CASE7 TEST BINARY SEARCH TREE*********************************" << std::endl;
	BST t4;
	std::vector<int> list7;
	int search;
	int count = 0;
	
		list7.push_back(1000);
		list7.push_back(500);
		for (int i = 2; i < 10; i++)
		{
			list7.push_back(floor((key[i - 1] + key[i - 2]) / 2));
		}
		list7.push_back(1000);
		list7.push_back(500);
		for (int i = 12; i < 20; i++)
		{
			list7.push_back(floor((key[i - 11] + key[i - 12]) / 2));
		}
	

	for (int i = 0; i < 20; i++)
	{
		t4.insert(list7[i], i+1);
	}


	while (count<21)
	{
		std::cout << " Stage " << count << std::endl;
		if (t4.root != NULL)
		{
			std::cout << " data item at root " << " Key: " << t4.root->key << " Data: " << t4.root->data << std::endl;
		}
		else
		{
			std::cout << " data item at root " << " Key: " << "nil" << " Data: " << "nil" << std::endl;
		}
		
		if (t4.root != NULL)
		{
		search = t4.root->key;
		t4.deleteNode(t4.root->key);
		}
		if (t4.root!= NULL)
		{
			std::cout << " data item at root(after deletion) " << " Key: " << t4.root->key << " Data: " << t4.root->data << std::endl;
		}
		else
		{
			std::cout << " data item at root(after deletion) " << " Key: " << "nil" << " Data: " <<"nil" << std::endl;
		}

		
		if (t4.search(search)!=NULL)
		{
			std::cout << " search for data with key " << " Key: " << t4.search(search)->key << " Data: " << t4.search(search)->data << std::endl;
		}
		else
		{
			std::cout << " search for data with key " << " it not exists " << std::endl;
		}
		if (count == 10)
		{
			err = fopen_s(&pfile, "t7.dot", "w+");
			if (err == 0)
			{
				printf("The file  was opened\n");
			}
			else
			{
				printf("The file  was not opened\n");
			}
			t4.bst_print_dot(t4.root, pfile);
		}
		count++;
	}

	std::cout << "********************CASE8 TEST 2D TREE*********************************" << std::endl;

	KdTree k4;
	for (int i = 1; i < 7; i++)
	{
		k4.insert(key2[i], 500 - key2[i], i+1);
	}
	for (int i = 7; i < 13; i++)
	{
		k4.insert(key2[i - 6], 500 - key2[i], i);
	}
	for (int i = 13; i < 18; i++)
	{
		k4.insert(key2[i - 6], 500 - key2[i - 12], i);
	}
	int i = 1;
	int num = 18;
	while (k4.root!= NULL) {
		k4.deleteNode(k4.root->Xkey, k4.root->Ykey);
		k4.update();
		num--;
		
		if (i>0&&i<7)
		{
			if (k4.search(key2[i], 500 - key2[i])!=NULL)
			{
				std::cout << " Search the node: " << " Key is " << k4.search(key2[i], 500 - key2[i])->Xkey << "&" << k4.search(key2[i], 500 - key2[i])->Ykey << " Data is " << k4.search(key2[i], 500 - key2[i])->data << std::endl;
			}
			else
			{
				std::cout << " what you search does not exist! " << std::endl;
			}
		}
		else if (i<13)
		{
			if (k4.search(key2[i-6], 500 - key2[i]) != NULL)
			{
				std::cout << " Search the node: " << " Key is " << k4.search(key2[i - 6], 500 - key2[i])->Xkey << "&" << k4.search(key2[i - 6], 500 - key2[i])->Ykey << " Data is " << k4.search(key2[i - 6], 500 - key2[i])->data << std::endl;
			}
			else
			{
				std::cout << " what you search does not exist! " << std::endl;
			}
		}
		else
		{
			if (k4.search(key2[i -6], 500 - key2[i-12]) != NULL)
			{
				std::cout << " Search the node: " << " Key is " << k4.search(key2[i - 6], 500 - key2[i - 12])->Xkey << "&" << k4.search(key2[i - 6], 500 - key2[i - 12])->Ykey << " Data is " << k4.search(key2[i - 6], 500 - key2[i - 12])->data << std::endl;
			}
			else
			{
				std::cout << " what you search does not exist! " << std::endl;
			}
		}
		i++;
		if (num == 12)
		{
			err = fopen_s(&pfile, "t8-a.dot", "w+");
			if (err == 0)
			{
				printf("The file  was opened\n");
			}
			else
			{
				printf("The file  was not opened\n");
			}
			k4.bst_print_dot(k4.root, pfile);
		}

		if (num == 6)
		{
			err = fopen_s(&pfile, "t8-b.dot", "w+");
			if (err == 0)
			{
				printf("The file  was opened\n");
			}
			else
			{
				printf("The file  was not opened\n");
			}
			k4.bst_print_dot(k4.root, pfile);
		}
	}
	system("pause");
}