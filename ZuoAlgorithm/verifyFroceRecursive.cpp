#include "forceRecursive.h"

void verifyGetAllSubStr()
{
	string src("abc");
	cout << "Input raw data:" << src << endl;
	vector<string> result = getAllSubStr(src);
	printVector(result);
}