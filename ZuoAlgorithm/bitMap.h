#pragma once
#include <vector>
using namespace std;

class BitMap
{
private:
	vector<int> arr;
public:
	BitMap();
	int getBitStatus(int n);
	bool setBitStatus(int n, bool flag);
};