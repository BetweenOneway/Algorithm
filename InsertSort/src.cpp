#include <iostream>
using namespace std;

#define MAXSIZE 10000	/* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
typedef struct
{
	int r[MAXSIZE];		/* ���ڴ洢Ҫ�������� */
	int length;			/* ���ڼ�¼����ĳ��� ��1��ʼ */
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
			//��Ϊ�����һ���ƶ���ʱ��Ὣ�����ݸ���
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