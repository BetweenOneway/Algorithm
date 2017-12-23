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

int InsertSort(SqList *toSortList)
{
	int iIndex = 0;
	int iReserve = 0;
	int iLoop = 0;

	for (iIndex = 1 ;iIndex < toSortList->length;iIndex++)
	{
		if (toSortList->r[iIndex] < toSortList->r[iIndex-1])
		{
			//因为后面第一次移动的时候会将该数据覆盖
			iReserve = toSortList->r[iIndex];
			for (iLoop = iIndex-1; iLoop >= 0; iLoop--)
			{
				if (toSortList->r[iLoop] > iReserve)
				{
					toSortList->r[iLoop + 1] = toSortList->r[iLoop];
				}
				else
				{
					break;
				}
			}
			toSortList->r[iLoop+1] = iReserve;
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
	SetListData(&SortList, 55);
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

	InsertSort(&SortList);

	OutputList(&SortList);

	system("pause");
	return 0;
}