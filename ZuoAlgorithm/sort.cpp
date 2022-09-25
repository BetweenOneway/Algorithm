#include <time.h>
#include "sort.h"
#include "common.h"

void bubbleSort(vector<int>& toSort)
{
	if (toSort.size() < 2)
	{
		return;
	}
	for (int i = 1; i < toSort.size(); i++)
	{
		for (int j = 1; j < toSort.size() - i + 1; j++)
		{
			if (toSort[j - 1] > toSort[j])
			{
				swap(toSort[j - 1], toSort[j]);
			}
		}
	}
}

void selectSort(vector<int>& toSort)
{
	if (toSort.size() < 2)
	{
		return;
	}
	for (int i = 0; i < toSort.size(); i++)
	{
		int minIndex = i;
		for (int j = i; j < toSort.size(); j++)
		{
			if (toSort[j] < toSort[minIndex])
			{
				minIndex = j;
			}
		}
		swap(toSort[i], toSort[minIndex]);
	}
}

void merge(int startIndex, int endIndex, vector<int>& data)
{
	int size = endIndex - startIndex + 1;
	vector<int> temp(size, 0);
	int mid = startIndex + endIndex >> 1;
	int l = startIndex;
	int r = mid + 1;
	int index = 0;
	while (l <= mid && r <= endIndex)
	{
		if (data[l] < data[r])
		{
			temp[index] = data[l];
			index++;
			l++;
		}
		else
		{
			temp[index] = data[r];
			index++;
			r++;
		}
	}
	if (l <= mid)
	{
		while (l <= mid)
		{
			temp[index] = data[l];
			index++;
			l++;
		}
	}
	if (r <= endIndex)
	{
		while (r <= endIndex)
		{
			temp[index] = data[r];
			index++;
			r++;
		}
	}
	for (int i = startIndex, j = 0; i <= endIndex; i++, j++)
	{
		data[i] = temp[j];
	}
}

//[startIndex,endIndex]
void partition(int startIndex, int endIndex, vector<int>& data)
{
	if (startIndex == endIndex)
	{
		return;
	}
	int mid = startIndex + (endIndex-startIndex >> 1);
	partition(startIndex, mid, data);
	partition(mid + 1, endIndex, data);
	merge(startIndex, endIndex, data);
}

void mergeSort(vector<int>& toSort)
{
	int maxIndex = toSort.size() - 1;
	partition(0, maxIndex, toSort);
}

void insertSort(vector<int>& toSort)
{
	if (toSort.empty() || 1 == toSort.size())
	{
		return;
	}
	for (int i = 1; i < toSort.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (toSort[j] < toSort[j - 1])
			{
				swap(toSort[j], toSort[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}

/*
荷兰国旗问题
以最右侧值为标准
左边的值都小于标准值；中间的值都等于标准值；右边的值都大于标准值
*/
vector<int> netherlandNationalFlag(vector<int>& toSort, int l, int r)
{
	int lessBorder = l - 1;
	int moreBorder = r;
	while (l < moreBorder)
	{
		if (toSort[l]<toSort[r])
		{
			swap(toSort[++lessBorder], toSort[l++]);
		}
		else if (toSort[l] > toSort[r])
		{
			swap(toSort[--moreBorder],toSort[l++]);
		}
		else
		{
			l++;
		}
	}
	swap(toSort[r], toSort[moreBorder]);
	return vector<int>{lessBorder, moreBorder};
}

void quickSort(vector<int>& toSort, int l, int r)
{
	if (l < r)
	{
		//随机任选一个数，放到最右边，作为划分的标准值
		srand(time(0));
		int pos = rand() % (r-l+1) + l;
		swap(toSort[r],toSort[pos]);
		vector<int> result = netherlandNationalFlag(toSort,l,r);
		quickSort(toSort, l, result[0]);
		quickSort(toSort,result[1],r);
	}
}

void quickSort(vector<int>& toSort)
{
	if (toSort.size() < 2)
	{
		return;
	}
	quickSort(toSort, 0, toSort.size() - 1);
}