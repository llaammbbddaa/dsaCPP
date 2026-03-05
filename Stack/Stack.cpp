#include <iostream>
#include "Stack.h"
using namespace std;

// adds a node to the front
void Stack::push(int data) {
	Node *a;
	a = new Node;
	a->next = head;
	a->data = data;
	head = a;
}

// removes frontmost node
void Stack::pop() {
	if (head != nullptr) { // cant pop nothing
		Node *a;
		a = head;
		head = a->next;
		delete a;
	}
}

int Stack::peek() {
	if (head != nullptr) {
		return (head->data);
	}
	return -1; // peeking at nothing
}
