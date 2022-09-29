#include "common.h"
#include "binaryTree.h"

void verifyPreOrder()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "origin data" << endl;
	printVector(data);
	shared_ptr<Node> head = vector2BinaryTree(data);
	vector<int> preOrderOutput(preOrderRecur(head));
	cout << "pre-order output" << endl;
	printVector(preOrderOutput);
}

void verifyInOrder()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "In order origin data" << endl;
	printVector(data);
	shared_ptr<Node> head = vector2BinaryTree(data);
	vector<int> inOrderOutput(inOrderRecur(head));
	cout << "in-order output" << endl;
	printVector(inOrderOutput);
}

void verifyPostOrder()
{
	vector<int> data;
	generateVerifyData(data, 0, 10, 10);
	cout << "Post order origin data" << endl;
	printVector(data);
	shared_ptr<Node> head = vector2BinaryTree(data);
	vector<int> postOrderOutput(postOrderRecur(head));
	cout << "post-order output" << endl;
	printVector(postOrderOutput);
}

