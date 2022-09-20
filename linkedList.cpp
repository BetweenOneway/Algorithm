#include <stack>
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* prev;
	Node* next;
};

using Node = struct Node;

Node* revertLinkedListWithStack(Node* head)
{
	std::stack<Node*> nodeStack;
	while (head)
	{
		nodeStack.push(head);
		head = head->next;
	}
	Node* newHead = nullptr;
	Node* cur = nullptr;
	Node* prev = nullptr;
	if (!nodeStack.empty())
	{
		newHead = nodeStack.top();
		prev = newHead;
		nodeStack.pop();
	}
	while (!nodeStack.empty())
	{
		cur = nodeStack.top();
		prev->next = cur;
		prev = cur;
		nodeStack.pop();
	}
	prev->next = nullptr;
	return newHead;
}

Node* revertLinkedList(Node* head)
{
	Node* prev = nullptr;
	Node* next = head->next;
	while (next)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		if (next)
		{
			head = next;
		}
	}
	return head;
}

void printLinkedList(Node* head)
{
	Node* pos = head;
	while (pos)
	{
		cout << pos->value << ' ';
		pos = pos->next;
	}
	cout << endl;
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

void main()
{
	testrevetLinkedList();
	return;
}