#include "common.h"
#include "examic_questions.h"

void verifyExamicQuestions()
{
	vector<int> verifyData1{ 1, 2, 2, 3, 3, 5, 5, 17, 17 };
	int ret = getOccurenceOddNumber(verifyData1);
	if (ret == 1)
	{
		cout << "Found correct number:" << ret << endl;
	}
	else
	{
		cout << "Found error number:" << ret << endl;
	}
	vector<int> verifyData2{ 4,4,6,6,66,77,77,16,99,99 };
	vector<int> ret2 = get2OccurenceOddNumber(verifyData2);
	cout << "Found 2 numbers:";
	printVector(ret2);
}
