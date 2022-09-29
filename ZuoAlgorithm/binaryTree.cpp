
#include <vector>
#include <queue>
using namespace std;
#include "binaryTree.h"

Node::Node(int val,int id)
{
	value = val;
	index = id;
}
Node::~Node()
{
	leftChild.reset();
	rightChild.reset();
	value = numeric_limits<int>::min();
}
int Node::getValue()
{
	return value;
}
void Node::setLeftChild(shared_ptr<Node>&& lc)
{
	leftChild = lc;
}
shared_ptr<Node> Node::getLeftChild()
{
	return leftChild;
}
void Node::setRightChild(shared_ptr<Node>&& rc)
{
	rightChild = rc;
}
shared_ptr<Node> Node::getRightChild()
{
	return rightChild;
}
int Node::getIndex()
{
	return index;
}

shared_ptr<Node> vector2BinaryTree(vector<int>& data)
{
	if (data.empty())
	{
		return make_shared<Node>();
	}
	queue<shared_ptr<Node>> nodeQ;
	shared_ptr<Node> root(new Node(data[0],0));
	nodeQ.push(root);
	while (!nodeQ.empty())
	{
		shared_ptr<Node> node = nodeQ.front();
		nodeQ.pop();
		int curIndex = node->getIndex();
		int leftChildIndex = curIndex * 2 + 1;
		int rightChildIndex = leftChildIndex + 1;
		if (leftChildIndex < data.size())
		{
			shared_ptr<Node> leftChild(new Node(data[leftChildIndex],leftChildIndex));
			nodeQ.push(leftChild);
			node->setLeftChild(move(leftChild));
		}
		if (rightChildIndex < data.size())
		{
			shared_ptr<Node> rightChild = make_shared<Node>(data[rightChildIndex], rightChildIndex);
			nodeQ.push(rightChild);
			node->setRightChild(std::move(rightChild));
		}
	}
	return root;
}

void preOrderRecur(shared_ptr<Node> node,vector<int>& storage)
{
	if (!node)
	{
		return;
	}
	storage.push_back(node->getValue());
	preOrderRecur(node->getLeftChild(), storage);
	preOrderRecur(node->getRightChild(), storage);
}
//二叉树的先序遍历
vector<int> preOrderRecur(shared_ptr<Node>& root)
{
	vector<int> storage;
	if (root)
	{
		preOrderRecur(root, storage);
	}
	return storage;
}

//二叉树的中序遍历--递归
void inOrderRecur(shared_ptr<Node> node, vector<int>& storage)
{
	if (!node)
	{
		return;
	}
	
	inOrderRecur(node->getLeftChild(), storage);
	storage.push_back(node->getValue());
	inOrderRecur(node->getRightChild(), storage);
}
vector<int> inOrderRecur(shared_ptr<Node>& root)
{
	vector<int> storage;
	if (root)
	{
		inOrderRecur(root, storage);
	}
	return storage;
}
//二叉树的后续遍历--递归
void postOrderRecur(shared_ptr<Node> node, vector<int>& storage)
{
	if (!node)
	{
		return;
	}
	
	postOrderRecur(node->getLeftChild(), storage);
	postOrderRecur(node->getRightChild(), storage);
	storage.push_back(node->getValue());
}
vector<int> postOrderRecur(shared_ptr<Node>& root)
{
	vector<int> storage;
	if (root)
	{
		postOrderRecur(root, storage);
	}
	return storage;
}