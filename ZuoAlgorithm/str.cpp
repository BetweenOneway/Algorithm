#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> generateNext(string str)
{
	if (1 == str.length())
	{
		return vector<int>{-1};
	}
	vector<int> next(str.length(),0);
	next[0] = -1;
	next[1] = 0;
	int pos = 2;
	int prePos = next[pos - 1];

	while (pos < str.length())
	{
		/*
		要计算pos位置的前缀，实际后缀的最远位置只能到pos-1的位置
		这里要比较的是pos-1位置的和prePos位置的值
		*/
		if (str[pos-1] == str[prePos])
		{
			next[pos++] = ++prePos;
		}
		else if (prePos > 0)
		{
			prePos = next[prePos];
		}
		else
		{
			next[pos++] = 0;
		}
	}
	return next;
}

int kmp(string src,string subStr)
{
	int posSrc = 0;
	int posSubStr = 0;
	if (0 == src.length() || 0 == subStr.length() || src.length() < subStr.length())
	{
		return -1;
	}
	/*
	next[i]的含义是，[0,next[i-1]) == [i-1-next[i-1]+1,i-1]
	同时前缀和后缀不能完全等于[0,i-1]
	*/
	vector<int> next = generateNext(subStr);
	while (posSrc < src.length() && posSubStr < subStr.length())
	{
		if (src[posSrc] == subStr[posSubStr])
		{
			posSrc++;
			posSubStr++;
		}
		else if (0 == posSubStr)
		{
			posSrc++;
		}
		else
		{
			posSubStr = next[posSubStr];
		}
	}
	//这里要判断posSubStr == subStr.length()
	return posSubStr == subStr.length() ? posSrc - posSubStr : -1;
}

string manacherStr(string src)
{
	string result("#");
	auto process = [&result](const char c) {result.append(&c); result.append("#"); };
	for_each(src.begin(), src.end(),process);
	return result;
}
/*
Manacher算法
求解最长回文子串
*/
int manacher(string src)
{
	string srcStr = manacherStr(src);
	int center = -1;
	int radius = -1;
	int result = numeric_limits<int>::min();
	vector<int> vRadius;

	for (int i = 0; i < srcStr.length(); i++)
	{
		//以center为中心的回文半径，实际不包含center+radius这个点
		//以0号点为例，回文半径为1，回文子串并不包含1号点
		vRadius.push_back(i >= (center+radius) ? 1 : min(center+radius - i, vRadius[2*center-i]));
		//从i已定的回文半径往外扩，确保不越界
		while ( i - vRadius[i] > -1 && i + vRadius[i] < srcStr.length())
		{
			if (srcStr[i - vRadius[i]] == srcStr[i + vRadius[i]])
			{
				vRadius[i]++;
			}
			else
			{
				break;
			}
		}
		if (vRadius[i] > radius)
		{
			center = i;
			radius = vRadius[i];
		}
		result = max(vRadius[i], result);
	}
	//这一步是求解原字符串长度
	return result - 1;
}
