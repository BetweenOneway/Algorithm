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
输入"abc"
输出"a" "ab" "abc" "bc" " "....
*/
vector<string> getAllSubStr(string src)
{
	vector<string> result;
	string temp;
	getSubStr(src, 0, temp, result);
	return result;
}

void getAllPossibleStr(string src, int index, vector<string>& result)
{
	if (index == src.length())
	{
		result.push_back(src);
		return;
	}

	for (int j = index; j < src.length(); j++)
	{
		swap(src, index, j);
		getAllPossibleStr(src, index + 1, result);
		swap(src, index, j);
	}
}
/*
打印一个字符串的全部排列
给定"abc"可以有"bac" "abc" "cab"....
*/
vector<string> getAllPossibleStr(string src)
{
	vector<string> result;
	getAllPossibleStr(src, 0, result);
	return result;
}

void getAllPossibleStrNoRepeat(string src, int index, vector<string>& result)
{
	if (index == src.length())
	{
		result.push_back(src);
		return;
	}
	vector<bool> visited(26, false);
	for (int j = index; j < src.length(); j++)
	{
		if (!visited[src[j] - 'a'])
		{
			swap(src, index, j);
			getAllPossibleStrNoRepeat(src, index + 1, result);
			swap(src, index, j);
		}
	}
}
/*
打印一个字符串的全部排列， 要求不要出现重复的排列
*/
vector<string> getAllPossibleStrNoRepeat(string src)
{
	vector<string> result;
	getAllPossibleStrNoRepeat(src, 0, result);
	return result;
}

int first(vector<int>& cards, int left, int right);
int second(vector<int>& cards, int left, int right)
{
	if (left == right)
	{
		return 0;
	}
	/*
	这里为什么不加上cards[left]/cards[right]
	因为这里模拟的是在left~right这一堆牌中，是第二个拿，所以不用加
	*/
	/*
	同时这里隐藏一个策略，即先手玩家每次留给后手玩家都是较小的牌
	*/
	return max(first(cards, left + 1, right), first(cards, left, right - 1));
}
int first(vector<int>& cards, int left, int right)
{
	//只剩一张牌，先手直接拿走
	if (left == right)
	{
		return cards[left];
	}
	return max(cards[left] + second(cards, left + 1, right), cards[right] + second(cards, left, right - 1));
}
/*
给定一个整型数组arr， 代表数值不同的纸牌排成一条线。 玩家A和玩家B依次拿走每张纸
牌， 规定玩家A先拿， 玩家B后拿， 但是每个玩家每次只能拿走最左或最右的纸牌， 玩家A
和玩家B都绝顶聪明。 请返回最后获胜者的分数
*/
int playCards(vector<int>& cards)
{
	int right = cards.size() - 1;
	return max(first(cards,0,right),second(cards,0,right));
}

int getAndRemoveStackBottom(stack<int>& src)
{
	int result = src.top();
	src.pop();
	if (src.empty())
	{
		return result;
	}
	int last = getAndRemoveStackBottom(src);
	src.push(last);
	return last;
}
/*
使用递归逆序栈
*/
void reverseStack(stack<int>& src)
{
	if (src.empty())
	{
		return;
	}
	int value = getAndRemoveStackBottom(src);
	reverseStack(src);
	src.push(value);
}

int convertInt2Str(vector<int>& src, int index)
{
	if (index == src.size())
	{
		return 1;
	}
	if (0 == src[index])
	{
		return 0;
	}
	if (1 == src[index])
	{
		int res = convertInt2Str(src, index + 1);
		if (index + 1 < src.size())
		{
			res += convertInt2Str(src, index + 2);
		}
		return res;
	}
	if (2 == src[index])
	{
		int res = convertInt2Str(src, index + 1);
		if (index + 1 < src.size() && src[index + 1] >= 0 && src[index + 1] <= 6)
		{
			res += convertInt2Str(src, index + 2);
		}
		return res;
	}
	return convertInt2Str(src, index + 1);
}

/*
规定1和A对应、 2和B对应、 3和C对应...
那么一个数字字符串比如"111"， 就可以转化为"AAA"、 "KA"和"AK"。
给定一个只有数字字符组成的字符串str， 返回有多少种转化结果。
*/
int convertInt2Str(vector<int>& src)
{
	return convertInt2Str(src, 0);
}

int mostValueable(vector<int>& weights, vector<int>& values, int index, int totalWeight, int bag)
{
	/*
	假如之前选择了index-1个包裹，然后重量超了，那么价值归零
	此时没选index-1的总价值必定比选择了的大
	*/
	if (totalWeight > bag)
	{
		return 0;
	}
	if (index == weights.size())
	{
		return 0;
	}
	return max(mostValueable(weights,values,index,totalWeight,bag),values[index]+mostValueable(weights,values,index+1,totalWeight+weights[index],bag));
}
/*
给定两个长度都为N的数组weights和values， weights[i]和values[i]分别代表
i号物品的重量和价值。 给定一个正数bag， 表示一个载重bag的袋子， 你装的物
品不能超过这个重量。 返回你能装下最多的价值是多少？

试所有的包裹，选或不选
*/
int highestValue(vector<int>& weights,vector<int>& values,int bag)
{
	int value = 0;
	value = mostValueable(weights, values, 0, 0, bag);
	return value;
}
/*八皇后问题*/
bool isValid(vector<int>& records, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		if (records[i] == col || abs(records[i]-col) == abs(i-row))
		{
			return false;
		}
	}
	return true;
}
/*
records中保存的是
records[i]=j 表示第i行的皇后放在了第j列
*/
int nQueens(int n, vector<int>& records, int index)
{
	if (index == n)
	{
		return 1;
	}
	int res = 0;
	//这里表示的是放在哪一列
	for (int i = 0; i < n; i++)
	{
		if (isValid(records,index,i))
		{
			//index行的皇后放在i列
			records[index] = i;
			res += nQueens(n, records, index + 1);
		}
	}
	return res;
}

int nQueens(int n)
{
	vector<int> records(n,numeric_limits<int>::min());
	return nQueens(n,records,0);
}