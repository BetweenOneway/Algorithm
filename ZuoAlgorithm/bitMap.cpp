#include "bitMap.h"

BitMap::BitMap()
{
	arr.resize(10, 0);
}

//获取第n位的状态
int BitMap::getBitStatus(int n)
{
	int numIndex = n / 32;
	int bitIndex = n % 32;
	return arr[numIndex] >> bitIndex & 1;
}

//将第n位设置为1或0
bool BitMap::setBitStatus(int n,bool flag)
{
	int numIndex = n / 32;
	int bitIndex = n % 32;
	if (flag)
	{
		arr[numIndex] = arr[numIndex] & (1 << bitIndex);
	}
	else
	{
		arr[numIndex] = arr[numIndex] & (~(1 << bitIndex));
	}
	return true;
}