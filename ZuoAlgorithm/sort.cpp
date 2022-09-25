#include "sort.h"



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
	int minIndex = toSort.size() - 1;
	partition(0, minIndex, toSort);
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