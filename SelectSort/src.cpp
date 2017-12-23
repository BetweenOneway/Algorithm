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

int SelectSort(SqList *toSortList)
{
	int iIndex = 0;
	int iMin = 0;
	for (iIndex =0;iIndex <toSortList->length;iIndex++)
	{
		iMin = iIndex;
		int jIndex = 0;
		for (jIndex = iIndex;jIndex < toSortList->length;jIndex++)
		{
			if (toSortList->r[jIndex] < toSortList->r[iMin])
			{
				iMin = jIndex;
			}
		}
		if (iMin != iIndex)
		{
			swap(toSortList->r[iIndex], toSortList->r[iMin]);
		}
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

	SelectSort(&SortList);

	OutputList(&SortList);

	system("pause");
	return 0;
}