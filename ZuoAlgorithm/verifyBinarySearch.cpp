#include "binarySearch.h"
void verifyGetPeakElemement()
{
	vector<int> src{3,4,3,2,1};
	cout << "input raw data is:";
	printVector(src);
	int index = getPeakElemement(src);
	cout << "peak element index is:"<<index << endl;
}