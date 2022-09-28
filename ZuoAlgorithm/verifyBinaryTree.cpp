#include "common.h"
#include "binaryTree.h"

void verifyPreOrder()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "origin data" << endl;
	printVector(data);
	shared_ptr<Node> head = vector2BinaryTree(data);
	vector<int> preOrderOutput(getPreOrderRecur(head));
	cout << "pre-order output" << endl;
	printVector(preOrderOutput);
}