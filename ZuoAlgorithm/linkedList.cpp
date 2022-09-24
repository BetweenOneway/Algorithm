#include <stack>
#include <iostream>
using namespace std;

#include "linkedList.h"

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