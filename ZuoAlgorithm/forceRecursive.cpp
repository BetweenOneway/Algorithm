/*
汉诺塔问题
*/
#include "common.h"

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

/*八皇后问题*/