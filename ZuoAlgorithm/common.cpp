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

void swap(string& src, int srcPos, int destPos)
{
	char temp = src[srcPos];
	src[srcPos] = src[destPos];
	src[destPos] = temp;
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