#include "common.h"
#include <time.h>

void swap(int& i, int& j)
{
	if (i == j)
	{
		return;
	}
	i = i^j;
	j = i^j;
	i = i^j;
}

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