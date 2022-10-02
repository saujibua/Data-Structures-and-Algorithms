#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;
class Node
{
	public:
	int dta;
	Node* npx; 
};
Node* XOR (Node *a, Node *b)
{
	return reinterpret_cast<Node *>(
	reinterpret_cast<uintptr_t>(a) ^
	reinterpret_cast<uintptr_t>(b));
}
void insert(Node **head_ref, int dta)
{
	// Allocate memory for new node
	Node *new_node = new Node();
	new_node->dta = dta;
	new_node->npx = *head_ref;
	if (*head_ref != NULL)
	{
		(*head_ref)->npx = XOR(new_node, (*head_ref)->npx);
	}

	// Change head
	*head_ref = new_node;
}
void printList (Node *head)
{
	Node *curr = head;
	Node *prev = NULL;
	Node *next;

	cout << "Following are the nodes of Linked List: \n";

	while (curr != NULL)
	{
		cout<<curr->dta<<" ";
		next = XOR (prev, curr->npx);
		prev = curr;
		curr = next;
	}
}
int main ()
{
	Node *head = NULL;
	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	insert(&head, 40);
	printList (head);

	return (0);
}
