#include "examic_questions.h"
/*
*一个数出现奇数次，其余出现偶数次，找到这个数
*/
int getOccurenceOddNumber(vector<int> inputData)
{
	int result = 0;
	for (int i : inputData)
	{
		result = result ^ i;
	}
	return result;
}
/*
* 两个不同的数出现奇数次，其余均出现偶数次，找到这两个数
*/
vector<int> get2OccurenceOddNumber(vector<int> inputData)
{
	int result = 0;
	for (int i : inputData)
	{
		result = result ^ i;
	}
	int bit1 = result & (~result + 1);
	int result1 = 0;
	for (int i : inputData)
	{
		if (i & bit1)
		{
			result1 = result1 ^ i;
		}
	}
	result = result ^ result1;
	return vector<int>{result, result1};
}

int merge(vector<int>& arr, int l, int m, int r)
{
	vector<int> temp(r - l + 1,0);
	int p1 = l;
	int p2 = m + 1;
	int res = 0;//记录小和的值
	int i = 0;//temp数组的下标
	while (p1 <= m && p2 <= r)
	{
		//只要arr[p1]<arr[p2]，说明从p2到r的所有值都比arr[p1]大
		//求小和的时候都要加上p1
		res += arr[p1] < arr[p2] ? (r - p2 + 1)*arr[p1] : 0;
		temp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	//不管左边还是右边有剩下的都不需要再计算小和
	//因为同一侧merge的时候已经求过小和，无需重复计算
	while (p1 <= m)
	{
		temp[i++] = arr[p1++];
	}
	while (p2 <= r)
	{
		temp[i++] = arr[p2++];
	}
	for (i = 0; i < temp.size(); i++)
	{
		arr[l + i] = temp[i];
	}
	return res;
}
/*
arr 待排序的数组 
l 数组最左侧下标
r 数组最右侧下标
返回值：小和的值
*/
int mergeSort(vector<int>& arr, int l, int r)
{
	if (l == r)
	{
		return 0;
	}
	int mid = l + ((r - l) >> 1);
	return mergeSort(arr, l, mid) + mergeSort(arr, mid+1, r)+merge(arr,l,mid,r);
}
/*
*在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和
{1,2,3}
1左边没有比1小的数，所以小和是0
2左边比2小的数，1，所以小和是1
3左边比3小的数1，2，所以小和是1+2=3
所以整个数组的小和就是1+（1+2）=4
*/
int smallSum(vector<int>& arr) {
	if (arr.size() < 2) {
		return 0;
	}
	return mergeSort(arr, 0, arr.size() - 1);
}
/*
打印两个有序链表的公共部分
谁小谁移动；相等打印，共同移动；越界结束
*/