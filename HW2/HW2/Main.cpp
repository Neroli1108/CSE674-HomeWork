//////////////////////////////////////////////////
//File:    Main.cpp								//
//Function: run all tests						//
//Author:Yunding	Li							//
//date: 10/27/2016								//
//////////////////////////////////////////////////

#include"SmSort.h"
#include<algorithm>
#include"PQ.h"
#include<time.h>
#include<stdlib.h>




int main() {


	PQ pq;

	std::cout << "**** First Test Case ****" << std::endl;
	for (int i = 1; i < 101; i++)
	{
		pq.insert(101 - i, i);
	}

	std::cout << "************After Extra_All_Min Operation*************" << std::endl;
	std::vector<PQNode> res = pq.Extra_all_min();
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << "Key: " << res[i].key << " Value: " << res[i].val << std::endl;
	}


	std::cout << "************After second Extra_All_Min Operation*************" << std::endl;
	pq.insert(1, 0);
	res = pq.Extra_all_min();
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << "Key: " << res[i].key << " Value: " << res[i].val << std::endl;
	}



	std::cout << "**** Second Test Case ****" << std::endl;

	pq.Clear();

	for (int i = 1; i < 10001; i++)
	{
		pq.insert(10001 - i, i);
	}

	std::cout << "************After first ALL_Minimum Operation*************" << std::endl;

	res.clear();

	res = pq.All_Minimum();

	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << "Key: " << res[i].key << " Value: " << res[i].val << std::endl;
	}

	std::cout << "************After Extra_ALL_Min Operation*************" << std::endl;

	for (int i = 1; i < 31; i++)
	{
		pq.insert(1, i);
	}

	res.clear();
	res = pq.Extra_all_min();

	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << "Key: " << res[i].key << " Value: " << res[i].val << std::endl;
	}

	std::cout << "************After Second ALL_Minimum Operation*************" << std::endl;
	res.clear();
	res = pq.All_Minimum();
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << "Key: " << res[i].key << " Value: " << res[i].val << std::endl;
	}



	std::cout << "**** Third Test Case ****" << std::endl;
	pq.Clear();
	srand((unsigned)time(NULL));
	for (int i = 0; i < 500; i++)
	{

		int key = rand() % 1000 + 10;
		int val = rand() % 1000 + 10;
		pq.insert(key, val);
	}

	std::cout << "************After Extra_ALL_Min Operation*************" << std::endl;
	res.clear();

	res = pq.Extra_all_min();
	res = pq.Extra_all_min();
	res = pq.Extra_all_min();
	res = pq.Extra_all_min();
	res = pq.Extra_all_min();

	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << "Key: " << res[i].key << " Value: " << res[i].val << std::endl;
	}

	std::cout << "************After All_Minimum Operation*************" << std::endl;

	int index = rand() % (pq.size() - 1);

	pq.decrease_key(index, 5);

	res.clear();

	res = pq.All_Minimum();

	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << "Key: " << res[i].key << " Value: " << res[i].val << std::endl;
	}


	std::cout << "**** Fourth Test Case ****" << std::endl;
	pq.Clear();
	for (int i = 0; i < 500; i++)
	{

		int key = rand() % 1000 + 10;
		int val = rand() % 1000 + 10;
		pq.insert(key, val);
	}
	for (int i = 0; i < 10; i++)
	{
		int index = rand() % (pq.size() - 1);
		int decre = rand() % 9;

		pq.decrease_key(index, decre);
	}

	for (int i = 0; i < 10; i++)
	{
		res.clear();
		res = pq.Extra_all_min();
		std::cout << "This is the " << i + 1 << " times to Etra_All_Min " << std::endl;
		for (size_t j = 0; j < res.size(); j++)
		{
			std::cout << "Key: " << res[j].key << " Value: " << res[j].val << std::endl;
		}
	}

	std::cout << "**** Fifth Test Case ****" << std::endl;
	pq.Clear();
	res.clear();
	int random = 0;







	for (int i = 1; i < 101; i++)
	{
		random = rand() % 4 + 1;
		switch (random)
		{
		case 1:
			pq.insert(rand() % 10000 + 1, rand() % 10000 + 1);
			break;
		case 2:
			if (pq.height() == 0)
				break;
			pq.decrease_key(rand() % pq.height(), rand() % 1000 + 1);
			break;
		case 3:
			pq.All_Minimum();
			break;
		case 4:
			pq.Extra_all_min();
			break;


		default:
			break;
		}
		if (i == 20 || i == 40 || i == 60 || i == 80 || i == 100)
		{
			std::cout << "the operation at " << i << " times:" << std::endl;
			pq.print();
		}
	}


	std::cout << "*****************************sixth Test********************************" << std::endl;
	std::vector<int> res2;

	for (size_t i = 1000; i > 0; i--)
	{
		res2.push_back(i);
	}
	
	std::cout << "*****The total number of the comparisons is " << Smoothsort(res2.begin(), res2.end()) << std::endl;
	
	for (size_t i = 0; i < res2.size();i=i+20)
	{
		std::cout << res2[i] << std::endl;
	}


	std::cout << "*****************************Seventh Test********************************" << std::endl;
	res.clear();
	std::vector<int> num;
	for (size_t i = 1; i < 2001; i++)
	{
		num.push_back(i);
	}
	random_shuffle(num.begin(),num.end());

	for (size_t i = 0; i <20; i++)
	{
		res2.push_back(num[i]);
	}

	for (size_t i = 0; i < 20;i= i+2)
	{
		int temp = res2[i];
		res2[i] = res2[i + 1];
		res2[i + 1] = temp;
	}
	std::cout << "*****The total number of the comparisons is " << Smoothsort(res2.begin(), res2.end()) << std::endl;

	for (size_t i = 0; i < res2.size(); i=i+20)
	{
		std::cout << res2[i] << std::endl;
	}

	std::cout << "*****************************Eighth Test********************************" << std::endl;
	res.clear();
	num.clear();
	for (size_t i = 1; i < 2001; i++)
	{
		num.push_back(i);
	}
	random_shuffle(num.begin(),num.end());
	for (size_t i = 0; i < 60; i++)
	{
		res2.push_back(num[i]);
	}
	for (size_t i = 1; i < res2.size(); i=i+3)
	{
		
		int temp1 = res2[i-1];
		int temp2 = res2[i];
		res2[i-1] = res2[i + 1];
		res2[i] = temp1;
		res2[i + 1] = temp2;
		
		
	}

	std::cout << "*****The total number of the comparisons is " << Smoothsort(res2.begin(), res2.end()) << std::endl;

	for (size_t i = 0; i < res.size(); i = i + 20)
	{
		std::cout << res2[i] << std::endl;
	}

	std::cout << "*****************************Nineth Test********************************" << std::endl;
	res2.clear();
	num.clear();
	
	for (size_t i = 1; i < 10000; i++)
	{
		num.push_back(i);
	}
	random_shuffle(num.begin(), num.end());
	for (size_t i = 0; i < 3193; i++)
	{
		res2.push_back(num[i]);
	}
	std::cout << "*****The total number of the comparisons is " << Smoothsort(res2.begin(), res2.end()) << std::endl;
	for (size_t i = 0; i < res2.size(); i = i + 20)
	{
		std::cout << res2[i] << std::endl;
	}

	std::cout << "*****************************Tenth Test********************************" << std::endl;
	res2.clear();
	num.clear();
	for (size_t i = 1; i < 10000; i++)
	{
		num.push_back(i);
	}
	random_shuffle(num.begin(), num.end());
	for (size_t i = 0; i < 5166; i++)
	{
		res2.push_back(num[i]);
	}
	std::cout << "*****The total number of the comparisons is " << Smoothsort(res2.begin(), res2.end()) << std::endl;
	for (size_t i = 0; i < res2.size(); i = i + 20)
	{
		std::cout << res2[i] << std::endl;
	}

}