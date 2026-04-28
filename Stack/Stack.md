# Linked Stack

## main.cpp
```
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	Stack a;
	a.push(1);
	cout << a.peek() << endl;
	a.push(2);
	a.push(3);
	a.pop();
	cout << a.peek() << endl;
}
```

## Stack.cpp
```
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
```

## Stack.h
```
#ifndef STACK_H
#define STACK_H

// implementing Node struct for use in Stack class (linked stack)
struct Node {
	int data;
	Node *next;
};

// linked stack, to the best of my ability -_-
class Stack {
	public:
		void push(int data);
		void pop();
		int peek();
	private:
		Node *head = nullptr;

};

#endif
```
