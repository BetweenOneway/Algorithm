#include "common.h"
#include "str.h"

void verifyKMP()
{
	string strSrc = "sadbutsad";
	string subStr = "sad";
	int pos = kmp(strSrc, subStr);
	if (pos == 0)
	{
		cout << "correct algorithm" << endl;
	}
	else
	{
		cout << "wrong algorithm" << endl;
	}
	strSrc = "leetcode";
	subStr = "leeto";
	pos = kmp(strSrc, subStr);
	if (-1 == pos)
	{
		cout << "correct answer" << endl;
	}
	else
	{
		cout << "wrong algorithm" << endl;
	}
}

void verifyManacher()
{
	//case 1
	string src = "abc1234321ab";
	int length = manacher(src);
	if (7 == length)
	{
		cout << "correct answer:" << length << endl;
	}
	else
	{
		cout << "wrong answer:" << length << endl;
	}
	//case 2
	src = "abc1111cba";
	length = manacher(src);
	if (10 == length)
	{
		cout << "correct answer:" << length << endl;
	}
	else
	{
		cout << "wrong answer:" << length << endl;
	}
}