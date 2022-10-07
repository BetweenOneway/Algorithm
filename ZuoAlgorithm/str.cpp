#include <string>
#include <vector>
using namespace std;

vector<int> generateNext(string str)
{
	if (1 == str.length())
	{
		return vector<int>{-1};
	}
	vector<int> next;
	next[0] = -1;
	next[1] = 0;
	int pos = 2;
	int prePos = next[pos - 1];

	while (pos < str.length())
	{
		if (str[pos] == str[prePos])
		{
			next[pos++] = ++prePos;
		}
		else if (prePos > 0)
		{
			prePos = next[prePos];
		}
		else
		{
			next[pos] = 0;
		}
	}
	return next;
}

int kmp(string src,string substr)
{
	int posSrc = 0;
	int posSubStr = 0;
	if (0 == src.length() || 0 == subStr.length() || src.length() < subStr.length())
	{
		return -1;
	}
	vector<int> next = generateNext(subStr);
	while (posSrc < src.length && posSubStr < subStr.length())
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
	return posSubStr == subStr.length() ? posSrc - posSubStr : -1;
}
