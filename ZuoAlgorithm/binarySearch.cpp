#include "common.h"

/*
*有序数组中，返回>=指定数的最左值下标
*/
int mostLeftNoLessNumIndex(vector<int>& src, int target)
{
	if (src.empty())
	{
		return -1;
	}
	int left = 0;
	int right = src.size() - 1;
	int answer = -1;
	while (left<=right)
	{
		int mid = left + ((right - left) >> 1);
		if (src[mid]>=target)
		{
			right = mid-1;
			answer = mid;
		}
		else
		{
			left = mid+1;
		}
	}
	return answer;
}
/*
*有序数组中<=指定数的最右值下标
*/
int mostRightNoGreaterNumIndex(vector<int>& src, int target)
{
	if (src.empty())
	{
		return -1;
	}
	int left = 0;
	int right = src.size() - 1;
	int answer = -1;
	while (left <= right)
	{
		int mid = left + ((left-right)>>1);
		if (src[mid] <= target)
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return answer;
}
