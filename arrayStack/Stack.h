#ifndef STACK_H
#define STACK_H

class Stack {

public:
	void push(int data);
	void pop();
	int peek();

private:
	int topIndex = 50;
	int stackArray[50]; // array of size 50

};

#endif
