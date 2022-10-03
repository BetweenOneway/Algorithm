/*
汉诺塔问题
*/
#include "forceRecursive.h"

void hanota(vector<int>& from, vector<int>& help, vector<int>& to, int i)
{
	if (i == 1)
	{
		to.push_back(from.back());
		from.pop_back();
		return;
	}
	//把i-1个从from经过to移动到help上，空出from的最后一个
	hanota(from, to, help, i - 1);
	//把i个挪动到to上去
	hanota(from, help, to, 1);
	//将剩余的从help上经过start，挪动到to上
	hanota(help, from, to, i - 1);
}
/*
LeetCode 面试题 08.06. 汉诺塔问题
*/
void hanota(vector<int>& from, vector<int>& help, vector<int>& to) {
	hanota(from, help, to, from.size());
}

void getSubStr(string src, int index, string temp,vector<string>& result)
{
	if (index == src.length())
	{
		result.push_back(temp);
		
		return;
	}
	getSubStr(src, index + 1, temp, result);
	temp.push_back(src[index]);
	getSubStr(src, index + 1, temp, result);
}
/*
打印一个字符串的全部子序列， 包括空字符串
*/
vector<string> getAllSubStr(string src)
{
	vector<string> result;
	string temp;
	getSubStr(src, 0, temp, result);
	return result;
}



/*八皇后问题*/