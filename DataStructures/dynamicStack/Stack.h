#ifndef STACK_H
#define STACK_H

class Stack {

public:
	void increaseSize();
	void pop();
	int peek();
	void push(int data);
	Stack();

private:
	int *dynamicStack;
	int topIndex = -1;
	int currSize = 2; // default size, and then each time itll double
};

#endif
