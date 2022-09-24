#pragma once 
struct Node {
	int value;
	Node* prev;
	Node* next;
};

using Node = struct Node;
Node* revertLinkedListWithStack(Node* head);
Node* revertLinkedList(Node* head);
void printLinkedList(Node* head);