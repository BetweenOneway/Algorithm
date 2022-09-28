#pragma once
#include <memory>
class Node
{
private:
	int value;
	int index;
	shared_ptr<Node> leftChild;
	shared_ptr<Node> rightChild;
public:
	Node() = default;
	Node(int val, int id);
	~Node();
	int getValue();
	int getIndex();
	void setLeftChild(shared_ptr<Node>&& lc);
	shared_ptr<Node>& getLeftChild();
	void setRightChild(shared_ptr<Node>&& rc);
	shared_ptr<Node>& getRightChild();
};
shared_ptr<Node> vector2BinaryTree(vector<int>& data);
vector<int> getPreOrderRecur(shared_ptr<Node>& root);