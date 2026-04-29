#ifndef STACK_H
#define STACK_H

struct Node {
	int data;
	Node *next;
};

class Stack {

public:
	int peek();
	void pop();
	void push(int data);

private:
	Node *head = nullptr;
};

#endif
