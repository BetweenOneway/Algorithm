#include "binarySearch.h"

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
		/*
		为什么取mid+1/mid-1
		*/
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

/*
局部最小值是指在一个数组中，假如一个元素比它的左右相邻元素（如果存在）都小，那么这个元素就是局部最小值。
1）数组第一个元素比第二个元素小，即为局部最小值。
2）数组最后一个元素比它前一个元素小，即为局部最小值。
3）若不满足，那么局部最小值必可在数组首尾两元素之间的某个位置取得
为什么能用二分？
因为原始题意里，左右两边可视为正无穷，所以必定存在一个转折点
而取的中位数，不管是递增还是递减，都必定在一侧有个转折点
*/
int localMin(vector<int>& data)
{
	if (data.size() == 0)
	{
		return -1;
	}
	int length = data.size();
	if (1 == length)
	{
		return 1;
	}
	if (data[0] < data[1])
	{
		return 0;
	}
	if (data[length - 1] < data[length - 2])
	{
		return length - 1;
	}
	int left = 1;
	int right = length - 2;
	/*
	这里为什么不取等于
	因为如果left == right，那已经没有意义再寻找了，此时的mid left right都是一样的值
	已经不可能找到符合题意的值了
	*/
	while (left < right)
	{
		int mid = left + ((right - left)>>2);
		if (data[mid - 1] > data[mid] && data[mid] < data[mid + 1])
		{
			return mid;
		}
		/*
		以第一次为例，data[0]>=data[1]，所以是单调递减的，
		如果data[mid - 1] < data[mid]，是单调递增的，
		从单调递减到单调递增，必有一次转折，那就是局部最小值
		*/
		/*
		为什么取mid+1/mid-1
		因为mid已经是不满足的了，那转折点必在mid+1~right或者left~mid-1之间
		*/
		if (data[mid - 1] < data[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}
/*
Leetcode 162
峰值元素是指其值严格大于左右相邻值的元素。
给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞ 。
你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
对于所有有效的 i 都有 nums[i] != nums[i + 1]
*/
int getPeakElemement(vector<int>& data)
{
	if (1 == data.size() || data[0] > data[1])
	{
		return 0;
	}
	int length = data.size();
	if (data[length - 1] > data[length - 2])
	{
		return length - 1;
	}
	//因为0和length-1位置已经不可能了，所以不在计算范围内
	int left = 1;
	int right = length - 2;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (data[mid - 1] < data[mid] && data[mid] > data[mid + 1])
		{
			return mid;
		}
		if (data[mid - 1] > data[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}