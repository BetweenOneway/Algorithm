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

int Merge(int InputAr[], int OutputAr[], int iStart,int iMid, int iEnd)
{
	int iIndex = 0;
	int iFirLoop = 0;
	int iSecLoop = 0;

	iIndex = iStart;
	for (iFirLoop =iStart, iSecLoop =iMid+1; iFirLoop <=iMid&&iSecLoop<=iEnd;iIndex++)
	{
		if (InputAr[iFirLoop] < InputAr[iSecLoop])
		{
			OutputAr[iIndex] = InputAr[iFirLoop++];
		}
		else
		{
			OutputAr[iIndex] = InputAr[iSecLoop++];
		}
	}
	if (iFirLoop <= iMid)
	{
		for (;iFirLoop<=iMid;iFirLoop++)
		{
			OutputAr[iIndex] = InputAr[iFirLoop];
		}
	}
	if (iSecLoop <=iEnd)
	{
		for (;iSecLoop<=iEnd;iSecLoop++)
		{
			OutputAr[iIndex] = InputAr[iSecLoop];
		}
	}
	return 0;
}
int MSort(int InputAr[],int OutputAr[],int iStart,int iEnd)
{
	if (iStart != iEnd)
	{
		int iMid = (iStart + iEnd) / 2;
		int TempAr[MAXSIZE] = { 0 };
		MSort(InputAr, TempAr, iStart, iMid);
		MSort(InputAr, TempAr, iMid + 1, iEnd);
		Merge(TempAr,OutputAr,iStart,iMid,iEnd);
	}
	else
	{
		OutputAr[iEnd] = InputAr[iStart];
	}
	return 0;
}

int MergeSort(SqList *toSortList)
{
	MSort(toSortList->r, toSortList->r, 0, toSortList->length - 1);
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

	MergeSort(&SortList);
	OutputList(&SortList);

	system("pause");
	return 0;
}