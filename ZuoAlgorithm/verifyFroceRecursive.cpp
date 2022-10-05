#include "forceRecursive.h"

void verifyGetAllSubStr()
{
	string src("abc");
	cout << "Input raw data:" << src << endl;
	vector<string> result = getAllSubStr(src);
	printVector(result);
}

void verifyGetAllPossibleStr()
{
	string src("abc");
	cout << "Input raw data:" << src << endl;
	vector<string> result = getAllPossibleStr(src);
	printVector(result);
}

void verifyPlayCards()
{
	vector<int> cards{1,2,100,4};
	int result = playCards(cards);
	cout << "winner score:" << result << endl;
}