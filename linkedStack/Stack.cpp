#include <iostream>
#include "Stack.h"
using namespace std;

void Stack::pop() {
	if (head != nullptr) {
		Node *a;
		a = head;
		head = a->next;
		delete a;
	}
}

int Stack::peek() {
	if (head != nullptr) {
		return head->data;
	}
}

void Stack::push(int data) {
	Node *a;
	a = new Node;
	a->data = data;
	if (head != nullptr) { a->next = head; }
	head = a;
}
