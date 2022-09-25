#include "examic_questions.h"
/*
*一个数出现奇数次，其余出现偶数次，找到这个数
*/
int getOccurenceOddNumber(vector<int> inputData)
{
	int result = 0;
	for (int i : inputData)
	{
		result = result ^ i;
	}
	return result;
}
/*
* 两个不同的数出现奇数次，其余均出现偶数次，找到这两个数
*/
vector<int> get2OccurenceOddNumber(vector<int> inputData)
{
	int result = 0;
	for (int i : inputData)
	{
		result = result ^ i;
	}
	int bit1 = result & (~result + 1);
	int result1 = 0;
	for (int i : inputData)
	{
		if (i & bit1)
		{
			result1 = result1 ^ i;
		}
	}
	result = result ^ result1;
	return vector<int>{result, result1};
}