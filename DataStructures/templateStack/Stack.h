#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {

public:
	void pop() { if (topIndex != -1) { topIndex--; } }
	T peek() { if (topIndex != -1) { return dynamicStack[topIndex]; } }
	Stack() { dynamicStack = new T[currSize]; }

	void push(T data) {
		topIndex++;
		if (topIndex >= currSize) { increaseSize(); }
		dynamicStack[topIndex] = data;
	}
	void increaseSize() {
		currSize *= 2;
		T *tempList;
		tempList = new T[currSize];
		for (int i = 0; i < (currSize / 2); i++) {
			tempList[i] = dynamicStack[i];
		}
		delete[] dynamicStack;
		dynamicStack = new T[currSize];
		dynamicStack = tempList;
	}

private:
	T *dynamicStack;
	int topIndex = -1;
	int currSize = 2; // default size, and then each time itll double
};

#endif
