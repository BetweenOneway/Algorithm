#include <iostream>
#include <algorithm>
#include "sort.h"
using namespace std;

#include <time.h>

#include "linkedList.h"
#include "examic_questions.h"

void printVector(vector<int>& dataSource)
{
	auto f = [](int it) {cout << it << " "; };
	for_each(dataSource.begin(), dataSource.end(), f);
	cout << endl;
}

void generateVerifyData(vector<int>& dataSource, int minNum, int maxNum, unsigned int num)
{
	int range = maxNum - minNum + 1;
	srand(time(0));
	for (unsigned int i = 0; i < num; i++)
	{
		int generatedValue = rand() % range + minNum;
		dataSource.push_back(generatedValue);
	}
}
void testBubbleSort()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "before sort" << endl;
	printVector(data);
	bubbleSort(data);
	cout << "after sort" << endl;
	printVector(data);
}

void testSelectSort()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "before sort" << endl;
	printVector(data);
	selectSort(data);
	cout << "after sort" << endl;
	printVector(data);
}

void testMergeSort()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "before sort" << endl;
	printVector(data);
	mergeSort(data);
	cout << "after sort" << endl;
	printVector(data);
}

void testrevetLinkedList()
{
	Node* head = new Node();
	head->value = 0;
	head->prev = nullptr;
	head->next = nullptr;
	Node* prev = head;
	for (int i = 1; i < 10; i++)
	{
		Node* temp = new Node;
		temp->value = i;
		temp->next = nullptr;
		prev->next = temp;
		prev = temp;
	}
	cout << "before revert:";
	printLinkedList(head);
	head = revertLinkedList(head);
	cout << "after revert:";
	printLinkedList(head);
	head = revertLinkedListWithStack(head);
	cout << "after restore:";
	printLinkedList(head);
}

void verifyExamicQuestions()
{
	vector<int> verifyData1{ 1, 2, 2, 3, 3, 5, 5, 17, 17 };
	int ret = getOccurenceOddNumber(verifyData1);
	if (ret == 1)
	{
		cout << "Found correct number:"<<ret << endl;
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
int main()
{
	//testMergeSort();
	//testrevetLinkedList();
	verifyExamicQuestions();
	system("pause");
	return 0;
}