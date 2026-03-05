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
