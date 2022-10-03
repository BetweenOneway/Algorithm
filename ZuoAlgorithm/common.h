#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void swap(int& i, int& j);
template<typename dataType> void printVector(vector<dataType>& dataSource)
{
	auto f = [](dataType it) {cout << it << " "; };
	for_each(dataSource.begin(), dataSource.end(), f);
	cout << endl;
}
void generateVerifyData(vector<int>& dataSource, int minNum, int maxNum, unsigned int num);