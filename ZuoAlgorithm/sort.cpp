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
			//这里l++是因为两种情况
			//1种换的值紧邻左侧小于区，还完之后，l指向小于区内的最右侧值，所以换完之后要+1
			//第二种，不靠近，则换过来的值一定属于等于区，且已经比较过了，所以也要+1
			swap(toSort[++lessBorder], toSort[l++]);
		}
		else if (toSort[l] > toSort[r])
		{
			//这里的l不能++
			//因为这里还完了之后原来右侧边界的那个值(原来moreBorder指向的值)并没有判断过
			//所以l不能++
			//或者说针对大于区域的交换，是换了个未知的数到l位置上，所以l不能++
			swap(toSort[--moreBorder],toSort[l]);
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

class BigRootHeap
{
private:
	vector<int> heap;
public:
	BigRootHeap() = default;
	void HeapInsert(int val);
	void Heapify();
	int popTop();
};

void BigRootHeap::HeapInsert(int val)
{
	heap.push_back(val);
	int index = heap.size()-1;
	while (heap[index] > heap[(index - 1) / 2])
	{
		swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
void BigRootHeap::Heapify()
{
	int startIndex = 0;
	int left = startIndex * 2 + 1;
	while (left < heap.size())
	{
		int largest = left;
		//如果存在右节点，则先比较左右两个子节点，取较大的节点
		if (left + 1 < heap.size())
		{
			largest = heap[left] > heap[left + 1] ? left : left + 1;
		}
		//将左右节点中的较大值和父节点比较，取较大的那个
		largest = heap[startIndex] > heap[largest] ? startIndex : largest;
		if (largest == startIndex)
		{
			break;
		}
		swap(heap[startIndex], heap[largest]);
		startIndex = largest;
		left = startIndex * 2 + 1;
	}
}
int BigRootHeap::popTop()
{
	int ret = heap[0];
	int lastChild = heap.size() - 1;
	//需要先将要删除的节点挪到最后，然后删除最后的节点
	//如果直接删除第一个节点，则按组织规则第二个节点会成为头节点，会打乱堆，导致结果出错
	swap(heap[0], heap[lastChild]);
	heap.erase(--heap.end());
	if (!heap.empty())
	{
		Heapify();
	}
	
	return ret;
}

void heapSort(vector<int>& toSort)
{
	if (toSort.size() < 2)
	{
		return;
	}
	BigRootHeap bigRootHeap;
	auto heapInsert = [&bigRootHeap](int& val) {
		bigRootHeap.HeapInsert(val); 
	};
	for_each(toSort.begin(), toSort.end(), heapInsert);

	int size = toSort.size()-1;
	while (size >= 0)
	{
		toSort[size--] = bigRootHeap.popTop();
	}
}