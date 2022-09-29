#include "common.h"
#include "binaryTree.h"

void verifyPreOrder()
{
	vector<int> data;

	generateVerifyData(data, 0, 10, 10);

	cout << "preorder origin data" << endl;
	printVector(data);

	shared_ptr<Node> head = vector2BinaryTree(data);

	vector<int> recurOutput(preOrderRecur(head));
	cout << "pre-order recursive output" << endl;
	printVector(recurOutput);

	vector<int> unrecurOutput(preOrderUnrecur(head));
	cout << "pre-order unrecursive output" << endl;
	printVector(recurOutput);

	if (equal(recurOutput.begin(), recurOutput.end(), unrecurOutput.begin()))
	{
		cout << "recursive == unrecursive" << endl;
	}
	else
	{
		cout << "recursive != unrecursive" << endl;
	}
}

void verifyInOrder()
{
	vector<int> data;

	generateVerifyData(data, 0, 10, 10);

	cout << "In order origin data" << endl;
	printVector(data);

	shared_ptr<Node> head = vector2BinaryTree(data);

	vector<int> recurOutput(inOrderRecur(head));

	cout << "in-order recursive output" << endl;
	printVector(recurOutput);

	vector<int> unrecurOutput(inOrderUnrecur(head));

	cout << "in-order unrecursive output" << endl;
	printVector(unrecurOutput);

	if(equal(recurOutput.begin(),recurOutput.end(),unrecurOutput.begin()))
	{
		cout << "recursive == unrecursive" << endl;
	}
	else
	{
		cout << "recursive != unrecursive" << endl;
	}
}

void verifyPostOrder()
{
	vector<int> data;

	generateVerifyData(data, 0, 10, 10);

	cout << "Post order origin data" << endl;
	printVector(data);

	shared_ptr<Node> head = vector2BinaryTree(data);

	vector<int> recurOutput(postOrderRecur(head));
	cout << "post-order recur output" << endl;
	printVector(recurOutput);

	vector<int> unrecurOutput(postOrderRecur(head));
	cout << "post-order unrecur output" << endl;
	printVector(unrecurOutput);

	if (equal(recurOutput.begin(), recurOutput.end(), unrecurOutput.begin()))
	{
		cout << "recursive == unrecursive" << endl;
	}
	else
	{
		cout << "recursive != unrecursive" << endl;
	}
}


