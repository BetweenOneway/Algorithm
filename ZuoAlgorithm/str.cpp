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
		Ҫ����posλ�õ�ǰ׺��ʵ�ʺ�׺����Զλ��ֻ�ܵ�pos-1��λ��
		����Ҫ�Ƚϵ���pos-1λ�õĺ�prePosλ�õ�ֵ
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
	next[i]�ĺ����ǣ�[0,next[i-1]) == [i-1-next[i-1]+1,i-1]
	ͬʱǰ׺�ͺ�׺������ȫ����[0,i-1]
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
	//����Ҫ�ж�posSubStr == subStr.length()
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
Manacher�㷨
���������Ӵ�
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
		//��centerΪ���ĵĻ��İ뾶��ʵ�ʲ�����center+radius�����
		//��0�ŵ�Ϊ�������İ뾶Ϊ1�������Ӵ���������1�ŵ�
		vRadius.push_back(i >= (center+radius) ? 1 : min(center+radius - i, vRadius[2*center-i]));
		//��i�Ѷ��Ļ��İ뾶��������ȷ����Խ��
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
	//��һ�������ԭ�ַ�������
	return result - 1;
}
