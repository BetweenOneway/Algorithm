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

int ShellSort(SqList *toSortList)
{
	int iIncresement = toSortList->length;
	int iIndex = 0;
	int iLoop = 0;
	int iReserve = 0;

	do
	{
		iIncresement = iIncresement / 3 + 1;
		//iIndex�ĵ�������1
		for (iIndex=0;iIndex<toSortList->length-iIncresement;iIndex++)
		{
			if (toSortList->r[iIndex] > toSortList->r[iIndex+iIncresement])
			{
				iReserve = toSortList->r[iIndex+iIncresement];
				for (iLoop = iIndex;iLoop>=0 && toSortList->r[iLoop] > iReserve;iLoop-= iIncresement)
				{
					toSortList->r[iLoop + iIncresement] = toSortList->r[iLoop];
				}
				//��Ϊ��ʱiLoop�Ѿ��������һ��iIncresement
				toSortList->r[iLoop+iIncresement] = iReserve;
			}
		}
	} while (iIncresement >1);
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

	ShellSort(&SortList);

	OutputList(&SortList);

	system("pause");
	return 0;
}