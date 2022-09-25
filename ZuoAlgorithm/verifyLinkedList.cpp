#include "linkedList.h"
#include <iostream>
using namespace std;

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

void verifyLinkedList()
{
	testrevetLinkedList();
}
