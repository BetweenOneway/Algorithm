#include <iostream>
using namespace std;

#define MAXSIZE 10000	/* 用于要排序数组个数最大值，可根据需要修改 */
typedef struct
{
	int r[MAXSIZE];		/* 用于存储要排序数组 */
	int length;			/* 用于记录数组的长度 从1开始 */
}SqList;

void SetListData(SqList *sortList, int iNum)
{
	sortList->r[sortList->length] = iNum;
	sortList->length = sortList->length + 1;
}

void OutputList(SqList *list)
{
	int iIndex = 0;
	for (iIndex = 0; iIndex < list->length; iIndex++)
	{
		cout << list->r[iIndex] << "\t";
	}
	cout << endl;
}

int swap(int *src, int *dest)
{
	*src = *src + *dest;
	*dest = *src - *dest;
	*src = *src - *dest;

	return 0;
}

int Parition(SqList *list,int low,int high)
{
	int key = list->r[low];
	while (low < high)
	{
		while (list->r[high] > key && high > low)
		{
			high--;
		}
		if (high > low)
		{
			swap(list->r[high], list->r[low]);
		}

		while (list->r[low] < key && low < high)
		{
			low++;
		}
		if (low < high)
		{
			swap(list->r[low], list->r[high]);
		}
	}
	//此时low和high是相等的，返回谁都无所谓
	return low;
}

int QuickSort(SqList *toSortList,int iStartIndex,int iEndIndex)
{
	if (iStartIndex < iEndIndex)
	{
		int iPos = Parition(toSortList, iStartIndex, iEndIndex);
		QuickSort(toSortList, iStartIndex, iPos - 1);
		QuickSort(toSortList, iPos + 1, iEndIndex);
	}
	return 0;
}

int main()
{
	SqList SortList;

	SortList.length = 0;
	SetListData(&SortList, 50);
	SetListData(&SortList, 60);
	SetListData(&SortList, 70);
	SetListData(&SortList, 80);
	SetListData(&SortList, 90);
	SetListData(&SortList, 10);
	SetListData(&SortList, 20);
	SetListData(&SortList, 30);
	SetListData(&SortList, 100);
	SetListData(&SortList, 400);
	SetListData(&SortList, 55);
	SetListData(&SortList, 66);

	QuickSort(&SortList,0,SortList.length-1);

	OutputList(&SortList);

	system("pause");
	return 0;
}