#include "common.h"
#include "verifySort.h"
#include "sort.h"

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

void testInsertSort()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "before sort" << endl;
	printVector(data);
	insertSort(data);
	cout << "after sort" << endl;
	printVector(data);
}

void verifySort()
{
	testMergeSort();
	testInsertSort();
	
}