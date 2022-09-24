#include <iostream>
#include <algorithm>
#include "sort.h"
using namespace std;

#include <time.h>

void printVector(vector<int>& dataSource)
{
	auto f = [](int it) {cout << it << " "; };
	for_each(dataSource.begin(), dataSource.end(), f);
	cout << endl;
}

void generateVerifyData(vector<int>& dataSource, int minNum, int maxNum, unsigned int num)
{
	int range = maxNum - minNum + 1;
	srand(time(0));
	for (unsigned int i = 0; i < num; i++)
	{
		int generatedValue = rand() % range + minNum;
		dataSource.push_back(generatedValue);
	}
}
void testBubbleSort()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "before sort" << endl;
	printVector(data);
	bubbleSort(data);
	cout << "after sort" << endl;
	printVector(data);
}

void testSelectSort()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "before sort" << endl;
	printVector(data);
	selectSort(data);
	cout << "after sort" << endl;
	printVector(data);
}

void testMergeSort()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "before sort" << endl;
	printVector(data);
	mergeSort(data);
	cout << "after sort" << endl;
	printVector(data);
}

int main()
{
	testMergeSort();
	
	system("pause");
	return 0;
}